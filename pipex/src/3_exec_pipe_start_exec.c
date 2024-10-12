/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_exec_pipe_start_exec.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasal <dasal@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:38:44 by dasal             #+#    #+#             */
/*   Updated: 2024/10/10 12:38:45 by dasal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	handle_child(t_pipex *data, int i, int prev_fd, int *fd)
{
	if (i == 0)
	{
		if (data->fd_in != STDIN_FILENO && data->fd_in != -2)
			redirect_fd(data->fd_in, STDIN_FILENO);
	}
	else
		redirect_fd(prev_fd, STDIN_FILENO);
	if (i == data->cmd_count - 1)
	{
		if (data->fd_out != STDOUT_FILENO)
			redirect_fd(data->fd_out, STDOUT_FILENO);
	}
	else
		redirect_fd(fd[1], STDOUT_FILENO);
	if (prev_fd != -1)
		close(prev_fd);
	if (i < data->cmd_count - 1)
	{
		close(fd[0]);
		close(fd[1]);
	}
	exec_cmd(data, i);
}

static void	handle_parent(t_pipex *data, int i, int *fd, int *prev_fd)
{
	if (*prev_fd != -1)
		close(*prev_fd);
	if (i < data->cmd_count - 1)
	{
		close(fd[1]);
		*prev_fd = fd[0];
	}
}

void	exec_multiple_cmds(t_pipex *data, int *last_pid)
{
	int		i;
	int		fd[2];
	int		prev_fd;
	pid_t	pid;

	if (data->fd_in == -2)
		i = 1;
	else
		i = 0;
	prev_fd = -1;
	while (i < data->cmd_count)
	{
		if (i < data->cmd_count - 1)
			create_pipe(data, fd);
		pid = fork_process(data);
		if (pid == 0)
			handle_child(data, i, prev_fd, fd);
		else if (pid > 0)
		{
			*last_pid = pid;
			handle_parent(data, i, fd, &prev_fd);
		}
		i++;
	}
}
