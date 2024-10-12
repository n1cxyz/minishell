/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_cleanup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlucke <wlucke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:44:04 by wlucke            #+#    #+#             */
/*   Updated: 2024/10/01 14:03:09 by wlucke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	cleanup_data(t_pipex *data)
{
	if (data->file_in != NULL)
	{
		close(data->fd_in);
		unlink(data->file_in);
	}
	exit(data->exit_code);
}
