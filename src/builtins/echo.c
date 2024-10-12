/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasal <dasal@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:05:12 by dasal             #+#    #+#             */
/*   Updated: 2024/10/10 14:05:16 by dasal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini.h"

int	main(int argc, char **argv)
{
	t_bool	newline;
	int		i;

	newline = true;
	i = 1;
	if (argc > 1 && ft_strncmp(argv[1], "-n", 3) == 0)
	{
		newline = false;
		i = 2;
	}
	while (i < argc)
	{
		ft_printf("%s", argv[i]);
		if (i < argc - 1)
			ft_printf(" ");
		i++;
	}
	if (newline)
		ft_printf("\n");
	return (0);
}
