/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasal <dasal@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 09:44:59 by dasal             #+#    #+#             */
/*   Updated: 2024/10/08 09:45:01 by dasal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	eval_cmds(t_vars *vars, t_pipex *data, char *input)
{
	vars->x = 0;
	while (vars->x < vars->pipeline_count)
	{
		get_start_end(vars);
		if (is_valid(vars))
		{
			if (contains_parent(vars))
			{
				vars->exit_code = eval_group(vars, data, input);
				continue ;
			}
			else
				execute_cmd(vars, data, input);
		}
		else
		{
			if (contains_parent(vars))
				skip_group(vars);
		}
		vars->x++;
	}
}

int	eval_group(t_vars *vars, t_pipex *data, char *input)
{
	int	cmd_count;
	int	i;

	i = 0;
	cmd_count = get_count(vars);
	if (is_valid(vars))
	{
		while (i < cmd_count)
		{
			if (is_valid(vars))
			{
				if (i > 0)
					get_start_end(vars);
				execute_cmd(vars, data, input);
			}
			else
				get_start_end(vars);
			i++;
			vars->x++;
		}
		return (vars->exit_code);
	}
	else
		skip_group(vars);
	return (vars->exit_code);
}

void	execute_cmd(t_vars *vars, t_pipex *data, char *input)
{
	data->exit_code = check_builtin(data, vars, input);
	if (data->exit_code != 0)
	{
		fill_struct(vars, data);
		if (data->cmd_count != 0)
			vars->exit_code = executor(data);
		free_struct(data, vars);
		reset_struct_vars(vars);
	}
}

void	skip_group(t_vars *vars)
{
	int	i;
	int	count;

	count = get_count(vars);
	count--;
	i = 0;
	while (i < count)
	{
		get_start_end(vars);
		i++;
		vars->x++;
	}
}
