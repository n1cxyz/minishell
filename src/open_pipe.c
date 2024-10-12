/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlucke <wlucke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:42:17 by dasal             #+#    #+#             */
/*   Updated: 2024/10/02 09:57:41 by wlucke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

char	*open_pipe(t_vars *vars, char *input)
{
	int		i;
	char	*result;

	(void) vars;
	i = 0;
	if (!input)
		return (NULL);
	if (!clear_postpipe(input))
		return (input);
	while (input[i])
		i++;
	i--;
	while (i > 0)
	{
		while (is_space(input[i]) && i > 0)
			i--;
		if (input[i] == '|' && check_operator(input, i))
			return (result = new_input(input));
		else
			return (input);
		if (i > 0)
			i--;
	}
	return (input);
}

char	*new_input(char *input)
{
	char	*result;
	char	*buffer;

	buffer = get_next_line(STDIN_FILENO);
	result = ft_strjoin(input, buffer);
	free(buffer);
	free(input);
	return (result);
}

int	clear_postpipe(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '|')
		return (0);
	while (is_space(s[i]) || s[i] == '|')
	{
		if (s[i] == '|')
		{
			i++;
			if (s[i] == '\0')
				return (0);
			while (is_space(s[i]) || s[i] == '\0')
			{
				if (s[i] == '\0')
					return (0);
				i++;
			}
			continue ;
		}
		i++;
	}
	return (1);
}

int	check_operator(char *s, int i)
{
	if (i > 0)
		i--;
	if ((s[i] == '<') || (s[i] == '>') || (s[i] == '|'))
		return (0);
	while (i > 0)
	{
		if (ft_isalnum(s[i]))
			break ;
		if ((s[i] == '<') || (s[i] == '>') || (s[i] == '|') || (s[i] == '&'))
			return (0);
		i--;
	}
	return (1);
}
