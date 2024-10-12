/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlucke <wlucke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:50:13 by wlucke            #+#    #+#             */
/*   Updated: 2024/05/24 12:57:22 by wlucke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_hex(unsigned long long nbr, char c)
{
	int	len;

	len = 0;
	if (nbr >= 16)
	{
		len += ft_put_hex(nbr / 16, c);
		len += ft_put_hex(nbr % 16, c);
	}
	else
	{
		if (nbr < 10)
			len += ft_putchar(nbr + '0');
		else
			len += ft_putchar(nbr - 10 + c);
	}
	return (len);
}
