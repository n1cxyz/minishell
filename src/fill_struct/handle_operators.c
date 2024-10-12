/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_operators.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlucke <wlucke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:02:20 by dasal             #+#    #+#             */
/*   Updated: 2024/10/02 10:49:57 by wlucke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	handle_operators(t_vars *vars, t_pipex *data)
{
	if (vars->cur->type == DLESS)
		handle_heredoc(vars, data);
	else if (vars->cur->type == LESS && !vars->infile_found)
		handle_input(vars, data);
	else if (vars->cur->type == GREAT && !vars->outfile_found)
		handle_output(vars, data);
	else if (vars->cur->type == DGREAT && !vars->outfile_found)
		handle_output_append(vars, data);
}

void	handle_heredoc(t_vars *vars, t_pipex *data)
{
	if (vars->cur->type == DLESS)
	{
		next_token(vars);
		if (vars->infile_count > 1 || vars->cmd_count == 0)
		{
			read_until_limiter_m(vars->cur->content);
			vars->infile_count--;
		}
		else
			data->here_doc = true;
		if (data->limiter)
			free(data->limiter);
		data->limiter = ft_strdup(vars->cur->content);
		data->file_in = NULL;
	}
}

void	handle_input(t_vars *vars, t_pipex *data)
{
	if (vars->cur->type == LESS)
	{
		next_token(vars);
		if (vars->infile_count > 1 || vars->cmd_count == 0)
		{
			if (access(vars->cur->content, F_OK) != 0)
			{
				data->file_in = ft_strdup(vars->cur->content);
				vars->infile_found = 1;
				no_such_file(vars);
			}
			else
			{
				if (access(vars->cur->content, R_OK) != 0)
				{
					data->file_in = ft_strdup(vars->cur->content);
					vars->infile_found = 1;
					permission_denied(vars);
				}
			}
			vars->infile_count--;
		}
		else 
			data->file_in = ft_strdup(vars->cur->content);
	}
}

void	handle_output(t_vars *vars, t_pipex *data)
{
	int	fd;

	if (vars->cur->type == GREAT)
	{
		next_token(vars);
		if (vars->outfile_count > 1 || vars->cmd_count == 0)
		{
			if (access(vars->cur->content, F_OK) != 0)
			{
				fd = open(vars->cur->content, 
						O_WRONLY | O_CREAT | O_TRUNC, 00777);
				if (fd < 0)
					ft_putstr_fd("error opening file\n", STDOUT_FILENO);
				close(fd);
			}
			if (access(vars->cur->content, R_OK) != 0)
				no_access(vars, data);
			vars->outfile_count--;
		}
		else 
			data->file_out = ft_strdup(vars->cur->content);
	}
}

void	handle_output_append(t_vars *vars, t_pipex *data)
{
	int	fd;

	if (vars->cur->type == DGREAT)
	{
		next_token(vars);
		if (vars->outfile_count > 1 || vars->cmd_count == 0)
		{
			if (access(vars->cur->content, F_OK) != 0)
			{
				fd = open(vars->cur->content, 
						O_WRONLY | O_CREAT | O_TRUNC, 00777);
				if (fd < 0)
					ft_putstr_fd("error opening file\n", STDOUT_FILENO);
				close(fd);
			}
			if (access(vars->cur->content, R_OK) != 0)
				permission_denied(vars);
			vars->outfile_count--;
		}
		else
		{
			data->append = true;
			data->file_out = ft_strdup(vars->cur->content);
		}
	}
}
