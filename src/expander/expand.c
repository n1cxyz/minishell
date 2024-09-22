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

void	expand(t_vars *vars, t_pipex *data) //	***
{
	vars->cur = vars->head;
	next_token(vars);
	while (vars->cur->type != NEWLINE)
	{
		if (vars->cur->type == WORD && vars->cur->content != NULL)
			expand_env(vars, data); //	***
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
//	***
void		expand_env(t_vars *vars, t_pipex *data)
{
	char			result[1024] = {0};
	unsigned int	result_len = 0;
	int				in_single_quotes = 0;
	int				i = 0;
	
	while (vars->cur->content[i] != '\0')
	{
		if (vars->cur->content[i] == 39)
		{
			in_single_quotes = !in_single_quotes;
			result[result_len++] = vars->cur->content[i++];
		}
		else if (vars->cur->content[i] == '?' && !in_single_quotes)
		{
			 if (vars->cur->content[i + 1] == '?' && (i == 0 || !ft_isalnum(vars->cur->content[i - 1])))
			 {
				char *exitcode_str = ft_itoa(vars->exit_code);
				result_len += ft_strlcpy(result + result_len, exitcode_str, sizeof(result) - result_len);
				i += 2;
				free (exitcode_str);
				continue;
			}
			if ((vars->cur->content[i + 1] == '\0') || (!ft_isalnum(vars->cur->content[i + 1]) && vars->cur->content[i+1] != '_'))
			{
				result[result_len++] = vars->cur->content[i++];
				continue;
			}
			i++;
			char var_name[256] = {0};
			int var_len = 0;
			
			while (vars->cur->content[i] != '\0' && (ft_isalnum(vars->cur->content[i]) || vars->cur->content[i] == '_'))
				var_name[var_len++] = vars->cur->content[i++];
			var_name[var_len] = '\0';
			
			char *var_value = ft_getenv(data, var_name);
			
			if (var_value)
			{
				ft_strlcpy(result + result_len, var_value, sizeof(result) - result_len - 1);
				result_len += ft_strlen(var_value);
			}
        }
		else
			result[result_len++] = vars->cur->content[i++];
		if (result_len >= sizeof(result) - 1)
			break;
	}
	
	result[result_len] = '\0';
	
	free(vars->cur->content);
	vars->cur->content = malloc(result_len + 1);
	if (vars->cur->content)
		ft_strlcpy(vars->cur->content, result, result_len + 1);
}

char	*ft_getenv(t_pipex *data, char *name)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(name);
	while (data->env[i])
	{
		if (strncmp(data->env[i], name, len) == 0 && data->env[i][len] == '=')
		 	return (data->env[i] + len + 1);
		i++;
	}
	return NULL;
}
//	***