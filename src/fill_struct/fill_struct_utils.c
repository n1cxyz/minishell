/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasal <dasal@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:05:45 by dasal             #+#    #+#             */
/*   Updated: 2024/10/01 11:05:46 by dasal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	read_until_limiter_m(const char *limiter)
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
		if (ft_strncmp(line, limiter,
				limiter_len) == 0 && line[limiter_len] == '\n')
		{
			free(line);
			break ;
		}
		free(line);
	}
}

void	alloc_cmd(t_vars *vars, t_pipex *data, int j)
{
	data->cmd[vars->i] = ft_strdup(vars->cur->content);
	data->cmd_argv[vars->i][j] = ft_strdup(vars->cur->content);
	next_token(vars);
}

/* void	init_struct(t_pipex *data, t_vars *vars)
{
	(void)vars;
	data->here_doc = false;
	data->limiter = NULL;
	data->file_in = NULL;
	data->cmd = (char **)malloc(sizeof(char *) * data->cmd_count);
	for (int i = 0; i < data->cmd_count; i++)
		data->cmd[i] = NULL;
	data->cmd_argv = (char ***)malloc(sizeof(char **) * data->cmd_count);
	for (int i = 0; i < data->cmd_count; i++)
	{
		data->cmd_argv[i] = (char **)malloc(sizeof(char *) * (vars->arg_count + 1));
		for (int j = 0; j < vars->arg_count; j++)
			data->cmd_argv[i][j] = NULL;
		data->cmd_argv[i][vars->arg_count] = NULL;
	}
	data->append = false;
	data->file_out = NULL;
	data->exit_code = 0;
} */

void	init_struct(t_pipex *data, t_vars *vars)
{
	int	i;

	i = 0;
	(void)vars;
	init_struct_2(data, vars);
	data->cmd = (char **)malloc(sizeof(char *) * data->cmd_count);
	while (i < data->cmd_count)
	{
		data->cmd[i] = NULL;
		i++;
	}
}

void	init_struct_2(t_pipex *data, t_vars *vars)
{
	int	i;
	int	j;

	(void)vars;
	data->here_doc = false;
	data->limiter = NULL;
	data->file_in = NULL;
	data->append = false;
	data->file_out = NULL;
	data->exit_code = 0;
	i = 0;
	data->cmd_argv = (char ***)malloc(sizeof(char **) * data->cmd_count);
	while (i < data->cmd_count)
	{
		data->cmd_argv[i] = (char **)malloc(sizeof(char *) * 
				(vars->arg_count + 1));
		j = 0;
		while (j < vars->arg_count)
		{
			data->cmd_argv[i][j] = NULL;
			j++;
		}
		data->cmd_argv[i][vars->arg_count] = NULL;
		i++;
	}
}

void	no_access(t_vars *vars, t_pipex *data)
{
	vars->outfile_found = 1;
	data->file_out = ft_strdup(vars->cur->content);
	permission_denied(vars);
}
