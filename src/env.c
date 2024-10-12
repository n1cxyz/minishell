/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasal <dasal@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:02:20 by dasal             #+#    #+#             */
/*   Updated: 2024/10/10 14:02:21 by dasal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini.h"

void	init_env(t_pipex *data, char **envp)
{
	int	count;
	int	i;

	count = 0;
	while (envp[count] != NULL)
		count++;
	data->env = malloc((count + 1) * sizeof(char *));
	i = 0;
	while (i < count)
	{
		data->env[i] = ft_strdup(envp[i]);
		i++;
	}
	data->env[count] = NULL;
}

char	*get_env_value(char **env, const char *key)
{
	int		i;
	size_t	key_len;

	if (!env || !key)
		return (NULL);
	key_len = strlen(key);
	i = 0;
	while (env[i])
	{
		if (strncmp(env[i], key, key_len) == 0 && env[i][key_len] == '=')
			return (env[i] + key_len + 1);
		i++;
	}
	return (NULL);
}
