/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlucke <wlucke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:46:10 by wlucke            #+#    #+#             */
/*   Updated: 2024/04/29 18:15:34 by wlucke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//https://www.youtube.com/watch?v=Njsn5HAnAnk
//memset is a function in string.h and only works for strings (char 1 byte)

/*
The ft_memset function fills a block of memory with a specified value.

Parameters:
ptr – A pointer to the block of memory to be filled.
value – The value to be set.
n – The number of bytes to be set.

Return:
A pointer to the memory block after it has been filled.
*/

//Why *(unsigned char *)? --> Take whatever pointer and treat it as a string

#include <stdlib.h>

void	*ft_memset(void *ptr, int value, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		*(unsigned char *)(ptr + i) = (unsigned char) value;
		i++;
	}
	return (ptr);
}
