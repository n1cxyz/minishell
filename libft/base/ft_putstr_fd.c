/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlucke <wlucke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:46:31 by wlucke            #+#    #+#             */
/*   Updated: 2024/05/24 12:58:15 by wlucke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	while (*s != '\0')
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}

/*
Function name       ft_putstr_fd
Prototype           void ft_putstr_fd(char *s, int fd);
Turn in files       -
Parameters          s: The string to output.
                    fd: The file descriptor on which to write.
Return value        None
External functs.    write
Description         Outputs the string ’s’ to the given file descriptor.
*/