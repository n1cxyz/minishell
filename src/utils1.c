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

void	free_minishell(t_pipex *pipex)
{
	if (pipex->env != NULL)
		free_array_2d(pipex->env);
}

int	is_delimiter(char c)
{
	if ((c == '<') || (c == '>') || (c == '|') || (c == '\0') 
		|| (c >= 8 && c <= 13) || (c == 32))
		return (1);
	return (0);
}

int	is_name_delimiter(char c)
{
	if ((c >= 1 && c <= 8) || (c >= 11 && c <= 32) || (c == '!') || 
		(c == '#') || (c >= 37 && c <= 38) || (c >= 40 && c <= 44) || 
		(c >= 46 && c <= 47) || (c >= 58 && c <= 59) || (c == '=') || 
		(c == '@') || (c >= 91 && c <= 96) || (c >= 125 && c <= 126) || 
		(c == '{'))
		return (1);
	return (0);
}

void	free_error_exit(t_vars *vars, char *msg)
{
	free_token(vars->head);
	ft_putstr_fd(msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	free_struct(t_pipex *data, t_vars *vars)
{
	if (data->limiter)
		free(data->limiter);
	if (data->file_in)
		free(data->file_in);
	if (data->file_out)
		free(data->file_out);
	free_cmd(data);
	free_argv(data, vars);
}
