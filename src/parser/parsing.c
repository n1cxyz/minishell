/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasal <dasal@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:40:44 by dasal             #+#    #+#             */
/*   Updated: 2024/09/07 15:40:45 by dasal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	pipeline(t_vars *vars);

int	simple_command(t_vars *vars);
/* {
	if (redirect_list)
	{
		if (accept(vars, WORD))
			cmd_suffix(vars);
	}
	else if (redirect_list)
		accept(vars, WORD);
} */

int	cmd_suffix(t_vars *vars)
{
	if (io_redirect(vars))
	{
		if (cmd_suffix(vars))
			return (1);
	}
	if (io_redirect(vars))
		return (1);
	if (accept(vars, WORD) || accept(vars, NAME))
	{
		if (cmd_suffix(vars))
			return (1);
	}
	return (0);
}

int	redirect_list(t_vars *vars)
{
	if (!(io_redirect(vars)))
		return (0);
	while(vars->cur->type == LESS || vars->cur->type == GREAT ||
	vars->cur->type == DGREAT || vars->cur->type == DLESS)
	{
			if (!(io_redirect(vars)))
				return (0);
	}
	return (1);
}

int	io_redirect(t_vars *vars)
{
	if (vars->cur->type == LESS || vars->cur->type == GREAT ||
	vars->cur->type == DGREAT || vars->cur->type == DLESS)
	{
		next_token(vars);
		if (expect(vars, FILENAME))
			return (1);
	}
	return (0);
}
