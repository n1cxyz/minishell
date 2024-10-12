/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlucke <wlucke@student.42.fr>                  +#+  +:+       +#+    */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 09:36:55 by wlucke            #+#    #+#             */
/*   Updated: 2024/09/26 10:32:06 by wlucke             ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini.h"

static int	valid_arg(const char	*input);

int	builtin_exit(t_pipex *data, t_vars *vars, const char *input)
{
	int			code;

	code = 0;
	if (input)
	{
		if (vars->cur->next->next->type != NEWLINE)
		{
			code = 1;
			ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		}
		else
			code = valid_arg(input);
	}
	free_token(vars->head);
	free_minishell(data);
	ft_printf("exit\n");
	exit(code);
}

static int	valid_arg(const char	*input)
{
	int	code;

	while (is_space(*input) || *input == 7)
		++input;
	if (ft_isdigit(*input))
		code = ft_atoi(input);
	while (ft_isdigit(*input))
		++input;
	while (is_space(*input) || *input == 7)
		++input;
	if (*input != '\0')
	{
		errno = EINVAL;
		perror("numeric argument required");
		code = 2;
	}
	return (code);
}
