/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlucke <wlucke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:47:10 by wlucke            #+#    #+#             */
/*   Updated: 2024/04/29 18:00:59 by wlucke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t size)
{
	size_t	i;
	size_t	tmp_i;
	char	*tmp_haystack;
	char	*tmp_needle;

	i = 0;
	if (*needle == '\0')
		return ((char *) haystack);
	while (*haystack != '\0' && i < size)
	{
		tmp_needle = (char *) needle;
		tmp_haystack = (char *) haystack;
		tmp_i = i;
		while (*tmp_haystack == *tmp_needle && tmp_i < size)
		{
			tmp_haystack++;
			tmp_needle++;
			tmp_i++;
			if (*tmp_needle == '\0')
				return ((char *) haystack);
		}
		haystack++;
		i++;
	}
	return (NULL);
}
