/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serializer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasal <dasal@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:04:42 by dasal             #+#    #+#             */
/*   Updated: 2024/10/10 14:04:43 by dasal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini.h"

static void	serialize_input(t_pipex *data, char **argv, int *i)
{
	if (data->here_doc)
		argv[*i] = ft_strdup("true");
	else
		argv[*i] = ft_strdup("false");
	(*i)++;
	if (data->here_doc && data->limiter != NULL)
		argv[*i] = ft_strdup(data->limiter);
	else
		argv[*i] = ft_strdup("NULL");
	(*i)++;
	if (data->file_in != NULL)
		argv[*i] = ft_strdup(data->file_in);
	else
		argv[*i] = ft_strdup("NULL");
	(*i)++;
}

static void	serialize_cmds(t_pipex *data, char **argv, int *i)
{
	int	j;

	j = 0;
	while (j < data->cmd_count)
	{
		if (data->cmd_argv[j] != NULL)
		{
			argv[*i] = join_cmd_args(data->cmd_argv[j]);
			if (argv[*i] == NULL)
			{
				perror("join_cmd_args failed");
				exit(1);
			}
			(*i)++;
		}
		j++;
	}
}

static void	serialize_output(t_pipex *data, char **argv, int *i)
{
	if (data->append)
		argv[*i] = ft_strdup("true");
	else
		argv[*i] = ft_strdup("false");
	(*i)++;
	if (data->file_out != NULL)
		argv[*i] = ft_strdup(data->file_out);
	else
		argv[*i] = ft_strdup("NULL");
	(*i)++;
}

char	**serialize_pipex_to_argv(t_pipex *data)
{
	int		args_count;
	int		i;
	char	**argv;

	args_count = 6 + data->cmd_count;
	argv = malloc(sizeof(char *) * (args_count + 1));
	if (!argv)
	{
		perror("malloc failed");
		exit(1);
	}
	i = 0;
	argv[i++] = ft_strdup(get_env_value(data->env, "PIPEX"));
	serialize_input(data, argv, &i);
	serialize_cmds(data, argv, &i);
	serialize_output(data, argv, &i);
	argv[i] = NULL;
	return (argv);
}
