/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasal <dasal@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 10:26:27 by dasal             #+#    #+#             */
/*   Updated: 2024/10/01 10:26:29 by dasal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	is_exit_code(t_vars *vars)
{
	char	*exitcode_str;

	if (vars->cur->content[vars->j + 1] == '?' && (vars->j == 0
			|| !ft_isalnum(vars->cur->content[vars->j - 1])))
	{
		exitcode_str = ft_itoa(vars->prev_exit_code);
		vars->len += ft_strlcpy(vars->result + vars->len, exitcode_str, 
				sizeof(vars->result) - vars->len);
		vars->j += 2;
		free (exitcode_str);
		return (1);
	}
	return (0);
}

int	is_single(t_vars *vars)
{
	if ((vars->cur->content[vars->j + 1] == '\0') 
		|| (!ft_isalnum(vars->cur->content[vars->j + 1]) 
			&& vars->cur->content[vars->j + 1] != '_'))
	{
		vars->result[vars->len++] = vars->cur->content[vars->j++];
		return (1);
	}
	return (0);
}

void	reset_vars(t_vars *vars)
{
	vars->len = 0;
	vars->j = 0;
	vars->sq = 0;
	vars->dq = 0;
}

char	*ft_getenv(t_pipex *data, char *name)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(name);
	while (data->env[i])
	{
		if (strncmp(data->env[i], name, len) == 0 && data->env[i][len] == '=')
			return (data->env[i] + len + 1);
		i++;
	}
	return (NULL);
}
