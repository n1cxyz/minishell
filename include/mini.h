#include "stdio.h"
#include "stdio.h"

//https://en.wikipedia.org/wiki/Recursive_descent_parser
//https://pubs.opengroup.org/onlinepubs/009695399/utilities/xcu_chap02.html

/* 
<command_line>		::=	<command>

<command>			::=	<simple_command> 
					|	<piped_command>

<simple_command>	::=	<word> <arguments>

<piped_command>		::= <simple_command> "|" <piped_command>

<arguments>			::= <word> <arguments>
                	|	ε

<word>				::=	<identifier>
                	| 	<string_literal>
                	| 	<number_literal>
/*

%token	DLESS	DGREAT	LESS	GREAT	SQUOTE	DQUOTE	PIPE
		'<<'	'>>'	'<'		'>'		'		"		|
 */
