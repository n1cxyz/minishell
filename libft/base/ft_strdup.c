/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlucke <wlucke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:46:41 by wlucke            #+#    #+#             */
/*   Updated: 2024/05/24 12:57:49 by wlucke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*dup;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	dup = (char *) malloc(len + 1 * sizeof(char));
	if (dup == NULL)
		return (NULL);
	dup = ft_memcpy(dup, str, len + 1);
	return (dup);
}
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char *ft_strdup(const char *s1) {
    size_t len = strlen(s1);
    char *new_str = (char *)malloc(len + 1);

    if (new_str == NULL) {
        return NULL;
    }

    strcpy(new_str, s1);
    return new_str;
}
*/