/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlucke <wlucke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:50:19 by wlucke            #+#    #+#             */
/*   Updated: 2024/05/24 12:57:29 by wlucke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_unbr(unsigned long long nbr)
{
	char	c;
	int		len;

	len = 0;
	if (nbr >= 10)
	{
		len += ft_put_unbr(nbr / 10);
		len += ft_put_unbr(nbr % 10);
	}
	else
	{
		c = nbr + '0';
		len += ft_putchar(c);
	}
	return (len);
}
