/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlucke <wlucke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:46:10 by wlucke            #+#    #+#             */
/*   Updated: 2024/04/29 18:20:00 by wlucke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t size)
{
	const unsigned char	*str1;
	const unsigned char	*str2;

	str1 = ptr1;
	str2 = ptr2;
	while (0 < size)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
		size--;
	}
	return (0);
}

/*
Difference between strcmp and memcmp!
strcmp:
memcmp:
*/

/*
Idea You can insert every variable type but then does the same?
*/

/*
Important if-statement if ptr1 or ptr2 start with NUL
Important how to assign variable types in function
*/