/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_addr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlucke <wlucke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:50:10 by wlucke            #+#    #+#             */
/*   Updated: 2024/05/24 12:57:18 by wlucke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_addr(const void *addr)
{
	unsigned long long	nbr;
	int					len;

	len = 0;
	nbr = (unsigned long long)addr;
	len += ft_putchar('0');
	len += ft_putchar('x');
	len += ft_put_hex(nbr, 'a');
	return (len);
}
