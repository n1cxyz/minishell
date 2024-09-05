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

int			is_delimiter(char c)
{
	if ((c == ' ') || (c == '\t') || (c == '<') || (c == '>') || (c == '|') 
	|| (c == '\n') || (c == '\0'))
		return (1);
	return (0);

}

void		init_vars(t_vars *vars)
{
	vars->quote_status = 0;
	vars->head = (t_token *)malloc(sizeof(t_token));
	if (!vars->head)
	{
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
	vars->head->content = NULL;
	vars->head->type = Empty;
	vars->head->next = NULL;
}

void	check_invalid_syntax(t_vars *vars, char c)
{
	if ((c >= 1 && c <= 8) || (c >= 11 && c <= 31) || (c == '!') || (c == '#'))
	{
		ft_putstr_fd("invalid syntax: '", STDERR_FILENO);
		ft_putchar_fd(c, STDERR_FILENO);
		ft_putchar_fd('\'', STDERR_FILENO);
		ft_putchar_fd('\n', STDERR_FILENO);
		free_token(vars->head);
        exit(EXIT_FAILURE);
	}
	if ((c >= 37 && c <= 38) || (c >= 40 && c <= 44) || (c >= 46 && c <= 47))
	{
		ft_putstr_fd("invalid syntax: '", STDERR_FILENO);
		ft_putchar_fd(c, STDERR_FILENO);
		ft_putchar_fd('\'', STDERR_FILENO);
		ft_putchar_fd('\n', STDERR_FILENO);
		free_token(vars->head);
        exit(EXIT_FAILURE);
	}
	if ((c >= 58 && c <= 59) || (c == '=') || (c == '@') || (c >= 91 && c <= 96))
	{
		ft_putstr_fd("invalid syntax: '", STDERR_FILENO);
		ft_putchar_fd(c, STDERR_FILENO);
		ft_putchar_fd('\'', STDERR_FILENO);
		ft_putchar_fd('\n', STDERR_FILENO);
		free_token(vars->head);
        exit(EXIT_FAILURE);
	}
	if ((c >= 125 && c <= 126) || (c == '{'))
	{
		ft_putstr_fd("invalid syntax: '", STDERR_FILENO);
		ft_putchar_fd(c, STDERR_FILENO);
		ft_putchar_fd('\'', STDERR_FILENO);
		ft_putchar_fd('\n', STDERR_FILENO);
		free_token(vars->head);
        exit(EXIT_FAILURE);
	}
}