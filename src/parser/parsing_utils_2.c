/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasal <dasal@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:22:01 by dasal             #+#    #+#             */
/*   Updated: 2024/10/08 11:22:02 by dasal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

/* <redirect_list>		::=	<io_redirect> <redirect_list>
					|	<io_redirect> */
void	redirect_list(t_vars *vars)
{
	io_redirect(vars);
	if (is_redirect(vars))
		redirect_list(vars);
}

void	handle_parentl(t_vars *vars)
{
	if (vars->cur->type == PARENTR)
		syntax_error(vars);
	cmd(vars);
	if (accept(vars, PARENTR))
	{
		if (vars->cur->type == PARENTL)
			syntax_error(vars);
	}
	if (accept(vars, PIPE))
	{
		if (vars->cur->type == PIPE || vars->cur->type == AND || 
			vars->cur->type == OR)
			syntax_error(vars);
	}
}

int	is_parent(t_vars *vars)
{
	if (vars->cur->type == NEWLINE)
		return (0);
	if (vars->cur->type == PARENTL && vars->cur->next->type == PIPE)
		syntax_error(vars);
	if (vars->cur->next->type == NEWLINE || vars->cur->next->type == PIPE)
		return (0);
	if (vars->cur->type == PARENTL || vars->cur->type == PARENTR)
		return (1);
	return (0);
}
