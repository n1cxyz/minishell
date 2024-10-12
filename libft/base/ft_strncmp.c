/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlucke <wlucke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:47:06 by wlucke            #+#    #+#             */
/*   Updated: 2024/04/30 17:17:16 by wlucke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strncmp(const char *str1, const char *str2, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (0);
	if ((unsigned char) str1[0] == '\0' || (unsigned char) str2[0] == '\0')
		return ((unsigned char) str1[0] - (unsigned char) str2[0]);
	else
	{
		while ((str1[i] != '\0' && str2[i] != '\0') && i < size - 1)
		{
			if ((unsigned char) str1[i] - (unsigned char) str2[i] != 0)
				return ((unsigned char) str1[i] - (unsigned char) str2[i]);
			i++;
		}
	}
	return ((unsigned char) str1[i] - (unsigned char) str2[i]);
}
