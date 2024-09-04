#ifndef MINI_H
#define MINI_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>
# include "libft.h"

enum tokentype {
	NEWLINE = '\n',
	LESS = '<',
	GREAT = '>',
	PIPE = '|',
	SQUOTE = 39,
	DQUOTE = 34,
	DLESS = 256,
	DGREAT = 257,
	SPACE,
	WORD,
	NAME,
	Empty,
};

typedef struct	s_token
{
	char			*content;
	int				type;
	struct s_token	*next;
}					t_token;

typedef struct s_vars
{
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
void		parse_input(t_vars *vars, char *input);
int			get_char_type(int c);
void		check_invalid_syntax(char c);
#endif

//https://en.wikipedia.org/wiki/Recursive_descent_parser
//https://pubs.opengroup.org/onlinepubs/009695399/utilities/xcu_chap02.html

/* 
<command_line>		::=	<simple_command> 
					|	<piped_command>

<simple_command>	::=	<word> <arguments>

<piped_command>		::= <simple_command> "|" <piped_command>

<arguments>			::= <word> <arguments>
                	|	ε

<word>				::=	<string_literal>

<io_redirect>		::= '<'		<filename>
					|	'>'		<filename>
					|	'>>'	<filename>

<name>				::= '$' <word>

<filename>			::= <word>
*/

/*

%token	DLESS	DGREAT	LESS	GREAT	SQUOTE	DQUOTE	PIPE
		'<<'	'>>'	'<'		'>'		'		"		|
 */