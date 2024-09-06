/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasal <dasal@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:38:48 by dasal             #+#    #+#             */
/*   Updated: 2024/09/06 11:38:49 by dasal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	handle_spaces(t_vars *vars, char *s, int i, int type)
{
	int	j;

	j = i;
	while (is_space(s[i]) && s[i])
		i++;
	add_token(&vars->head, new_token(ft_substr(s, j, i - j), type));
	return (i - 1);
}

int	handle_redirectors(t_vars *vars, char *s, int i, int type)
{
	if ((type == '<') && (type == get_char_type(s[i + 1])))
	{
		// handle here_doc
		add_token(&vars->head, new_token(ft_substr("<<", 0, 2), DLESS));
		i++;
	}
	else if ((type == '>') && (type == get_char_type(s[i + 1])))
	{
		// handle '>>'
		add_token(&vars->head, new_token(ft_substr(">>", 0, 2), DGREAT));
		i++;
	}
	else
		// handle '<' or '>' or '|'
		add_token(&vars->head, new_token(ft_substr(s, i, 1), type));
	return (i);
}

int	handle_squotes(t_vars *vars, char *s, int i, int type)
{
	//	many spaces in quote ' $HOME                 '  ?
	int	j;

	j = i;
	(void)type;
	while (s[i] != '\0')
	{
		if (get_char_type(s[i]) == SQUOTE)
		{
			//i++;
			break;
		}
		i++;
	}
	if (s[i] == '\0')
		free_error_exit(vars, "unclosed quote\n");
	add_token(&vars->head, new_token(ft_substr(s, j, i - j), SQUOTE));
	return (i);	
}

int	handle_dquotes(t_vars *vars, char *s, int i, int type)
{
	int	j;

	j = i;
	(void)type;
	while (s[i] != '\0')
	{
		if (get_char_type(s[i]) == DQUOTE)
		{
			//i++;
			break;
		}
		if (s[i] == '?')
			i = handle_name(vars, s, i, type);
		i++;
	}
	if (s[i] == '\0')
		free_error_exit(vars, "unclosed quote\n");
	add_token(&vars->head, new_token(ft_substr(s, j, i - j), DQUOTE));
	return (i);	
}

int	handle_word(t_vars *vars, char *s, int i, int type)
{
	int	j;
	//"$HOME" or "HOME"
	/* if (type == '?')
		i++; */

	//		{ }
	j = i;
	while (!(is_delimiter(s[i])))
	{
		//check_invalid_syntax(vars, s[i]);
		//	bugfix for "'asd'?HOME"
		if (s[i] == '?' && ((i - j) > 0))
		{
			add_token(&vars->head, new_token(ft_substr(s, j, i - j), WORD));
			i = handle_name(vars, s, i, type);
			vars->added_token = 1;
		}
		else if (get_char_type(s[i]) == SQUOTE)
			i = handle_squotes(vars, s, i + 1, type);
		else if (get_char_type(s[i]) == DQUOTE)
			i = handle_dquotes(vars, s, i + 1, type);
		i++;
	}
	if (!(vars->added_token))
		add_token(&vars->head, new_token(ft_substr(s, j, i - j), WORD));
	return (i - 1);	
}

int	handle_name(t_vars *vars, char *s, int i, int type)
{
	int	j;
	(void)type;
	//"$HOME" or "HOME"
	/* if (type == '?')
		i++; */
	j = i;
	while ((!(is_delimiter(s[i]))) && ((s[i] != SQUOTE) && (s[i] != DQUOTE)))
	{
		//check_invalid_syntax(vars, s[i]);
		i++;
	}
	add_token(&vars->head, new_token(ft_substr(s, j, i - j), NAME));
	return (i - 1);	
}
