/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_exec_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlucke <wlucke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:43:14 by wlucke            #+#    #+#             */
/*   Updated: 2024/10/01 12:43:15 by wlucke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	read_input(t_pipex *data)
{
	if (data->here_doc)
		read_heredoc(data);
	else if (data->file_in)
		read_infile(data);
}
