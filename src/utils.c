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

int	is_space(char c)
{
	if ((c >= 8 && c <= 13) || (c == 32))
		return (1);
	return (0);
}

void	free_error_exit(t_vars *vars, char *str)
{
	free_token(vars->head);
	perror(str);
    exit(EXIT_FAILURE);
}
