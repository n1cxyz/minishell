/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_exec_open.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasal <dasal@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:38:32 by dasal             #+#    #+#             */
/*   Updated: 2024/10/10 12:38:34 by dasal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	open_output(t_pipex *data)
{
	int	output_fd;

	if (data->file_out == NULL)
		output_fd = STDOUT_FILENO;
	else
	{
		if (data->append)
			output_fd = open(data->file_out,
					O_WRONLY | O_CREAT | O_APPEND, 0644);
		else
			output_fd = open(data->file_out,
					O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
	if (output_fd < 0)
		exit_error(data, data->file_out, 1);
	data->fd_out = output_fd;
	return (output_fd);
}

int	open_input(t_pipex *data)
{
	int	input_fd;

	if (data->here_doc)
	{
		input_fd = open("/tmp/.heredoc_tmp", O_RDONLY);
		if (input_fd == -1)
		{
			perror("Error opening heredoc temporary file");
			exit_error(data, "Failed to open heredoc temporary file", 1);
		}
	}
	else if (data->file_in == NULL)
		input_fd = STDIN_FILENO;
	else
	{
		input_fd = open(data->file_in, O_RDONLY);
		if (input_fd < 0)
		{
			data->exit_code = 1;
			data->fd_in = -2;
			return (-1);
		}
	}
	data->fd_in = input_fd;
	return (input_fd);
}
