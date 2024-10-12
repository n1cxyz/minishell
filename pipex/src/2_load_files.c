/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_load_files.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasal <dasal@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:38:19 by dasal             #+#    #+#             */
/*   Updated: 2024/10/10 12:38:21 by dasal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*get_infile(char **argv)
{
	if (ft_strncmp(argv[3], "NULL", 5) == 0)
		return (NULL);
	else
	{
		seven_to_space(argv[3]);
		return (argv[3]);
	}
}

char	*get_outfile(int argc, char **argv)
{
	if (ft_strncmp(argv[argc - 1], "NULL", 5) == 0)
		return (NULL);
	else
	{
		seven_to_space(argv[argc - 1]);
		return (argv[argc - 1]);
	}
}
