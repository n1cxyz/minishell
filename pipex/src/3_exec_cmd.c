/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_exec_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlucke <wlucke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 09:32:42 by wlucke            #+#    #+#             */
/*   Updated: 2024/10/02 16:18:47 by wlucke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	exec_cmd(t_pipex *data, int i)
{
	if (data->cmd_argv[i][0] == NULL)
		exit_error(data, data->cmd[i], 127);
	execve(data->cmd_argv[i][0], data->cmd_argv[i], data->env);
	write_error(data->cmd[i], errno);
	if (errno == ENOENT)
		exit(127);
	else if (errno == EACCES)
		exit(126);
	else
		exit(1);
}

void	write_error(const char *cmd, int error)
{
	write(2, cmd, strlen(cmd));
	if (error == ENOENT)
		write(2, ": command not found\n", 20);
	else if (error == EACCES)
		write(2, ": permission denied\n", 20);
}
