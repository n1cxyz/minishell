/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlucke <wlucke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:45:04 by wlucke            #+#    #+#             */
/*   Updated: 2024/05/01 16:49:30 by wlucke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_intlen(int n)
{
	size_t		len;

	len = 1;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	len = count_intlen(n);
	if (n < 0)
		n = -n;
	str = (char *) ft_calloc(sizeof(char), (len + 1));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	len--;
	while (n != 0)
	{
		str[len] = (n % 10) + 48;
		n = n / 10;
		len--;
	}
	if (len == 0)
		str[0] = '-';
	return (str);
}
