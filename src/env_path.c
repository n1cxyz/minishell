/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasal <dasal@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:02:57 by dasal             #+#    #+#             */
/*   Updated: 2024/10/10 14:02:59 by dasal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini.h"

char	*find_current_path(char **env)
{
	int		i;
	char	*path;

	i = 0;
	path = NULL;
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			path = env[i] + 5;
			return (path);
		}
		i++;
	}
	return (path);
}

char	*build_new_path(const char *new_path, const char *current_path)
{
	char	*new_env_entry;
	size_t	new_path_len;
	size_t	current_path_len;
	size_t	total_len;

	new_path_len = ft_strlen(new_path);
	current_path_len = 0;
	if (current_path)
		current_path_len = ft_strlen(current_path);
	total_len = new_path_len + current_path_len + 6;
	new_env_entry = malloc(total_len);
	if (!new_env_entry)
	{
		perror("Failed to allocate memory");
		return (NULL);
	}
	ft_strlcpy(new_env_entry, "PATH=", total_len);
	ft_strlcat(new_env_entry, new_path, total_len);
	if (current_path)
	{
		ft_strlcat(new_env_entry, ":", total_len);
		ft_strlcat(new_env_entry, current_path, total_len);
	}
	return (new_env_entry);
}

void	add_path_to_env(char **env, const char *new_path)
{
	int		i;
	char	*current_path;
	char	*new_env_entry;

	i = 0;
	current_path = find_current_path(env);
	new_env_entry = build_new_path(new_path, current_path);
	if (!new_env_entry)
		return ;
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			free(env[i]);
			env[i] = new_env_entry;
			return ;
		}
		i++;
	}
	env[i] = new_env_entry;
	env[i + 1] = NULL;
}

void	add_path_to_env_cwd(char **env, const char *relative_path)
{
	char	*cwd;
	char	*full_path;
	size_t	cwd_len;
	size_t	relative_path_len;

	cwd = getcwd(NULL, 0);
	if (!cwd)
	{
		perror("Failed to get current working directory");
		return ;
	}
	relative_path_len = ft_strlen(relative_path);
	cwd_len = ft_strlen(cwd);
	full_path = malloc(cwd_len + relative_path_len + 1);
	if (!full_path)
	{
		free(cwd);
		perror("Failed to allocate memory");
		return ;
	}
	ft_strlcpy(full_path, cwd, cwd_len + 1);
	ft_strlcat(full_path, relative_path, cwd_len + relative_path_len + 1);
	add_path_to_env(env, full_path);
	free(full_path);
	free(cwd);
}
