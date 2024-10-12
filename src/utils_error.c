/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlucke <wlucke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:11:03 by dasal             #+#    #+#             */
/*   Updated: 2024/10/02 10:49:33 by wlucke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	syntax_error(t_vars *vars)
{
	vars->error_status++;
	if (vars->error_status == 1)
	{
		vars->exit_code = 2;
		if (vars->parent_count < 0 || vars->parent_count != 0)
		{
			ft_putstr_fd("minishell: unclosed parenthesis\n", STDERR_FILENO);
		}
		else
		{
			ft_putstr_fd("minishell: syntax error near unexpected token `", 
				STDERR_FILENO);
			if (vars->cur->content)
				ft_putstr_fd(vars->cur->content, STDERR_FILENO);
			else
				ft_putstr_fd("newline", STDERR_FILENO);
			ft_putchar_fd(SQUOTE, STDERR_FILENO);
			ft_putchar_fd('\n', STDERR_FILENO);
		}
	}
}

void	permission_denied(t_vars *vars)
{
	vars->exit_code = 1;
}

void	no_such_file(t_vars *vars)
{
	vars->file_error = 1;
	vars->exit_code = 1;
}

void	unclosed_quote(t_vars *vars)
{
	vars->exit_code = 2;
	ft_putstr_fd("minishell: unclosed quote\n", STDERR_FILENO);
}
