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
	NAME,
	Empty,
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
	int	quote_status;
	t_token	*head;
}			t_vars;

//			TOKEN
t_token		*new_token(char *content, int type);
void		add_token(t_token **lst, t_token *new);
void		free_token(t_token *token);
//			TESTING
void		print_token(t_token *token);
void		print_token_list(t_token *list);
//			MAIN
void		init_vars(t_vars *vars);
//			LEXING	
int			handle_redirector(t_vars *vars, char *input, int i, int type);
int			handle_word_name(t_vars *vars, char *input, int i, int type);
int			handle_quotes(t_vars *vars, char *s, int i, int type);
void		tokenize(t_vars *vars, char *input);
int			get_char_type(int c);
void		check_invalid_syntax(t_vars *vars, char c);
int			is_delimiter(char c);
void		word_to_filename(t_token *head);
#endif

//https://en.wikipedia.org/wiki/Recursive_descent_parser
//https://pubs.opengroup.org/onlinepubs/009695399/utilities/xcu_chap02.html

/* 
<pipeline>			::=	<simple_command> '|' <pipeline> 
					|	<simple_command> 'ε'

<simple_command>	::=	<io_list> <word> <cmd_suffix>
					|	<io_list> <woprd>
					|	<io_list>
					|	<word>	  <cmd_suffix>
					|	<word>

<cmd_suffix>		::=	<io_redirect> <cmd_suffix>
					|	<io_redirect> 
					|	<WORD> <cmd_suffix>
					|	<WORD> 

<redirect_list>		::=	<io_redirect> <redirect_list>
					|	<io_redirect>

<io_redirect>		::= '<'		<filename>
					|	'>'		<filename>
					|	'>>'	<filename>
					|	'<<'	<filename>

<word>				::=	<string_literal>
*/

/*
%token	DLESS	DGREAT	LESS	GREAT	SQUOTE	DQUOTE	PIPE	FILENAME				NAME
		'<<'	'>>'	'<'		'>'		'		"		|		'<' [<word>, <name>]	'$' <word>
																'>' [<word>, <name>]
																'>>' [<word>, <name>]
 */