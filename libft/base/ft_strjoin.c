/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlucke <wlucke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:46:48 by wlucke            #+#    #+#             */
/*   Updated: 2024/05/14 11:29:34 by wlucke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*output;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	output = (char *) malloc(len_s1 + len_s2 + 1);
	if (output == NULL)
		return (NULL);
	ft_strlcpy(output, s1, len_s1 + 1);
	ft_strlcat(output, s2, len_s1 + len_s2 + 1);
	return (output);
}
