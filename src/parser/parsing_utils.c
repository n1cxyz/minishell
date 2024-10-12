/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasal <dasal@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:40:48 by dasal             #+#    #+#             */
/*   Updated: 2024/09/07 15:40:50 by dasal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	accept(t_vars *vars, int type)
{
	if (vars->cur->type == type)
	{
		next_token(vars);
		return (1);
	}
	return (0);
}

int	expect(t_vars *vars, int type)
{
	if (accept(vars, type))
		return (1);
	syntax_error(vars);
	return (0);
}

void	next_token(t_vars *vars)
{
	if (vars->cur != NULL)
	{
		if (vars->cur->next != NULL)
			vars->cur = vars->cur->next;
	}
}

int	is_redirect(t_vars *vars)
{
	if (vars->cur->type == LESS || vars->cur->type == GREAT || 
		vars->cur->type == DGREAT || vars->cur->type == DLESS)
		return (1);
	return (0);
}

void	parse(t_vars *vars)
{
	vars->cur = vars->head;
	next_token(vars);
	if (vars->cur->type == PIPE || vars->cur->type == AND || 
		vars->cur->type == OR)
		syntax_error(vars);
	cmd(vars);
}
