/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlucke <wlucke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 09:33:36 by wlucke            #+#    #+#             */
/*   Updated: 2024/10/01 12:44:08 by wlucke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	exit_error(t_pipex *data, char *error_message, int exit_code)
{
	perror(error_message);
	free_data(data);
	exit(exit_code);
}

char	*first_word(char *str)
{
	unsigned int	i;
	size_t			j;

	i = 0;
	j = 0;
	while (str[i] == 32 || str[i] == 9)
		i++;
	while ((str[i + j] != 32 && str[i + j] != 9) && str[i + j])
		j++;
	return (ft_substr(str, i, j));
}

void	seven_to_space(char *str)
{
	while (*str)
	{
		if (*str == 7)
			*str = ' ';
		str++;
	}
}

void	seven_to_nul(char *str)
{
	if (str[0] == 7 && str[1] == '\0')
		str[0] = '\0';
}
