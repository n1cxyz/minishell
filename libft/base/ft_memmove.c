/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlucke <wlucke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:09:34 by wlucke            #+#    #+#             */
/*   Updated: 2024/05/01 11:26:49 by wlucke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest < src)
		dest = ft_memcpy(dest, src, size);
	else
	{
		while (size)
		{
			size--;
			*(unsigned char *)(dest + size) = *(unsigned char *)(src + size);
		}
	}
	return (dest);
}

/*
void *ft_memmove(void *dst, const void *src, size_t len) {
    char *d = (char *)dst;
    const char *s = (const char *)src;

    if (d < s) {
        while (len--) {
            *d++ = *s++;
        }
    } else {
        d += len;
        s += len;
        while (len--) {
            *--d = *--s;
        }
    }

    return dst;
}
*/