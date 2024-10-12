/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_exec_read_infile.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sevo <sevo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:43:09 by wlucke            #+#    #+#             */
/*   Updated: 2024/10/03 13:14:31 by sevo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	handle_input_file(t_pipex *data, const char *input_file);
static void	process_input_file(t_pipex *data, int fd_in, char *temp_file);
static int	write_to_temp(t_pipex *data, int fd_tmp, char *line,
				ssize_t *bytes);

void	read_infile(t_pipex *data)
{
	handle_input_file(data, data->file_in);
}

static void	handle_input_file(t_pipex *data, const char *input_file)
{
	int		fd_in;
	char	*temp_file;

	fd_in = open(input_file, O_RDONLY);
	if (fd_in == -1)
	{
		perror(input_file);
		data->exit_code = 1;
		return ;
	}
	temp_file = "/tmp/.input_tmp";
	process_input_file(data, fd_in, temp_file);
	close(fd_in);
	data->file_in = temp_file;
	data->fd_in = fd_in;
}

static void	process_input_file(t_pipex *data, int fd_in, char *temp_file)
{
	int		fd_tmp;
	ssize_t	bytes;
	char	*line;

	bytes = 0;
	fd_tmp = open(temp_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_tmp == -1)
		exit_error(data, "Error creating temporary file for input", 1);
	line = get_next_line(fd_in);
	while (line != NULL)
	{
		if (!write_to_temp(data, fd_tmp, line, &bytes))
			break ;
		line = get_next_line(fd_in);
	}
	close(fd_tmp);
}

static int	write_to_temp(t_pipex *data, int fd_tmp, char *line, ssize_t *bytes)
{
	ssize_t	line_length;

	line_length = ft_strlen(line);
	if (*bytes + line_length > CHUNK_SIZE)
	{
		free(line);
		return (0);
	}
	if (write(fd_tmp, line, line_length) != line_length)
	{
		free(line);
		exit_error(data, "Error writing to temporary file", 1);
	}
	*bytes += line_length;
	free(line);
	return (1);
}
