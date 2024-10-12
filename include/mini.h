/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasal <dasal@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:27:28 by dasal             #+#    #+#             */
/*   Updated: 2024/10/10 12:27:29 by dasal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_H
# define MINI_H

// Libft
# include "../libft/base/libft.h"
# include "../libft/gnl/get_next_line.h"
# include "../libft/printf/ft_printf.h"
// Pipex
# include "../pipex/include/pipex.h"
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
// # include <sys/stat.h>  // stat, lstat, fstat
# include <sys/wait.h>
# include <sys/types.h>
# include <fcntl.h>
# include <errno.h>		
# include <signal.h>
// User input in command-line interfaces
# include <readline/readline.h>
# include <readline/history.h>
// Standard IO
# include <stdio.h>

// // Directory manipulation
# include <dirent.h>
// // Terminal
// #include <termios.h>	
// #include <curses.h>
// #include <term.h>
// // IO Control
// # include <sys/ioctl.h>	//ioctl

# define BUFFER_SIZZE 4096

enum e_tokentype {
	LESS = '<',
	GREAT = '>',
	PIPE = '|',
	SQUOTE = 39,
	DQUOTE = 34,
	DLESS = 256,
	DGREAT = 257,
	GENERAL, 
	WORD = 259,
	NAME = '$',
	EMPTY,
	FILENAME,
	AND = 42,
	OR = 43,
	PARENTL = 44,
	PARENTR = 45,
	END = 46
};

typedef struct s_token
{
	char			*content;
	int				type;
	struct s_token	*next;
}					t_token;

typedef struct s_vars
{
	int		error_status;
	int		infile_count;
	int		infile_found;
	int		outfile_found;
	int		outfile_count;
	int		cmd_count;
	int		arg_count;
	int		exit_code;
	int		cur_pipe;
	int		pipeline_count;
	int		prev_exit_code;
	int		sq;
	int		dq;
	int		file_error;
	char	result[1024];
	char	and_or[64];
	int		i;
	int		j;
	int		k;
	int		x;
	int		y;
	int		parent_count;
	int		first_file;
	char	*prefix;
	char	*suffix;
	char	*tmp;
	DIR		*dir;
	size_t	len;
	t_token	*head;
	t_token	*cur;
	t_token	*start;
	t_token	*end;
}			t_vars;

extern volatile sig_atomic_t	g_signal_received;

//			TOKEN
t_token		*new_token(char *content, int type);
void		add_token(t_token **lst, t_token *new);
void		free_token(t_token *token);
void		free_error_exit(t_vars *vars, char *msg);
//			TESTING
void		print_token(t_token *token);
void		print_token_list(t_token *list);
void		print_struct(t_pipex *data);
//			MAIN
void		init_vars(t_vars *vars);
//			TOKENIZE
void		tokenize(t_vars *vars, const char *input);
int			get_char_type(int c);
//			HANDLERS
int			handle_spaces(t_vars *vars, char *s, int i, int type);
int			handle_redirectors(t_vars *vars, const char *input, int i, 
				int type);
int			handle_squotes(t_vars *vars, const char *s, int i, int type);
int			handle_dquotes(t_vars *vars, const char *s, int i, int type);
int			handle_word(t_vars *vars, const char *input, int i, int type);
int			handle_name(t_vars *vars, const char *input, int i, int type);
//			PARSING_UTILS
void		handle_parentl(t_vars *vars);
void		parse(t_vars *vars);
int			accept(t_vars *vars, int type);
int			expect(t_vars *vars, int type);
void		next_token(t_vars *vars);
int			is_redirect(t_vars *vars);
int			is_parent(t_vars *vars);
//			PARSING
void		io_redirect(t_vars *vars);
void		redirect_list(t_vars *vars);
void		cmd_suffix(t_vars *vars);
void		simple_cmd(t_vars *vars);
void		pipeline(t_vars *vars);
void		cmd(t_vars *vars);
//			WILDCARDS
void		wildcard(t_vars *vars);
void		search_wildcard(t_vars *vars, struct dirent *entry);
void		match_all(t_vars *vars, struct dirent *entry);
void		match_suffix(t_vars *vars, struct dirent *entry, char *suffix);
char		*match_files(t_vars *vars, struct dirent *entry, char *prefix, 
				char *suffix);
int			ft_str_suffix(char *str, char *suffix);
int			wildcard_in_quotes(t_vars *vars);
void		alloc_content(t_vars *vars);
char		*alloc_result_w(char *buffer, int len);
//			EXPANDING
void		expand(t_vars *vars, t_pipex *data);
void		remove_quotes(t_vars *vars);
void		space_to_7(t_vars *vars);
void		empty_string(t_vars *vars);
//			EXPAND UTILS
char		*ft_getenv(t_pipex *data, char *name);
void		reset_vars(t_vars *vars);
int			is_exit_code(t_vars *vars);
int			is_single(t_vars *vars);
//			EXPAND_SEARCH
void		expand_search(t_vars *vars, t_pipex *data);
void		handle_squote(t_vars *vars);
void		handle_dquote(t_vars *vars);
void		alloc_name(t_vars *vars, t_pipex *data);
void		alloc_result(t_vars *vars);
//			FILL STRUCT
void		fill_struct(t_vars *vars, t_pipex *data);
void		search_vars(t_vars *vars, t_pipex *data);
void		alloc_cmd(t_vars *vars, t_pipex *data, int j);
void		handle_words(t_vars *vars, t_pipex *data);
void		count_operators(t_vars *vars, int type);
void		count_cmds(t_vars *vars);
int			handle_and_or(t_vars *vars, const char *s, int i);
int			handle_parent(t_vars *vars, const char *s, int i);
//			FILL STRUCT UTILS
void		read_until_limiter_m(const char *limiter);
void		init_struct(t_pipex *data, t_vars *vars);
void		init_struct_2(t_pipex *data, t_vars *vars);
void		next(t_vars *vars);
void		get_start(t_vars *vars);
void		get_end(t_vars *vars);
void		no_access(t_vars *vars, t_pipex *data);
//			HANDLE_OPERATORS
void		handle_operators(t_vars *vars, t_pipex *data);
void		handle_heredoc(t_vars *vars, t_pipex *data);
void		handle_input(t_vars *vars, t_pipex *data);
void		handle_output(t_vars *vars, t_pipex *data);
void		handle_output_append(t_vars *vars, t_pipex *data);
//			OPEN PIPE
char		*open_pipe(t_vars *vars, char *input);
int			check_operator(char *s, int i);
int			clear_postpipe(char *s);
char		*new_input(char *input);
//			BONUS
void		eval_cmds(t_vars *vars, t_pipex *data, char *input);
int			eval_group(t_vars *vars, t_pipex *data, char *input);
void		execute_cmd(t_vars *vars, t_pipex *data, char *input);
void		skip_group(t_vars *vars);
//			BONUS_UTILS
int			is_valid(t_vars *vars);
int			contains_parent(t_vars *vars);
void		get_start_end(t_vars *vars);
int			get_count(t_vars *vars);
void		reset_struct_vars(t_vars *vars);
//			UTILS
void		syntax_error(t_vars *vars);
void		no_such_file(t_vars *vars);
void		permission_denied(t_vars *vars);
void		unclosed_quote(t_vars *vars);
//void		check_invalid_syntax(t_vars *vars, char c);
int			is_delimiter(char c);
int			is_space(char c);
int			is_name_delimiter(char c);
void		free_struct(t_pipex *data, t_vars *vars);
void		free_cmd(t_pipex *data);
void		free_argv(t_pipex *data, t_vars *vars);
void		empty_heredoc(const char *limiter);
char		*ft_strndup(const char *str, size_t n);
void		start_next(t_vars *vars);

// Signals
void		register_signals(void);
void		handle_sigint(int sig);
void		handle_sigquit(int sig);
//void		setup_signals(void);

// Builtins
int			check_builtin(t_pipex *data, t_vars *vars, const char *input);
// int		builtin_echo(const char *input);				// echo
// void	builtin_echo_n(const char *input);
int			builtin_cd(const char *input);
// int		builtin_pwd(void);								
int			builtin_export(t_pipex *data, const char *input);
int			builtin_unset(t_pipex *data, const char *input);
// int		builtin_env(t_pipex *data, const char *input);
int			builtin_exit(t_pipex *data, t_vars *vars, const char *input);

// Environment
void		init_env(t_pipex *data, char **envp);
void		add_env(t_pipex *data, const char *new_entry);
void		delete_env(t_pipex *data, const char *entry);
char		*get_env_value(char **env, const char *key);

char		*find_current_path(char **env);
char		*build_new_path(const char *new_path, const char *current_path);
void		add_path_to_env(char **env, const char *new_path);

void		add_env_with_path(t_pipex *data, const char *env_key, 
				const char *relative_path);

// todo to one more general function
// void	add_builtins_path_to_env(char **env);
// void	add_pipex_path_to_env(char **env);
void		add_path_to_env_cwd(char **env, const char *relative_path);

// Serializer
char		**serialize_pipex_to_argv(t_pipex *pipex);
char		*join_cmd_args(char **cmd_argv);

//Executor
int			executor(t_pipex *data);
// Cleanup
void		free_minishell(t_pipex *pipex);

#endif
