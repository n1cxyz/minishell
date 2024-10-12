/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlucke <wlucke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:46:05 by wlucke            #+#    #+#             */
/*   Updated: 2024/05/02 15:06:16 by wlucke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int value, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (*(unsigned char *) ptr == (unsigned char) value)
			return ((void *)ptr);
		ptr++;
		i++;
	}
	return (NULL);
}

//no crash
/*
void	*ft_memchr(const void *ptr, int value, size_t size)
{
	size_t	i;

	i = 0;
	if (ptr == NULL || size == 0)
		return (NULL);
	while (i < size)
	{
		if (*(unsigned char *) ptr == (unsigned char) value)
			return ((void *)ptr);
		ptr++;
		i++;
	}
	return (NULL);
}
*/