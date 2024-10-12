/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlucke <wlucke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:46:45 by wlucke            #+#    #+#             */
/*   Updated: 2024/05/01 13:58:11 by wlucke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

/*
Function name       ft_striteri
Prototype           void ft_striteri(char *s, void (*f)(unsigned int, char*));
Turn in files       -
Parameters          s: The string on which to iterate.
                    f: The function to apply to each character.
Return value        None
External functs.    None
Description         Applies the function ’f’ on each character of
                    the string passed as argument, passing its index
                    as first argument. Each character is passed by
                    address to ’f’ to be modified if necessary.
*/