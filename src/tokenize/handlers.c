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
	return (i);
}

int	handle_squotes(t_vars *vars, const char *s, int i, int type)
{
	(void)type;
	i++;
	while (s[i] != '\0')
	{
		if (get_char_type(s[i]) == SQUOTE)
			break ;
		i++;
	}
	if (s[i] == '\0')
		unclosed_quote(vars);
	return (i);
}

int	handle_dquotes(t_vars *vars, const char *s, int i, int type)
{
	(void)type;
	i++;
	while (s[i] != '\0')
	{
		if (get_char_type(s[i]) == DQUOTE)
			break ;
		i++;
	}
	if (s[i] == '\0')
		unclosed_quote(vars);
	return (i);
}

int	handle_word(t_vars *vars, const char *s, int i, int type)
{
	int	j;

	j = i;
	(void)type;
	while (!(is_delimiter(s[i])) && s[i] != '(' && s[i] != ')')
	{
		if (get_char_type(s[i]) == SQUOTE)
			i = handle_squotes(vars, s, i, type);
		else if (get_char_type(s[i]) == DQUOTE)
			i = handle_dquotes(vars, s, i, type);
		if (s[i] != '\0')
			i++;
	}
	add_token(&vars->head, new_token(ft_substr(s, j, i - j), WORD));
	return (i);
}

int	handle_name(t_vars *vars, const char *s, int i, int type)
{
	int	j;

	j = i;
	(void)type;
	while ((!(is_delimiter(s[i]))) && ((s[i] != SQUOTE) && (s[i] != DQUOTE)))
		i++;
	if (i - j == 1)
		add_token(&vars->head, new_token(ft_substr(s, j, i - j), WORD));
	else
		add_token(&vars->head, new_token(ft_substr(s, j, i - j), WORD));
	return (i);
}
