/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasal <dasal@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:03:14 by dasal             #+#    #+#             */
/*   Updated: 2024/10/10 14:03:15 by dasal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini.h"

// int	executor(t_pipex *data)
// {
//     char	**call;
//     pid_t   pid;
//     int		status;
//	
//     call = serialize_pipex_to_argv(data);
//     pid = fork();
//     if (pid < 0)
// 	{
//         perror("fork failed");
//         free_array_2d(call);
//         return (-1);
//     }
//     if (pid == 0)
// 	{
// 	    execve(get_env_value(data->env, "PIPEX"), call, data->env);
//         perror("execve failed");
//         exit(EXIT_FAILURE);
//     } 
// 	else 
// 	{
//         while (waitpid(pid, &status, WNOHANG) == 0) {
//             if (g_signal_received) {
//                 kill(pid, SIGTERM);
//                 waitpid(pid, &status, 0);
//                 break ;
//             }
//             usleep(100000);
//         }
// 		g_signal_received = 0;
//         free_array_2d(call);
//         if (WIFEXITED(status))
//             data->exit_code = WEXITSTATUS(status);
// 		else
//             data->exit_code = -1;
//     }
// 	return (data->exit_code);
// }

static int	handle_parent_process(pid_t pid, char **call, t_pipex *data)
{
	int	status;

	while (waitpid(pid, &status, WNOHANG) == 0)
	{
		if (g_signal_received)
		{
			kill(pid, SIGTERM);
			waitpid(pid, &status, 0);
			break ;
		}
		usleep(100000);
	}
	g_signal_received = 0;
	free_array_2d(call);
	if (WIFEXITED(status))
		data->exit_code = WEXITSTATUS(status);
	else
		data->exit_code = -1;
	return (data->exit_code);
}

static int	handle_child_process(t_pipex *data, char **call)
{
	execve(get_env_value(data->env, "PIPEX"), call, data->env);
	perror("execve failed");
	exit(EXIT_FAILURE);
}

int	executor(t_pipex *data)
{
	char	**call;
	pid_t	pid;

	call = serialize_pipex_to_argv(data);
	pid = fork();
	if (pid < 0)
	{
		perror("fork failed");
		free_array_2d(call);
		return (-1);
	}
	if (pid == 0)
		handle_child_process(data, call);
	else
		return (handle_parent_process(pid, call, data));
	return (data->exit_code);
}
