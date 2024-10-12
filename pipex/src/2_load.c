/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_load.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlucke <wlucke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 09:32:32 by wlucke            #+#    #+#             */
/*   Updated: 2024/10/01 15:08:44 by wlucke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	load_data(t_pipex *data, int argc, char **argv, char **envp)
{
	data->here_doc = get_here_doc(argv);
	data->limiter = get_limiter(argv);
	data->append = get_append(argc, argv);
	data->file_in = get_infile(argv);
	data->cmd_count = argc - 6;
	get_commands(data, argv);
	data->file_out = get_outfile(argc, argv);
	data->env = envp;
}
