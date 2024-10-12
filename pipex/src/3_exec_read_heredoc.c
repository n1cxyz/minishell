/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_exec_read_heredoc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasal <dasal@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:38:58 by dasal             #+#    #+#             */
/*   Updated: 2024/10/10 12:39:00 by dasal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	handle_here_doc(t_pipex *data, const char *limiter);
static void	read_until_limiter(t_pipex *data, int fd, const char *limiter);

void	read_heredoc(t_pipex *data)
{
	handle_here_doc(data, data->limiter);
}

static void	handle_here_doc(t_pipex *data, const char *limiter)
{
	int		fd;
	char	*temp_file;

	temp_file = "/tmp/.heredoc_tmp";
	fd = open(temp_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		exit_error(data, "Error creating temporary file for here_doc", 1);
	read_until_limiter(data, fd, limiter);
	close(fd);
	data->file_in = temp_file;
	data->fd_in = fd;
}

static void	read_until_limiter(t_pipex *data, int fd, const char *limiter)
{
	char		*line;
	size_t		limiter_len;
	t_expand	exp;

	limiter_len = ft_strlen(limiter);
	while (1)
	{
		ft_printf("heredoc> ");
		line = get_next_line(0);
		if (!line)
			break ;
		if (ft_strncmp(line, limiter,
				limiter_len) == 0 && line[limiter_len] == '\n')
		{
			free(line);
			break ;
		}
		init_exp_p(&exp);
		line = expand_line_p(data, &exp, line);
		write(fd, line, ft_strlen(line));
		free(line);
	}
}

void	init_exp_p(t_expand *exp)
{
	exp->i = 0;
	exp->len = 0;
	exp->sq = 0;
	exp->dq = 0;
	memset(exp->result, 0, sizeof(exp->result));
}

char	*ft_getenv_p(t_pipex *data, char *name)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(name);
	while (data->env[i])
	{
		if (ft_strncmp(data->env[i], name, len) == 0
			&& data->env[i][len] == '=')
			return (data->env[i] + len + 1);
		i++;
	}
	return (NULL);
}
