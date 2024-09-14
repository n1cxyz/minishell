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

void	init_vars(t_vars *vars)
{
	//vars->quote_counter = 0;
	//vars->dquote_status = 0;
	//vars->added_token = 0;
	vars->error_status = 0;
	vars->head = (t_token *)malloc(sizeof(t_token));
	if (!vars->head)
	{
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
	vars->head->content = NULL;
	vars->head->type = EMPTY;
	vars->head->next = NULL;
}

void	parse(t_vars *vars)
{
	vars->cur = vars->head;
	next_token(vars);
	pipeline(vars);
	if ((expect(vars, NEWLINE)) && (!(vars->error_status)))
		printf("SUCCESS\n");
}

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		t_vars vars;

		init_vars(&vars);
		tokenize(&vars, av[1]);
		//print_token_list(vars.head);
		//word_to_filename(vars.head);
		//print_token_list(vars.head);
		parse(&vars);
		expand(&vars);
		print_token_list(vars.head);
		free_token(vars.head);
	}
}
/*	!!! not working
	?HOME?SHELL
*/

//	build expander
//	fill struct

//	remove quotes
