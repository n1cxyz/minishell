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

#include "mini_dasal.h"

int	handle_spaces(t_vars *vars, char *s, int i, int type)
{
	int	j;

	j = i;
	while (is_space(s[i]) && s[i])
		i++;
	add_token(&vars->head, new_token(ft_substr(s, j, i - j), type));
	return (i);
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
		add_token(&vars->head, new_token(ft_substr(">>", 0, 2), DGREAT));
		i++;
	}
	else
		add_token(&vars->head, new_token(ft_substr(s, i, 1), type));
	i++;
	return (i);
}

int	handle_squotes(t_vars *vars, char *s, int i, int type)
{
	//	many spaces in quote ' $HOME                 '  ?
	(void)type;
	i++;
	while (s[i] != '\0')
	{
		if (get_char_type(s[i]) == SQUOTE)
			break;
		i++;
	}
	if (s[i] == '\0')
		free_error_exit(vars, "minishell: unclosed squote\n");
	return (i);	
}

int	handle_dquotes(t_vars *vars, char *s, int i, int type)
{
	(void)type;
	i++;
	while (s[i] != '\0')
	{
		if (get_char_type(s[i]) == DQUOTE)
			break;
		i++;
	}
	if (s[i] == '\0')
		free_error_exit(vars, "unclosed dquote\n");
	return (i);	
}

int	handle_word(t_vars *vars, char *s, int i, int type)
{
	(void)type;
	int	j;

	j = i;
	while (!(is_delimiter(s[i])))
	{
		if (get_char_type(s[i]) == SQUOTE)
			i = handle_squotes(vars, s, i , type);
		else if (get_char_type(s[i]) == DQUOTE)
			i = handle_dquotes(vars, s, i , type);
		i++;
	}
	add_token(&vars->head, new_token(ft_substr(s, j, i - j), WORD));
	return (i);	
}

int	handle_name(t_vars *vars, char *s, int i, int type)
{
	int	j;
	(void)type;

	j = i;
	while ((!(is_delimiter(s[i]))) && ((s[i] != SQUOTE) && (s[i] != DQUOTE)))
		i++;
	if (i - j == 1)
		add_token(&vars->head, new_token(ft_substr(s, j, i - j), WORD));
	else
		add_token(&vars->head, new_token(ft_substr(s, j, i - j), WORD)); // type NAME
	return (i);	
}
