/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlucke <wlucke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:10:12 by wlucke            #+#    #+#             */
/*   Updated: 2024/10/02 16:47:44 by wlucke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini.h"

int	check_builtin(t_pipex *data, t_vars *vars, const char *input)
{
	vars->cur = vars->start;
	next_token(vars);
	if (vars->cur->content != NULL)
	{
		while (vars->cur->type == PARENTL)
			next_token(vars);
		if (strncmp(vars->cur->content, "cd", 2) == 0)
			return (builtin_cd(vars->cur->next->content));
		if (strncmp(vars->cur->content, "export", 6) == 0)
			return (builtin_export(data, vars->cur->next->content));
		if (strncmp(vars->cur->content, "unset", 5) == 0)
			return (builtin_unset(data, vars->cur->next->content));
		if (strncmp(vars->cur->content, "exit", 4) == 0)
			return (builtin_exit(data, vars, vars->cur->next->content));
	}
	return (3);
}

// lstat, fstat
//Not a directory
//Permission denied 1
//No such file or directory 1
int	builtin_cd(const char *input)
{
	const char	*path;

	path = input;
	if (*path == '\0' || *path == ' ')
	{
		path = getenv("HOME");
		if (!path)
		{
			perror("cd: HOME not set");
			return (1);
		}
	}
	if (chdir(path) == -1)
	{
		perror(path);
		return (1);
	}
	return (0);
}

int	builtin_unset(t_pipex *data, const char *input)
{
	const char	*str;

	str = input;
	if (str)
		delete_env(data, str);
	return (0);
}

int	builtin_export(t_pipex *data, const char *input)
{
	const char	*str;

	str = input;
	if (str)
		add_env(data, str);
	return (0);
}
