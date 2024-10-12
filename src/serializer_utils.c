/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serializer_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasal <dasal@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:04:50 by dasal             #+#    #+#             */
/*   Updated: 2024/10/10 14:04:52 by dasal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini.h"

static int	calculate_total_length(char **cmd_argv)
{
	int	total_length;
	int	i;

	total_length = 0;
	i = 0;
	while (cmd_argv[i] != NULL)
	{
		total_length += ft_strlen(cmd_argv[i]);
		if (cmd_argv[i + 1] != NULL)
			total_length++;
		i++;
	}
	return (total_length);
}

static void	copy_cmd_args(char **cmd_argv, char *joined)
{
	int	i;
	int	pos;

	i = 0;
	pos = 0;
	while (cmd_argv[i] != NULL)
	{
		ft_strlcpy(&joined[pos], cmd_argv[i], ft_strlen(cmd_argv[i]) + 1);
		pos += ft_strlen(cmd_argv[i]);
		if (cmd_argv[i + 1] != NULL)
			joined[pos++] = ' ';
		i++;
	}
	joined[pos] = '\0';
}

char	*join_cmd_args(char **cmd_argv)
{
	int		total_length;
	char	*joined;

	total_length = calculate_total_length(cmd_argv);
	joined = malloc(total_length + 1);
	if (joined == NULL)
		return (NULL);
	copy_cmd_args(cmd_argv, joined);
	return (joined);
}
