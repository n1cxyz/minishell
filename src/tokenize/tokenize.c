/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasal <dasal@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:04:01 by dasal             #+#    #+#             */
/*   Updated: 2024/09/05 09:04:03 by dasal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	tokenize(t_vars *vars, char *s)
{
	int	i;
	int	type;
	
	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
	{
		//check_invalid_syntax(vars, s[i]);
		type = get_char_type(s[i]);
		while (get_char_type(s[i]) == SPACE)
			i++;
		/* if (type == SPACE)
			i = handle_spaces(vars, s, i, type); */
		if (type == '<' || type == '>' || type == '|')
			i = handle_redirectors(vars, s, i, type);
		/* else if (type == SQUOTE)
			i = handle_squotes(vars, s, i, type);
		else if (type == DQUOTE)
			i = handle_dquotes(vars, s, i, type); */
		/* else if (type == NAME)
			i = handle_name(vars, s, i, type); */
		else if (type == GENERAL || type == SQUOTE || type == DQUOTE || 
		type == NAME)
			i = handle_word(vars, s, i, type);
	}
	add_token(&vars->head, new_token(NULL, NEWLINE));
}

int	get_char_type(int c)
{
	if (c == DLESS)
		return (DLESS);
	else if (c == DGREAT)
		return (DGREAT);
	else if (c == LESS)
		return (LESS);
	else if (c == GREAT)
		return (GREAT);
	else if (c == PIPE)
		return (PIPE);
	else if (c == SQUOTE)
		return (SQUOTE);
	else if (c == DQUOTE)
		return (DQUOTE);
	else if ((c >= 8 && c <= 13) || (c == 32))
		return (SPACE);
	else if (c == NAME)
		return (NAME); // $
	else 
		return (GENERAL);
}
 
 /*		parses through the linked list and converts any element with 
TYPE: LESS, GREAT or DGREAT who is preceeded by an element with TYPE: WORD
to TYPE: FILENAME
*/
void	word_to_filename(t_token *head)
{
	while (head)
	{
		if (head->type == LESS || head->type == GREAT || 
		head->type == DGREAT || head->type == DLESS) // ?
		{
			if (head->next)
			{
				if (head->next->type == WORD)
					head->next->type = FILENAME;
			}
		}
		head = head->next;
	}
}
