/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlucke <wlucke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:47:14 by wlucke            #+#    #+#             */
/*   Updated: 2024/05/02 15:07:29 by wlucke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*last;

	last = NULL;
	while (*str != '\0')
	{
		if (*str == (char) c)
		{
			last = (char *) str;
		}
		str++;
	}
	if (*str == '\0' && (char) c == '\0')
		return ((char *) str);
	return (last);
}

//no crash
/*
char	*ft_strrchr(const char *str, int c)
{
	char	*last;

	if (str == NULL)
		return (NULL);
	last = NULL;
	while (*str != '\0')
	{
		if (*str == (char) c)
		{
			last = (char *) str;
		}
		str++;
	}
	if (*str == '\0' && (char) c == '\0')
		return ((char *) str);
	return (last);
}
*/