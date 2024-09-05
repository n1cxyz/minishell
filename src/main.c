/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasal <dasal@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:04:09 by dasal             #+#    #+#             */
/*   Updated: 2024/09/05 09:04:11 by dasal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		//char *input = "< Makefile cat | wc -w >> outfile";
		t_vars vars;

		init_vars(&vars);
		tokenize(&vars, av[1]);
		word_to_filename(vars.head);
		print_token_list(vars.head);
		free_token(vars.head);
	}
	printf("SUCCESS\n");
}
