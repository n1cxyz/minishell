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

int	handle_and_or(t_vars *vars, const char *s, int i)
{
	if (s[i] == '&' && s[i + 1] == '&')
	{
		add_token(&vars->head, new_token(ft_substr("&&", 0, 2), AND));
		vars->pipeline_count++;
		vars->and_or[vars->k] = '&';
		vars->k++;
		i++;
	}
	else if (s[i] == '|' && s[i + 1] == '|')
	{
		add_token(&vars->head, new_token(ft_substr("||", 0, 2), OR));
		vars->pipeline_count++;
		vars->and_or[vars->k] = '|';
		vars->k++;
		i++;
	}
	else
		return (i);
	i++;
	return (i);
}

int	handle_parent(t_vars *vars, const char *s, int i)
{
	if (s[i] == '(')
	{
		add_token(&vars->head, new_token(ft_substr(s, i, 1), PARENTL));
		vars->parent_count++;
	}
	else if (s[i] == ')')
	{
		add_token(&vars->head, new_token(ft_substr(s, i, 1), PARENTR));
		vars->parent_count--;
		if (vars->parent_count < 0)
			syntax_error(vars);
	}
	else
		return (i);
	i++;
	return (i);
}

void	tokenize(t_vars *vars, const char *s)
{
	int	i;
	int	type;

	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
	{
		type = get_char_type(s[i]);
		while (get_char_type(s[i]) == SPACE)
			i++;
		if (s[i] == '(' || s[i] == ')')
			i = handle_parent(vars, s, i);
		else if ((s[i] == '&' && s[i + 1] == '&') || 
			(s[i] == '|' && s[i + 1] == '|'))
			i = handle_and_or(vars, s, i);
		else if (type == '<' || type == '>' || type == '|')
			i = handle_redirectors(vars, s, i, type);
		else if (type == GENERAL || type == SQUOTE || type == DQUOTE || 
			type == NAME)
			i = handle_word(vars, s, i, type);
	}
	vars->and_or[vars->k] = '\0';
	vars->pipeline_count = vars->k;
	if (vars->parent_count != 0)
		syntax_error(vars);
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
		return (NAME);
	else 
		return (GENERAL);
}

int	handle_redirectors(t_vars *vars, const char *s, int i, int type)
{
	if ((type == '<') && (type == get_char_type(s[i + 1])))
	{
		add_token(&vars->head, new_token(ft_substr("<<", 0, 2), DLESS));
		i++;
	}
	else if ((type == '>') && (type == get_char_type(s[i + 1])))
	{
		add_token(&vars->head, new_token(ft_substr(">>", 0, 2), DGREAT));
		i++;
	}
	else
		add_token(&vars->head, new_token(ft_substr(s, i, 1), type));
	i++;
	return (i);
}
