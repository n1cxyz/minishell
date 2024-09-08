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
	//printf("return: %d\n", cmd_suffix(vars));
	//printf("return: %d\n", redirect_list(vars));
	//printf("return: %d\n", cmd_suffix(vars));
	//printf("io_redirect: %d\n", io_redirect(vars));
	redirect_list(vars);
	if ((expect(vars, NEWLINE)) && (!(vars->error_status)))
		printf("SUCCESS\n");
	//print_token_list(vars->head);
}

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		t_vars vars;

		init_vars(&vars);
		tokenize(&vars, av[1]);
		word_to_filename(vars.head);
		//print_token_list(vars.head);
		parse(&vars);
		free_token(vars.head);
	}
}

//handle name in dquote
