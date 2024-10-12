/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_exec_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlucke <wlucke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:43:58 by wlucke            #+#    #+#             */
/*   Updated: 2024/10/01 12:43:58 by wlucke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	redirect_fd(int old_fd, int new_fd)
{
	dup2(old_fd, new_fd);
	close(old_fd);
}

void	handle_parent(t_pipex *data, int *fd, int i)
{
	if (i > 0)
		close(data->fd_in);
	data->fd_in = fd[0];
	close(fd[1]);
}

void	create_pipe(t_pipex *data, int *fd)
{
	if (pipe(fd) == -1)
		exit_error(data, "Error creating pipe", 1);
}

pid_t	fork_process(t_pipex *data)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		exit_error(data, "Error forking", 1);
	return (pid);
}
