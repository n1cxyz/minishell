/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_cleanup_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlucke <wlucke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 09:33:30 by wlucke            #+#    #+#             */
/*   Updated: 2024/10/02 09:58:59 by wlucke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	free_data(t_pipex *data)
{
	if (!data)
		return ;
	if (data->cmd != NULL)
		free_array_2d(data->cmd);
	if (data->cmd_argv != NULL)
		free_array_3d(data->cmd_argv);
	free(data);
}

void	free_array_2d(char **array)
{
	int	i;

	i = 0;
	if (array == NULL)
		return ;
	while (array[i] != NULL)
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
}

void	free_array_3d(char ***array)
{
	int	i;

	i = 0;
	if (array == NULL)
		return ;
	while (array[i] != NULL)
	{
		free_array_2d(array[i]);
		i++;
	}
	free(array);
}
