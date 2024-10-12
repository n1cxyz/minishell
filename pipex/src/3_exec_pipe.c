/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_exec_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sevo <sevo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:43:02 by wlucke            #+#    #+#             */
/*   Updated: 2024/10/03 13:10:49 by sevo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	exec_pipe(t_pipex *data)
{
	int	last_pid;

	read_input(data);
	open_input(data);
	last_pid = 0;
	open_output(data);
	exec_multiple_cmds(data, &last_pid);
	pipe_wait(data, last_pid);
}
