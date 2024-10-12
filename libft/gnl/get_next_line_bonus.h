/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlucke <wlucke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:50:10 by wlucke            #+#    #+#             */
/*   Updated: 2024/05/29 14:50:50 by wlucke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# ifndef MAX_FD
#  define MAX_FD 64
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
int		check_new_line(char *line);
char	*cut_line(char *line);
void	save_overflow(char *line, char *overflow);
char	*clean_save_cut(char *buffer, char *line, ssize_t nbytes);

void	ft_bzero(void *ptr, size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t size);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *str);

#endif