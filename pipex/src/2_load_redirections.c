/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_load_redirections.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlucke <wlucke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 09:32:29 by wlucke            #+#    #+#             */
/*   Updated: 2024/10/01 15:07:26 by wlucke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

t_bool	get_here_doc(char **argv)
{
	if (ft_strncmp(argv[1], "true", 5) == 0)
		return (true);
	else
		return (false);
}

char	*get_limiter(char **argv)
{
	return (argv[2]);
}

t_bool	get_append(int argc, char **argv)
{
	if (ft_strncmp(argv[argc - 2], "true", 5) == 0)
		return (true);
	else
		return (false);
}
