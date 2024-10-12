/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlucke <wlucke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:16:42 by dasal             #+#    #+#             */
/*   Updated: 2024/09/25 10:59:59 by wlucke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	expand(t_vars *vars, t_pipex *data)
{
	vars->cur = vars->head;
	next_token(vars);
	while (vars->cur->type != NEWLINE)
	{
		if (vars->cur->type == WORD && vars->cur->content != NULL)
		{
			expand_search(vars, data);
			wildcard(vars);
		}
		next_token(vars);
	}
	vars->cur = vars->head;
	next_token(vars);
	while (vars->cur->type != NEWLINE)
	{
		if (vars->cur->type == WORD)
		{
			reset_vars(vars);
			space_to_7(vars);
			reset_vars(vars);
			remove_quotes(vars);
			empty_string(vars);
		}
		next_token(vars);
	}
}

void	space_to_7(t_vars *vars)
{
	char	*src;
	char	*dst;

	src = vars->cur->content;
	dst = vars->cur->content;
	while (*src != '\0')
	{
		if ((is_space(*src)) && (vars->dq || vars->sq))
		{
			*src = 7;
		}
		if (*src == 34 && !vars->sq)
		{
			vars->dq ^= 1;
		}
		else if (*src == 39 && !vars->dq)
		{
			vars->sq ^= 1;
		}
		*dst = *src;
		dst++;
		src++;
	}
	*dst = '\0';
}

void	remove_quotes(t_vars *vars)
{
	char	*src;
	char	*dst;

	src = vars->cur->content;
	dst = vars->cur->content;
	while (*src != '\0')
	{
		if (*src == 34 && !vars->sq)
		{
			vars->dq ^= 1;
			src++;
			continue ;
		}
		else if (*src == 39 && !vars->dq)
		{
			vars->sq ^= 1;
			src++;
			continue ;
		}
		*dst = *src;
		dst++;
		src++;
	}
	*dst = '\0';
}

void	empty_string(t_vars *vars)
{
	if (vars->cur->content[0] == '\0')
	{
		free (vars->cur->content);
		vars->cur->content = (char *)malloc(sizeof(char) * 2);
		if (!vars->cur->content)
			perror("memory allocation failed");
		vars->cur->content[0] = 7;
		vars->cur->content[1] = '\0';
	}
}
