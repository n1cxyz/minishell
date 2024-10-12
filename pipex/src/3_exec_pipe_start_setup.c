/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_exec_pipe_start_setup.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlucke <wlucke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:42:56 by wlucke            #+#    #+#             */
/*   Updated: 2024/10/01 12:42:56 by wlucke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	handle_input_setup(t_pipex *data, int i, int *fd)
{
	if (i == 0)
	{
		if (data->file_in != NULL)
		{
			data->fd_in = open(data->file_in, O_RDONLY);
			if (data->fd_in == -1)
				exit_error(data, "Failed to open input file", 1);
			redirect_fd(data->fd_in, STDIN_FILENO);
		}
		else if (data->here_doc)
		{
			data->fd_in = open("/tmp/.heredoc_tmp", O_RDONLY);
			if (data->fd_in == -1)
				exit_error(data, "Failed to open heredoc temporary file", 1);
			redirect_fd(data->fd_in, STDIN_FILENO);
		}
		else if (fd != NULL)
			redirect_fd(fd[0], STDIN_FILENO);
	}
	else
		redirect_fd(fd[0], STDIN_FILENO);
}

static void	handle_output_setup(t_pipex *data, int i, int *fd, int output_fd)
{
	if (i == data->cmd_count - 1)
	{
		if (data->file_out != NULL)
		{
			if (output_fd != -1)
				redirect_fd(output_fd, STDOUT_FILENO);
			else
				exit_error(data, "Failed to open output", 1);
		}
	}
	else
		redirect_fd(fd[1], STDOUT_FILENO);
}

void	setup_child(t_pipex *data, int i, int *fd, int output_fd)
{
	handle_input_setup(data, i, fd);
	handle_output_setup(data, i, fd, output_fd);
	if (fd != NULL)
	{
		close(fd[0]);
		close(fd[1]);
	}
}
