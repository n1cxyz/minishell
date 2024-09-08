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

#ifndef MINI_H
#define MINI_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>
# include "libft.h"

#  define BUFFER_SIZE 4096

enum tokentype {
	NEWLINE = '\n',
	LESS = '<',
	GREAT = '>',
	PIPE = '|',
	SQUOTE = 39,
	DQUOTE = 34,
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
	int	error_status;
	int	dquote_status;
	int	added_token;
	int	quote_counter;
	t_token	*head;
	t_token *cur;
}			t_vars;

//			TOKEN
t_token		*new_token(char *content, int type);
void		add_token(t_token **lst, t_token *new);
int			token_type(t_vars *vars, int type);
void		free_token(t_token *token);
void		free_error_exit(t_vars *vars, char *msg);
//			TESTING
void		print_token(t_token *token);
void		print_token_list(t_token *list);
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
//			PARSING
void		io_redirect(t_vars *vars);
void		redirect_list(t_vars *vars);
int			cmd_suffix(t_vars *vars);
int			simple_command(t_vars *vars);
int			pipeline(t_vars *vars);
//			UTILS
void		syntax_error(t_vars *vars);
void		check_invalid_syntax(t_vars *vars, char c);
int			is_delimiter(char c);
int			is_space(char c);
void		word_to_filename(t_token *head);
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