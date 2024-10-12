/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlucke <wlucke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 09:32:16 by wlucke            #+#    #+#             */
/*   Updated: 2024/10/02 16:30:19 by wlucke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*data;

	data = malloc(sizeof(t_pipex));
	if (!data)
		exit_error(data, "Memory allocation failed", 1);
	init_data(data);
	load_data(data, argc, argv, envp);
	parse_cmds(data);
	exec_data(data);
	cleanup_data(data);
}
