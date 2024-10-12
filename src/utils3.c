/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasal <dasal@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:28:57 by dasal             #+#    #+#             */
/*   Updated: 2024/10/08 10:28:58 by dasal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini.h"

char	*ft_strndup(const char *str, size_t n)
{
	char	*dup;
	size_t	len;

	len = ft_strlen(str);
	if (len > n)
		len = n;
	dup = malloc((len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, str, len + 1);
	return (dup);
}

void	start_next(t_vars *vars)
{
	vars->cur = vars->start;
	next_token(vars);
}

void	next(t_vars *vars)
{
	if (vars->end != NULL)
	{
		if (vars->end->next != NULL)
			vars->end = vars->end->next;
	}
}

void	get_start(t_vars *vars)
{
	if (vars->cur_pipe < vars->pipeline_count)
	{
		if (vars->cur_pipe == 0)
		{
			vars->start = vars->head;
		}
		else
		{
			vars->start = vars->end;
		}
	}
}

void	get_end(t_vars *vars)
{
	if (vars->cur_pipe < vars->pipeline_count)
	{
		if (vars->cur_pipe == 0)
		{
			vars->end = vars->head;
			next(vars);
			while (vars->end->type != NEWLINE)
			{
				if (vars->end->type == AND || vars->end->type == OR)
					break ;
				next(vars);
			}
		}
		else
		{
			next(vars);
			while (vars->end->type != NEWLINE)
			{
				if (vars->end->type == AND || vars->end->type == OR)
					break ;
				next(vars);
			}
		}
		vars->cur_pipe++;
	}
}
