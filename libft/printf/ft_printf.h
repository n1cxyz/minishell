/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sevo <sevo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:09:27 by wlucke            #+#    #+#             */
/*   Updated: 2024/10/03 13:36:41 by sevo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "../base/libft.h"

int		ft_printf(const char *str, ...);
int		ft_print(const char *str, va_list args);
int		ft_putarg_i(va_list args, char specifier);
int		ft_putarg_u(va_list args, char specifier);
int		ft_putarg_p(va_list args, char specifier);
int		ft_put_hex(unsigned long long int nbr, char c);
int		ft_put_addr(const void *addr);
int		ft_put_nbr( long long int nbr);
int		ft_put_unbr(unsigned long long nbr);
int		ft_putchar(char c);
int		ft_putstr(char *s);

#endif
