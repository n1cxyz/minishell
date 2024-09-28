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

#include "mini_dasal.h"

void	init_vars(t_vars *vars)
{
	vars->exit_code = 0;
	vars->infile_count = 0;
	vars->outfile_count = 0;
	vars->error_status = 0;
	vars->cmd_count= 0; // ?
	vars->arg_count = 0;
	vars->head = (t_token *)malloc(sizeof(t_token));
	if (!vars->head)
	{
        perror("Failed to allocate memory"); // ?
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
}

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		t_vars vars;
		t_pipex data;

		init_vars(&vars);
		tokenize(&vars, av[1]);
		//word_to_filename(vars.head);
		parse(&vars);
		if (!vars.exit_code)
		{
			print_token_list(vars.head);
			expand(&vars, &data);
			fill_struct(&vars, &data);
			print_struct(&data);
			free_struct(&data, &vars);
			//printf("%d\n", vars.cmd_count);
		}
		free_token(vars.head);
	}
}
/*	!!! not working

""
''
"$abc"
$$
expansion in heredoc

	

*/
//	TODO:
//	problem with here_doc and multiple infile: "<< eof cat | wc -w > out  < src/main.c"
