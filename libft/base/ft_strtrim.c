/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlucke <wlucke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:47:23 by wlucke            #+#    #+#             */
/*   Updated: 2024/05/01 15:49:46 by wlucke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim; 
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	if (s1[0] == '\0' || set[0] == '\0') //bit actually somewhere in set?
        return (ft_strdup(""));
	start = 0;
	while (s1[start] != '\0' && ft_strchr(set, (int) s1[start]) != NULL)
		start++;
	end = ft_strlen(s1) - 1;
	while (start < end && ft_strrchr(set, (int) s1[end]) != NULL) 
		end--;
	if (start > end)
		return (ft_strdup(""));
	trim = ft_strdup(ft_substr(s1, start, end - start + 1));
	if (trim == NULL)
		return (NULL);
	return (trim);
}
*/

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	start;
	size_t	end;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	if (s1[0] == '\0')
		return (ft_strdup(""));
	start = 0;
	while (s1[start] != '\0' && ft_strchr(set, s1[start]) != NULL)
		start++;
	end = ft_strlen(s1) - 1;
	while (end >= start && ft_strchr(set, s1[end]) != NULL)
		end--;
	len = end - start + 1;
	trim = malloc(sizeof(char) * (len + 1));
	if (trim == NULL)
		return (NULL);
	ft_strlcpy(trim, s1 + start, len + 1);
	return (trim);
}
