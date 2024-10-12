/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlucke <wlucke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:39:24 by dasal             #+#    #+#             */
/*   Updated: 2024/10/02 10:43:18 by wlucke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini.h"

int	is_space(char c)
{
	if ((c >= 8 && c <= 13) || (c == 32))
		return (1);
	return (0);
}
//t_token	*alloc_token();

void	init_vars(t_vars *vars)
{
	vars->parent_count = 0;
	vars->infile_count = 0;
	vars->infile_found = 0;
	vars->outfile_found = 0;
	vars->outfile_count = 0;
	vars->error_status = 0;
	vars->file_error = 0;
	vars->cmd_count = 0;
	vars->arg_count = 0;
	vars->cur_pipe = 0;
	vars->pipeline_count = 0;
	vars->i = 0;
	vars->j = 0;
	vars->k = 0;
	vars->len = 0;
	vars->sq = 0;
	vars->dq = 0;
	memset(vars->result, 0, sizeof(vars->result));
	memset(vars->and_or, 0, sizeof(vars->and_or));
	vars->and_or[vars->k] = '.';
	vars->k++;
	vars->head = new_token(NULL, EMPTY);
	vars->start = vars->head;
	reset_vars(vars);
}

// void	read_until_limiter(int fd, const char *limiter)
void	empty_heredoc(const char *limiter)
{
	char	*line;
	size_t	limiter_len;

	limiter_len = ft_strlen(limiter);
	while (1)
	{
		ft_printf("heredoc> ");
		line = get_next_line(0);
		if (!line)
			break ;
		if (ft_strncmp(line, limiter, limiter_len) == 0 && 
			line[limiter_len] == '\n')
		{
			free(line);
			break ;
		}
		free(line);
	}
}

void	free_cmd(t_pipex *data)
{
	int	i;

	i = 0;
	if (data->cmd)
	{
		while (i < data->cmd_count)
		{
			free (data->cmd[i]);
			i++;
		}
		free(data->cmd);
	}
}

void	free_argv(t_pipex *data, t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	if (data->cmd_argv)
	{
		while (i < data->cmd_count)
		{
			j = 0;
			while (j < vars->arg_count)
			{
				free(data->cmd_argv[i][j]);
				j++;
			}
			free(data->cmd_argv[i]);
			i++;
		}
		free(data->cmd_argv);
	}
}
