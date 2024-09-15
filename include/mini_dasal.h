/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasal <dasal@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:04:28 by dasal             #+#    #+#             */
/*   Updated: 2024/09/05 09:04:30 by dasal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_DASAL_H
#define MINI_DASAL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>
# include <fcntl.h>
# include <string.h>
# include "libft.h"

#  define BUFFER_SIZE 4096

enum tokentype {
	NEWLINE = '\n',
	LESS = '<',
	GREAT = '>',
	PIPE = '|',
	SQUOTE = 39,
	DQUOTE = '-',
	DLESS = 256,
	DGREAT = 257,
	GENERAL, 
	SPACE,
	WORD,
	NAME = '?',
	EMPTY,
	FILENAME,
	END
};

typedef struct	s_token
{
	char			*content;
	int				type;
	struct s_token	*next;
}					t_token;



typedef struct s_vars
{
	int		error_status;
	int		infile_count;
	int		outfile_count;
	int		cmd_count;
	int		arg_count;
	int		exit_code;
	t_token	*head;
	t_token *cur;
}			t_vars;

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_pipex
{
	t_bool	here_doc;
	char	*limiter;	
	char	*file_in;
	int		cmd_count;
	char	**cmd;
	char	***cmd_argv;
	t_bool	append;
	char	*file_out;	
	char	**env;
	int		fd_in;
	int		fd_out;
	int		exit_code;
}	t_pipex;

//			TOKEN
t_token		*new_token(char *content, int type);
void		add_token(t_token **lst, t_token *new);
int			token_type(t_vars *vars, int type);
void		free_token(t_token *token);
void		free_error_exit(t_vars *vars, char *msg);
//			TESTING
void		print_token(t_token *token);
void		print_token_list(t_token *list);
void		print_struct(t_pipex *data);
void		init_struct(t_pipex *data, t_vars *vars);
//			MAIN
void		init_vars(t_vars *vars);
//			TOKENIZE
void		tokenize(t_vars *vars, char *input);
int			get_char_type(int c);
//			HANDLERS
int			handle_spaces(t_vars *vars, char *s, int i, int type);
int			handle_redirectors(t_vars *vars, char *input, int i, int type);
int			handle_squotes(t_vars *vars, char *s, int i, int type);
int			handle_dquotes(t_vars *vars, char *s, int i, int type);
int			handle_word(t_vars *vars, char *input, int i, int type);
int			handle_name(t_vars *vars, char *input, int i, int type);
//			PARSING_UTILS
void		parse(t_vars *vars);
int 		accept(t_vars *vars, int type);
int			expect(t_vars *vars, int type);
void		next_token(t_vars *vars);
int			is_redirect(t_vars *vars);
//			PARSING
void		io_redirect(t_vars *vars);
void		redirect_list(t_vars *vars);
void		cmd_suffix(t_vars *vars);
void		simple_cmd(t_vars *vars);
void		pipeline(t_vars *vars);
//			EXPANDING
void		expand(t_vars *vars);
void		find_names(t_vars *vars);
char		*substr_replace(t_vars *vars, char *s1, int index);
char		*substr_remove(t_vars *vars, char c);
//			EXPAND UTILS
char		*get_name(t_vars *vars, int i);
int			get_name_index(t_vars *vars, char *name);
void		remove_quotes(t_vars *vars);
int			find_q1(t_vars *vars);
int			find_q2(t_vars *vars);
//			FILL STRUCT
void		fill_struct(t_vars *vars, t_pipex *data);
void		handle_words(t_vars *vars, t_pipex *data);
void		handle_operators(t_vars *vars, t_pipex *data);
void		handle_input(t_vars *vars, t_pipex *data);
void		handle_output(t_vars *vars, t_pipex *data);
void		handle_output_append(t_vars *vars, t_pipex *data);
void		count_operators(t_vars *vars, int type);
//			UTILS
void		syntax_error(t_vars *vars);
void 		no_such_file(t_vars *vars);
void 		permission_denied(t_vars *vars);
void		unclosed_quote(t_vars *vars);
void		check_invalid_syntax(t_vars *vars, char c);
int			is_delimiter(char c);
int			is_space(char c);
int			is_name_delimiter(char c);
void		word_to_filename(t_token *head);
void		free_struct(t_pipex *data, t_vars *vars);
#endif

//https://en.wikipedia.org/wiki/Recursive_descent_parser
//https://pubs.opengroup.org/onlinepubs/009695399/utilities/xcu_chap02.html

/* 
<pipeline>			::=	<simple_cmd> '|' <pipeline> 
					|	<simple_cmd> 'ε'

<simple_cmd>		::=	<redirect_list> <word> <cmd_suffix>
					|	<redirect_list> <word>
					|	<redirect_list>
					|	<word>	  <cmd_suffix>
					|	<word>

<cmd_suffix>		::=	<io_redirect> <cmd_suffix>
					|	<io_redirect> 
					|	<word> <cmd_suffix>
					|	<word> 

<redirect_list>		::=	<io_redirect> <redirect_list>
					|	<io_redirect>

<io_redirect>		::= ['<'|'>'|'<<'|'>>'] <filename>





%token	DLESS	DGREAT	LESS	GREAT	SQUOTE	DQUOTE	PIPE
		'<<'	'>>'	'<'		'>'		'		"		|

WORD		::=	<string_literal>

NAME		::=	'$'<word> 

FILENAME	::=	'<' [<word>, <name>]
			|	'>' [<word>, <name>]
			|	'>>' [<word>, <name>]
*/

// $ = ?
// " = -
