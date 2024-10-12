/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlucke <wlucke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:44:46 by wlucke            #+#    #+#             */
/*   Updated: 2024/05/22 11:54:16 by wlucke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num_elements, size_t size_bytes)
{
	void	*mem;

	if (num_elements == 0 || size_bytes == 0)
	{
		mem = malloc(0);
		return (mem);
	}
	if (size_bytes > (size_t)(-1) / num_elements)
		return (NULL);
	mem = malloc(num_elements * size_bytes);
	if (mem == NULL)
		return (NULL);
	ft_memset(mem, 0, num_elements * size_bytes);
	return (mem);
}
