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

int	main(void)
{
	char *input = {"<Makefile cat|wc -w>>outfile\n"};
	t_vars vars;

	init_vars(&vars);
	parse_input(&vars, input);
	word_to_filename(vars.head);
	print_token_list(vars.head);
	free_token(vars.head);	
}
