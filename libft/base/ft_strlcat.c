/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlucke <wlucke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:46:52 by wlucke            #+#    #+#             */
/*   Updated: 2024/05/14 11:29:45 by wlucke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dsize)
{
	size_t	i;
	size_t	src_len;
	size_t	dest_len;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	if (dsize == 0)
		return (src_len);
	if (dsize < dest_len)
		return (dsize + src_len);
	i = 0;
	while (src[i] != '\0' && dest_len + i < dsize - 1)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}

/*
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t 	i;
	size_t	src_len;
    size_t  dest_len;

	i = 0;
    src_len = ft_strlen(src);
    dest_len = ft_strlen(dest);
	if (src[0] != '\0')
	{
		while (src[i] != '\0' && i < size)
		{
			dest[dest_len + i] = src[i];
			i++;
		}
		i = i - 1;
	}
	// while (i < size)
	// {
	// 	dest[i] = '\0';
	// 	i++;
	// }
	dest[i] = '\0';
	return (src_len + dest_len);
}
*/