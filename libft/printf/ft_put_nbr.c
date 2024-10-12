/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlucke <wlucke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:50:17 by wlucke            #+#    #+#             */
/*   Updated: 2024/05/24 12:57:25 by wlucke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_nbr(long long int nbr)
{
	char	c;
	int		len;

	len = 0;
	if (nbr < 0)
	{
		len += ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr >= 10)
	{
		len += ft_put_nbr(nbr / 10);
		len += ft_put_nbr(nbr % 10);
	}
	else
	{
		c = nbr + '0';
		len += ft_putchar(c);
	}
	return (len);
}
