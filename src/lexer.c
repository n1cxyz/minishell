/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasal <dasal@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:04:01 by dasal             #+#    #+#             */
/*   Updated: 2024/09/05 09:04:03 by dasal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	parse_input(t_vars *vars, char *s)
{
	//"< $Makefile cat | wc -w > outfile\n"
	int	i;
	int	type;
	// to check: '<', '<<', '>', '>>', '|', ', ", $, <space>, 
	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
	{
		if (!vars->quote_status)
			check_invalid_syntax(vars, s[i]);
		while ((get_char_type(s[i])) == SPACE)
			i++;
		type = get_char_type(s[i]);
		if (type == '<' || type == '>' || type == '|')
		{
			if ((handle_redirector(vars, s, i, type)))
				i++;
			else
				add_token(&vars->head, new_token(ft_substr(s, i, 1), type));
		}
		else if (type == '$' || type == GENERAL)
		//	sets i to one index before next delimiter
			i = handle_word_name(vars, s, i, type);
		// so far: '<', '<<', '>', '>>', '|', <space>, '$', <general>.

		// check for beginning of quote
		if (type == DQUOTE || type == SQUOTE)
			i = handle_quotes(vars, s, i, type);
		i++;		
	}
	//	add END token
	add_token(&vars->head, new_token(NULL, END));
}

int	handle_quotes(t_vars *vars, char *s, int i, int type)
{
	vars->quote_status = 1;
	//"\"<Makefile cat|wc -w\">>outfile\n"
	int	j;
	int	len;
	//char *substring;
	//"$HOME" or "HOME"
	if (type == DQUOTE || type == SQUOTE)
		i++;
	else
	{
		free_token(vars->head);
		perror("handle_quote wrong type");
        exit(EXIT_FAILURE);
	}
	// j = starting position
	j = i;
	len = 0;
	while (s[i] != '\0')
	{
		if (s[i] == type)
			break;
		i++;
		len++;
	}
	if (s[i] == '\0')
	/* {
		free_token(vars->head);
		perror("unclosed quote");
        exit(EXIT_FAILURE);
	} */
	//substring = ft_substr(s, s + j, len);
	add_token(&vars->head, new_token(ft_substr(s, j, len), type));
	return (i - 1);	
}

int	handle_word_name(t_vars *vars, char *s, int i, int type)
{
	//" $HOME>outfile"
	int	j;
	int	len;
	//char *substring;
	//"$HOME" or "HOME"
	if (type == '$')
		i++;
	// j = starting position
	j = i;
	len = 0;
	while (!(is_delimiter(s[i])))
	{
		i++;
		len++;
	}
	//substring = ft_substr(s, s + j, len);
	if (type == '$')
		add_token(&vars->head, new_token(ft_substr(s, j, len), NAME));
	else 
		add_token(&vars->head, new_token(ft_substr(s, j, len), WORD));
	return (i - 1);	
}

//	checks for '<<' and '>>', returns 1 if found, otherwise 0.
int	handle_redirector(t_vars *vars, char *s, int i, int type)
{
	// check next char for '<<'
	if ((type == '<') && (type == get_char_type(s[i + 1])))
	{
		// handle here_doc
		add_token(&vars->head, new_token(ft_substr("<<", 0, 2), DLESS));
		return (1);
	}
	// check next char for '>>'
	else if ((type == '>') && (type == get_char_type(s[i + 1])))
	{
		// handle '>>'
		add_token(&vars->head, new_token(ft_substr(">>", 0, 2), DGREAT));
		return  (1);
	}
	return (0);
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
		head->type == DGREAT)
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
	else if (c == 32 || c == '\t')
		return (SPACE);
	else if (c == '$')
		return ('$');
	else 
		return (GENERAL);
}
 
