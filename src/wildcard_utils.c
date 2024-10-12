/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasal <dasal@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:34:50 by dasal             #+#    #+#             */
/*   Updated: 2024/10/08 11:34:52 by dasal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	ft_str_suffix(char *str, char *suffix)
{
	size_t	str_len;
	size_t	suffix_len;

	str_len = ft_strlen(str);
	suffix_len = ft_strlen(suffix);
	if (suffix_len > str_len)
		return (0);
	return (ft_strncmp(str + (str_len - suffix_len), suffix, suffix_len) == 0);
}

//	returns 1 if '*' was found inside quotes or not found
int	wildcard_in_quotes(t_vars *vars)
{
	int	i;

	vars->y = 0;
	i = 0;
	while (vars->cur->content[vars->y])
	{
		if (vars->cur->content[vars->y] == 39 && !vars->dq)
		{
			i--;
			vars->sq = !vars->sq;
		}
		else if (vars->cur->content[vars->y] == 34 && !vars->sq)
		{
			i--;
			vars->dq = !vars->dq;
		}
		if (vars->cur->content[vars->y] == '*' && !vars->sq && !vars->dq)
			break ;
		vars->y++;
		i++;
	}
	if (vars->sq || vars->dq || vars->cur->content[vars->y] != '*')
		return (-1);
	vars->y = i;
	return (1);
}

void	alloc_content(t_vars *vars)
{
	free(vars->cur->content);
	vars->cur->content = vars->tmp;
}

char	*alloc_result_w(char *buffer, int len)
{
	char	*result;

	if (len == 0)
		return (NULL);
	result = malloc(len + 1);
	if (result)
		ft_strlcpy(result, buffer, ft_strlen(buffer) + 1);
	return (result);
}
