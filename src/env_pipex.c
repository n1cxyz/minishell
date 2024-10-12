/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_pipex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasal <dasal@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:03:03 by dasal             #+#    #+#             */
/*   Updated: 2024/10/10 14:03:04 by dasal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini.h"

static char	*get_full_path(const char *relative_path)
{
	char	*cwd;
	char	*full_path;
	size_t	len;

	cwd = getcwd(NULL, 0);
	if (!cwd)
	{
		perror("Failed to get current working directory");
		return (NULL);
	}
	len = ft_strlen(cwd) + ft_strlen(relative_path) + 1;
	full_path = malloc(len);
	if (!full_path)
	{
		free(cwd);
		perror("Memory allocation failed");
		return (NULL);
	}
	ft_strlcpy(full_path, cwd, ft_strlen(cwd) + 1);
	ft_strlcat(full_path, relative_path, len);
	free(cwd);
	return (full_path);
}

static char	*create_env_entry(const char *env_key, const char *full_path)
{
	char	*new_entry;
	size_t	len;

	len = ft_strlen(env_key) + ft_strlen(full_path) + 2;
	new_entry = malloc(len);
	if (!new_entry)
		return (NULL);
	ft_strlcpy(new_entry, env_key, ft_strlen(env_key) + 1);
	ft_strlcat(new_entry, "=", ft_strlen(env_key) + 2);
	ft_strlcat(new_entry, full_path, len);
	return (new_entry);
}

static void	add_pipex_env(t_pipex *data, char *new_entry)
{
	int		count;
	int		i;
	char	**new_env;

	count = 0;
	while (data->env[count] != NULL)
		count++;
	new_env = malloc((count + 2) * sizeof(char *));
	i = 0;
	while (i < count)
	{
		new_env[i] = data->env[i];
		i++;
	}
	new_env[count] = new_entry;
	new_env[count + 1] = NULL;
	free(data->env);
	data->env = new_env;
}

void	add_env_with_path(t_pipex *data, const char *env_key,
							const char *relative_path)
{
	char	*full_path;
	char	*new_entry;

	full_path = get_full_path(relative_path);
	if (!full_path)
		return ;
	new_entry = create_env_entry(env_key, full_path);
	if (!new_entry)
	{
		free(full_path);
		perror("Memory allocation failed");
		return ;
	}
	add_pipex_env(data, new_entry);
	free(full_path);
}
