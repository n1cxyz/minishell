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

#include "mini.h"

void	expand(t_vars *vars)
{
	//	set cur to beginning of list
	vars->cur = vars->head;
	next_token(vars);
	printf("token content: %s\n", vars->cur->content);
	expand_names(vars);
	next_token(vars);
	printf("token content: %s\n", vars->cur->content);
	expand_names(vars);
	//remove_quotes();
}

void	expand_names(t_vars *vars)
{
	//	finds '$' in the current node if it's not inside single quotes,
	//	checkes if it is an envirnonment variable 
	contains_dollar(vars->cur->content);
}

void	contains_dollar(char *s)
{
	int		i;
	int		j;
	int		single_quote_status;
	int		len;
	char	*name;

	i = 0;
	len = 0;
	single_quote_status = 0;

	while(s[i])
	{
		if (s[i] == 39)
			single_quote_status = 1;
		if (((get_char_type(s[i])) == NAME) && (single_quote_status == 0))
		{
			i++;
			j = i;
			while (s[i])
			{
				if (is_name_delimiter(s[i]))
					break;
				len++;
				i++;
			}
			name = ft_substr(s, j, len);
			//check_name(name);
			printf("name is: %s\n", name);
		}
		i++;
		if (s[i] == 39)
			single_quote_status = 0;
	}
}
