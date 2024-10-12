/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlucke <wlucke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 09:32:19 by wlucke            #+#    #+#             */
/*   Updated: 2024/10/01 12:42:23 by wlucke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	init_data(t_pipex *data)
{
	data->here_doc = false;
	data->limiter = NULL;
	data->append = false;
	data->cmd_count = 0;
	data->cmd = NULL;
	data->cmd_argv = NULL;
	data->file_in = NULL;
	data->fd_in = -1;
	data->file_out = NULL;
	data->fd_out = -1;
	data->env = NULL;
	data->exit_code = 0;
}
