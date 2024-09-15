/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasal <dasal@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:16:42 by dasal             #+#    #+#             */
/*   Updated: 2024/09/13 12:16:43 by dasal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_dasal.h"

void	expand(t_vars *vars)
{
	vars->cur = vars->head;
	next_token(vars);
	while (vars->cur->type != NEWLINE)
	{
		if (vars->cur->type == WORD)
			find_names(vars);
		next_token(vars);
	}
	vars->cur = vars->head;
	next_token(vars);
	while (vars->cur->type != NEWLINE)
	{
		if (vars->cur->type == WORD)
			remove_quotes(vars);
		next_token(vars);
	}
}

void		find_names(t_vars *vars)
{
	int		i;
	int		index;
	char	*name;

	(void)vars;
	i = 0;
	while(vars->cur->content[i])
	{
		while (vars->cur->content[i] == 39)
			i++;
		if (((get_char_type(vars->cur->content[i])) == NAME))
		{
			name = get_name(vars, i);
			index = get_name_index(vars, name);
			vars->cur->content = substr_replace(vars, name, index);
			free (name);
		}
		i++;
	}
	//free (vars->cur->content);
}

char	*substr_replace(t_vars *vars, char *s1, int index)
{
	int		i;
	int		j;
	char	*s2;
	char	*result;

	i = 0;
	j = 0;
	s2 = getenv(s1 + 1);
	if (!s2)
		return (result = substr_remove(vars, '?'));
	result = (char *)malloc(sizeof(char) * ((ft_strlen(vars->cur->content) - 
	ft_strlen(s1) + ft_strlen(s2)) + 1));
	while (i < (ft_strlen(vars->cur->content) - ft_strlen(s1) + ft_strlen(s2)))
	{
		if (i == index)
		{
			ft_memcpy(result + i, s2, ft_strlen(s2));
			i += ft_strlen(s2);
			j += ft_strlen(s1);
		}
		result[i++] = vars->cur->content[j++];
	}
	return (result);
}

char	*substr_remove(t_vars *vars, char c)
{
	int		i;
	char	*result;

	i = 0;
	while (vars->cur->content[i])
	{
		if (vars->cur->content[i] == c)
			break;
		i++;
	}
	if (get_char_type(vars->cur->content[0]) == DQUOTE)
		i++;
	result = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (vars->cur->content[i])
	{
		if (vars->cur->content[i] == c)
			break;
		result[i] = vars->cur->content[i];
		i++;
	}
	if (get_char_type(vars->cur->content[0]) == DQUOTE)
	{
		result[i] = '-'; // DQUOTE
		i++;
	}
	result[i] = '\0';
	return (result);
}
