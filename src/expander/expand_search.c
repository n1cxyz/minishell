/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasal <dasal@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 10:27:36 by dasal             #+#    #+#             */
/*   Updated: 2024/10/01 10:27:38 by dasal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	expand_search(t_vars *vars, t_pipex *data)
{
	reset_vars(vars);
	while (vars->cur->content[vars->j] != '\0')
	{
		if (vars->cur->content[vars->j] == 34)
		{
			handle_dquote(vars);
			continue ;
		}
		if ((vars->cur->content[vars->j]) == 39 && (!vars->dq))
			handle_squote(vars);
		else if (vars->cur->content[vars->j] == '$' && !vars->sq)
		{
			if (is_exit_code(vars))
				continue ;
			if (is_single(vars))
				continue ;
			alloc_name(vars, data);
		}
		else
			vars->result[vars->len++] = vars->cur->content[vars->j++];
		if (vars->len >= sizeof(vars->result) - 1)
			break ;
	}
	alloc_result(vars);
}

void	handle_squote(t_vars *vars)
{
	vars->sq = !vars->sq;
	vars->result[vars->len++] = vars->cur->content[vars->j++];
}

void	handle_dquote(t_vars *vars)
{
	vars->dq = !vars->dq;
	vars->result[vars->len++] = vars->cur->content[vars->j++];
}

void	alloc_name(t_vars *vars, t_pipex *data)
{
	char	var_name[256];
	char	*var_value;
	int		var_len;

	vars->j++;
	memset(var_name, 0, sizeof(var_name));
	var_len = 0;
	while (vars->cur->content[vars->j] != '\0' && 
		(ft_isalnum(vars->cur->content[vars->j]) || 
			vars->cur->content[vars->j] == '_'))
		var_name[var_len++] = vars->cur->content[vars->j++];
	var_name[var_len] = '\0';
	var_value = ft_getenv(data, var_name);
	if (var_value)
	{
		ft_strlcpy(vars->result + vars->len, var_value, 
			sizeof(vars->result) - vars->len - 1);
		vars->len += ft_strlen(var_value);
	}
}

void	alloc_result(t_vars *vars)
{
	vars->result[vars->len] = '\0';
	free(vars->cur->content);
	vars->cur->content = malloc(vars->len + 1);
	if (vars->cur->content)
		ft_strlcpy(vars->cur->content, vars->result, vars->len + 1);
}
