/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlucke <wlucke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:09:16 by wlucke            #+#    #+#             */
/*   Updated: 2024/05/24 12:57:09 by wlucke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print(const char *str, va_list args)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			if (ft_strchr("cdi", str[i]) != NULL)
				len += ft_putarg_i(args, str[i]);
			if (ft_strchr("uxX", str[i]) != NULL)
				len += ft_putarg_u(args, str[i]);
			if (ft_strchr("sp", str[i]) != NULL)
				len += ft_putarg_p(args, str[i]);
			if (str[i] == '%')
				len += ft_putchar('%');
		}
		else
			len += ft_putchar(str[i]);
		i++;
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	va_list	args;

	if (str == NULL)
		return (-1);
	va_start(args, str);
	len = ft_print(str, args);
	va_end(args);
	return (len);
}
