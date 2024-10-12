/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_delete.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasal <dasal@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:02:40 by dasal             #+#    #+#             */
/*   Updated: 2024/10/10 14:02:41 by dasal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini.h"

// void	delete_env(t_pipex *data, const char *entry)
// {
// 	int		count;
// 	int		i;
// 	int		j;
// 	char	**new_env;

// 	count = 0;
// 	while (data->env[count] != NULL)
// 		count++;
// 	new_env = malloc(count * sizeof(char *));
// 	i = 0;
// 	j = 0;
// 	while (data->env[i] != NULL)
// 	{
// 		if (strncmp(data->env[i], entry, strlen(entry)) != 0
// 			|| data->env[i][strlen(entry)] != '=')
// 		{
// 			new_env[j] = data->env[i];
// 			j++;
// 		}
// 		else
// 			free(data->env[i]);
// 		i++;
// 	}
// 	new_env[j] = NULL;
// 	free(data->env);
// 	data->env = new_env;
// }

static int	get_env_count(char **env)
{
	int	count;

	count = 0;
	while (env[count] != NULL)
		count++;
	return (count);
}

static void	copy_env_except_entry(char **new_env, char **old_env,
									const char *entry)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (old_env[i] != NULL)
	{
		if (strncmp(old_env[i], entry, strlen(entry)) != 0
			|| old_env[i][strlen(entry)] != '=')
		{
			new_env[j] = old_env[i];
			j++;
		}
		else
			free(old_env[i]);
		i++;
	}
	new_env[j] = NULL;
}

void	delete_env(t_pipex *data, const char *entry)
{
	int		count;
	char	**new_env;

	count = get_env_count(data->env);
	new_env = malloc(count * sizeof(char *));
	copy_env_except_entry(new_env, data->env, entry);
	free(data->env);
	data->env = new_env;
}
