/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasal <dasal@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 09:44:54 by dasal             #+#    #+#             */
/*   Updated: 2024/10/08 09:44:56 by dasal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	is_valid(t_vars *vars)
{
	if ((vars->x == 0) || ((vars->and_or[vars->x] == '&' && !vars->exit_code)
			|| (vars->and_or[vars->x] == '|' && vars->exit_code) || 
			(vars->and_or[vars->x] == '|' && vars->exit_code == -1)))
		return (1);
	return (0);
}

int	contains_parent(t_vars *vars)
{
	vars->cur = vars->start;
	next_token(vars);
	if (vars->cur->type == AND || vars->cur->type == OR)
		next_token(vars);
	while (vars->cur->type != NEWLINE && vars->cur->type != AND && 
		vars->cur->type != OR)
	{
		if (vars->cur->type == PARENTL)
			return (1);
		next_token(vars);
	}
	return (0);
}

void	get_start_end(t_vars *vars)
{
	get_start(vars);
	get_end(vars);
}

int	get_count(t_vars *vars)
{
	int	count;

	count = 1;
	vars->cur = vars->start;
	next_token(vars);
	while (vars->cur->type != PARENTR)
	{
		if (vars->cur->type == AND || vars->cur->type == OR)
			count++;
		next_token(vars);
	}
	return (count);
}

void	reset_struct_vars(t_vars *vars)
{
	vars->infile_count = 0;
	vars->outfile_count = 0;
	vars->cmd_count = 0;
	vars->arg_count = 0;
	vars->i = 0;
	vars->j = 0;
	vars->len = 0;
	vars->sq = 0;
	vars->dq = 0;
}
