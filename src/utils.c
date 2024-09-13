/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasal <dasal@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:19:23 by dasal             #+#    #+#             */
/*   Updated: 2024/09/05 09:19:24 by dasal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "mini.h"

int	is_delimiter(char c)
{
	if ((c == '<') || (c == '>') || (c == '|') || (c == '\0') 
	|| (c >= 8 && c <= 13) || (c == 32))
		return (1);
	return (0);
}

int	is_name_delimiter(char c)
{
	if ((c >= 1 && c <= 8) || (c >= 11 && c <= 31) || (c == '!') || 
	(c == '#') || (c >= 37 && c <= 38) || (c >= 40 && c <= 44) || 
	(c >= 46 && c <= 47) || (c >= 58 && c <= 59) || (c == '=') || (c == '@') || 
	(c >= 91 && c <= 96) || (c >= 125 && c <= 126) || (c == '{'))
		return (1);
	return (0);
}

int	is_space(char c)
{
	if ((c >= 8 && c <= 13) || (c == 32))
		return (1);
	return (0);
}

void	free_error_exit(t_vars *vars, char *msg)
{
	free_token(vars->head);
	ft_putstr_fd(msg, STDERR_FILENO);
    exit(EXIT_FAILURE);
}

void syntax_error(t_vars *vars)
{
	//exit code 2
	ft_putstr_fd("minishell: syntax error near unexpected token `", STDERR_FILENO);
	if (vars->cur->content)
		ft_putstr_fd(vars->cur->content, STDERR_FILENO);
	else
		ft_putstr_fd("newline", STDERR_FILENO);
	ft_putchar_fd(SQUOTE, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
}