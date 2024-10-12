/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasal <dasal@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:02:31 by dasal             #+#    #+#             */
/*   Updated: 2024/10/10 14:02:33 by dasal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini.h"

static int	find_and_replace_env_var(t_pipex *data, const char *new_entry,
										const char *new_var)
{
	int	i;

	i = 0;
	while (data->env[i] != NULL)
	{
		if (strncmp(data->env[i], new_var, strlen(new_var)) == 0
			&& data->env[i][strlen(new_var)] == '=')
		{
			free(data->env[i]);
			data->env[i] = ft_strdup(new_entry);
			return (1);
		}
		i++;
	}
	return (0);
}

static void	extend_env(t_pipex *data, const char *new_entry, int env_size)
{
	char	**new_env;
	int		j;

	new_env = malloc((env_size + 2) * sizeof(char *));
	j = 0;
	while (j < env_size)
	{
		new_env[j] = data->env[j];
		j++;
	}
	new_env[env_size] = ft_strdup(new_entry);
	new_env[env_size + 1] = NULL;
	free(data->env);
	data->env = new_env;
}

void	add_env(t_pipex *data, const char *new_entry)
{
	int		i;
	char	*new_var;

	i = 0;
	new_var = ft_strndup(new_entry, ft_strchr(new_entry, '=') - new_entry);
	if (find_and_replace_env_var(data, new_entry, new_var))
	{
		free(new_var);
		return ;
	}
	while (data->env[i])
		i++;
	extend_env(data, new_entry, i);
	free(new_var);
}
