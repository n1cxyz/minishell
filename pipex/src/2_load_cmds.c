/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_load_cmds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasal <dasal@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:58:27 by dasal             #+#    #+#             */
/*   Updated: 2024/10/10 13:58:32 by dasal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static int	alloc_cmds(t_pipex *data)
{
	int	i;

	data->cmd = (char **)malloc((data->cmd_count + 1) * sizeof(char *));
	data->cmd_argv = (char ***)malloc((data->cmd_count + 1) * sizeof(char **));
	if (!data->cmd || !data->cmd_argv)
		return (0);
	i = 0;
	while (i <= data->cmd_count)
	{
		data->cmd[i] = NULL;
		data->cmd_argv[i] = NULL;
		i++;
	}
	return (1);
}

static void	split_cmds(t_pipex *data, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->cmd_count)
	{
		j = 0;
		data->cmd[i] = first_word(argv[i + 4]);
		seven_to_space(data->cmd[i]);
		data->cmd_argv[i] = ft_split(argv[i + 4], ' ');
		while (data->cmd_argv[i][j] != NULL)
		{
			seven_to_nul(data->cmd_argv[i][j]);
			j++;
		}
		if (!data->cmd_argv[i])
			exit_error(data, "Failed to split command", 1);
		i++;
	}
}

void	get_commands(t_pipex *data, char **argv)
{
	int		i;
	int		j;

	if (!alloc_cmds(data))
		return ;
	split_cmds(data, argv);
	i = 0;
	while (i < data->cmd_count)
	{
		j = 0;
		while (data->cmd_argv[i][j] != NULL)
		{
			seven_to_space(data->cmd_argv[i][j]);
			++j;
		}
		++i;
	}
}
