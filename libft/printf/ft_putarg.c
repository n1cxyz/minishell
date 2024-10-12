/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putarg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlucke <wlucke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:53:52 by wlucke            #+#    #+#             */
/*   Updated: 2024/05/24 12:57:32 by wlucke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putarg_i(va_list args, char specifier)
{
	int		arg_i;
	int		len;

	arg_i = va_arg(args, int);
	len = 0;
	if (specifier == 'c')
		len = ft_putchar(arg_i);
	else if (specifier == 'd' || specifier == 'i')
		len = ft_put_nbr(arg_i);
	return (len);
}

int	ft_putarg_u(va_list args, char specifier)
{
	unsigned int	arg_u;
	int				len;

	arg_u = va_arg(args, unsigned int);
	len = 0;
	if (specifier == 'u')
		len = ft_put_unbr(arg_u);
	else if (specifier == 'x')
		len = ft_put_hex(arg_u, 'a');
	else if (specifier == 'X')
		len = ft_put_hex(arg_u, 'A');
	return (len);
}

int	ft_putarg_p(va_list args, char specifier)
{
	void	*arg_p;
	int		len;

	arg_p = va_arg(args, void *);
	len = 0;
	if (specifier == 's' && arg_p == NULL)
		len = ft_putstr("(null)");
	else if (specifier == 's')
		len = ft_putstr((char *) arg_p);
	else if (specifier == 'p' && arg_p == NULL)
		len = ft_putstr("(nil)");
	else if (specifier == 'p')
		len = ft_put_addr(arg_p);
	return (len);
}
