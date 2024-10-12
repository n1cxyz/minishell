/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_parse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlucke <wlucke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:42:41 by wlucke            #+#    #+#             */
/*   Updated: 2024/10/02 16:15:55 by wlucke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	parse_cmds(t_pipex *data)
{
	char	*cmd_path;
	int		i;

	i = 0;
	while (i < data->cmd_count)
	{
		if (data->cmd_argv[i][0][0] != '/' && data->cmd_argv[i][0][0] != '.')
		{
			if (data->cmd_argv[i][0][0] != '\0')
			{
				cmd_path = add_path(data->cmd_argv[i][0], data->env);
				if (cmd_path)
				{
					free(data->cmd_argv[i][0]);
					data->cmd_argv[i][0] = cmd_path;
				}
			}
		}
		i++;
	}
}
