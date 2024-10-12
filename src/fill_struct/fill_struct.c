/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasal <dasal@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 10:59:45 by dasal             #+#    #+#             */
/*   Updated: 2024/10/01 10:59:47 by dasal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	fill_struct(t_vars *vars, t_pipex *data)
{
	vars->cur = vars->start;
	next_token(vars);
	while (vars->cur->type != vars->end->type)
	{
		if (is_parent(vars))
			next_token(vars);
		count_operators(vars, vars->cur->type);
		if (vars->cur->type != vars->end->type)
			next_token(vars);
		if (vars->cur->type == OR)
			break ;
	}
	count_cmds(vars);
	data->cmd_count = vars->cmd_count;
	init_struct(data, vars);
	vars->cur = vars->start;
	next_token(vars);
	search_vars(vars, data);
}

void	search_vars(t_vars *vars, t_pipex *data)
{
	while (vars->cur->type != vars->end->type)
	{
		if (vars->cur->type == PARENTL || vars->cur->type == PARENTR)
			next_token(vars);
		if (is_redirect(vars))
			handle_operators(vars, data);
		else if (vars->cur->type == WORD)
			handle_words(vars, data);
		if (vars->file_error)
			break ;
		if (vars->cur->type != vars->end->type)
			next_token(vars);
	}
}

void	count_operators(t_vars *vars, int type)
{
	if (type == LESS)
		vars->infile_count++;
	else if (type == GREAT)
		vars->outfile_count++;
	else if (type == DLESS)
		vars->infile_count++;
	else if (type == DGREAT)
		vars->outfile_count++;
	else if (type == WORD)
		vars->arg_count++;
}

void	count_cmds(t_vars *vars)
{
	start_next(vars);
	while (vars->cur->type != vars->end->type)
	{
		if (vars->cur->type == PARENTL || vars->cur->type == PARENTR)
			next_token(vars);
		if ((is_redirect(vars)))
		{
			next_token(vars);
			if (vars->cur->type != NEWLINE)
				next_token(vars);
		}
		if (vars->cur->type == WORD)
		{
			vars->cmd_count++;
			while (vars->cur->type != NEWLINE)
			{
				if (vars->cur->type == PIPE || 
					vars->cur->type == vars->end->type)
					break ;
				next_token(vars);
			}
		}
		if (vars->cur->type != NEWLINE && vars->cur->type == PIPE)
			next_token(vars);
	}
}

void	handle_words(t_vars *vars, t_pipex *data)
{
	int	j;

	j = 0;
	if (vars->cur->type == WORD)
		alloc_cmd(vars, data, j);
	while (vars->cur->type != PIPE && vars->cur->type != vars->end->type)
	{
		if (is_redirect(vars))
		{
			handle_operators(vars, data);
			if (vars->cur->next->type == PIPE || 
				vars->cur->next->type == NEWLINE)
				break ;
		}
		else if (vars->cur->type == WORD)
		{
			j++;
			data->cmd_argv[vars->i][j] = ft_strdup(vars->cur->content);
		}
		next_token(vars);
	}
	j++;
	data->cmd_argv[vars->i][j] = NULL;
	vars->i++;
}
