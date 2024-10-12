/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_exec_expand_heredoc.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasal <dasal@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:30:58 by dasal             #+#    #+#             */
/*   Updated: 2024/10/08 10:31:00 by dasal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*expand_line_p(t_pipex *data, t_expand *exp, char *line)
{
	while (line[exp->i] != '\0')
	{
		if (line[exp->i] == '$' && !exp->sq)
		{
			if (is_single_p(exp, line))
				continue ;
			alloc_name_p(exp, data, line);
		}
		else
			exp->result[exp->len++] = line[exp->i++];
		if (exp->len >= sizeof(exp->result) - 1)
			break ;
	}
	line = alloc_result_p(exp, line);
	return (line);
}

int	is_single_p(t_expand *exp, char *line)
{
	if ((line[exp->i + 1] == '\0')
		|| (!ft_isalnum(line[exp->i + 1])
			&& line[exp->i + 1] != '_'))
	{
		exp->result[exp->len++] = line[exp->i++];
		return (1);
	}
	return (0);
}

void	alloc_name_p(t_expand *exp, t_pipex *data, char *line)
{
	char	var_name[256];
	char	*var_value;
	int		var_len;

	exp->i++;
	ft_memset(var_name, 0, sizeof(var_name));
	var_len = 0;
	while (line[exp->i] != '\0' && line[exp->i] != '\n'
		&& (ft_isalnum(line[exp->i]) || line[exp->i] == '_'))
		var_name[var_len++] = line[exp->i++];
	var_name[var_len] = '\0';
	var_value = ft_getenv_p(data, var_name);
	if (var_value)
	{
		ft_strlcpy(exp->result + exp->len, var_value,
			sizeof(exp->result) - exp->len - 1);
		exp->len += ft_strlen(var_value);
	}
}

char	*alloc_result_p(t_expand *exp, char *line)
{
	exp->result[exp->len] = '\0';
	free(line);
	line = malloc(exp->len + 1);
	if (line)
		ft_strlcpy(line, exp->result, exp->len + 1);
	return (line);
}
