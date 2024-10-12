/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlucke <wlucke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:40:02 by wlucke            #+#    #+#             */
/*   Updated: 2024/04/29 17:56:55 by wlucke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if (c == ' ' || (c >= '\t' && c <= '\r'))
	{
		return (8192);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	nbr;
	int	sign;

	sign = 1;
	nbr = 0;
	while (ft_isspace((char) *str) != 0)
		str++;
	if (ft_strncmp(str, "-2147483648", 11) == 0)
		return (-2147483648);
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str) != 0)
	{
		nbr = nbr * 10;
		nbr = nbr + *str - 48;
		str++;
	}
	return (sign * nbr);
}
