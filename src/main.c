/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasal <dasal@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:33:51 by dasal             #+#    #+#             */
/*   Updated: 2024/10/08 11:33:52 by dasal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini.h"

volatile sig_atomic_t	g_signal_received = 0;

static void	minishell(t_pipex *data, t_vars *vars)
{
	char	*input;

	while (1)
	{
		g_signal_received = 1;
		input = readline("minishell: ");
		g_signal_received = 0;
		if (input)
		{
			vars->prev_exit_code = vars->exit_code;
			vars->exit_code = 0;
			add_history(input);
			init_vars(vars);
			input = open_pipe(vars, input);
			tokenize(vars, input);
			parse(vars);
			expand(vars, data);
			if (!vars->exit_code)
				eval_cmds(vars, data, input);
			free_token(vars->head);
		}
		else
			break ;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	data;
	t_vars	vars;

	(void) argc;
	(void) argv;
	init_env(&data, envp);
	register_signals();
	add_path_to_env_cwd(data.env, "/pipex");
	add_path_to_env_cwd(data.env, "/src/builtins");
	add_env_with_path(&data, "PIPEX", "/pipex/pipex");
	vars.exit_code = 0;
	minishell(&data, &vars);
	rl_clear_history();
	free_minishell(&data);
	return (0);
}
//	(cd include/)
//	outfile permissions

//	exit "         1"

//	(< Makefile cat | wc -w) || (ls include/ && ls)
//	(< Makefile cat) | wc -w) && (ls include/ && ls)
//	(< Makefile cat) | < <  wc -w
//	(< Makefile cat) && wc -w

//	((echo 1) | (echo 2) | (echo 3 | (echo 4)))
//	(/bin/echo 1) (/bin/echo 2)
//	(echo 1 && echo 2) | (grep 1 && grep 2)
//	((ls && echo hello && < Makefile )cat | wc -w)

//	handle_words

//	echo "cat lol.c | cat > lol                   .c"
//	'      '
//	ls ' '
//	ping google.com
//	| ls
//	quotes	''$HOME''
//	""
//	''
//	"$abc"

//	$$
//	<>
//	space to 7

//	exit codes

//	expansion in heredoc
//	ls |
// 2 spaces
