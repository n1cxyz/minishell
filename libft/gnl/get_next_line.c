/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlucke <wlucke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:50:10 by wlucke            #+#    #+#             */
/*   Updated: 2024/05/29 14:51:07 by wlucke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	ssize_t		nbytes;
	char		*line;
	char		*tmp;

	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE < 1 || read(fd, buffer, 0) < 0)
	{
		ft_bzero(buffer, BUFFER_SIZE);
		return (NULL);
	}
	line = ft_strdup((const char *) buffer + 1);
	nbytes = 1;
	while (check_new_line(line) == 0 && nbytes != 0)
	{
		ft_bzero(buffer, BUFFER_SIZE);
		nbytes = read(fd, buffer, BUFFER_SIZE);
		tmp = ft_strjoin(line, buffer);
		free(line);
		line = tmp;
	}
	line = clean_save_cut(buffer, line, nbytes);
	return (line);
}

char	*cut_line(char *old_line)
{
	int		i;
	int		len;
	char	*new_line;

	i = 0;
	while (old_line[i] != '\n' && old_line[i] != '\0')
		i++;
	len = i;
	new_line = (char *)malloc((len + 2) * sizeof(char));
	i = 0;
	while (old_line[i] != '\n' && old_line[i] != '\0')
	{
		new_line[i] = old_line[i];
		i++;
	}
	new_line[i] = old_line[i];
	i++;
	new_line[i] = '\0';
	free(old_line);
	return (new_line);
}

void	save_overflow(char *line, char *overflow)
{
	int		i;
	int		len;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	len = i;
	i = 0;
	while (line[len + i] != '\0')
	{
		overflow[i] = line[len + i];
		i++;
	}
	overflow[i] = '\0';
}

int	check_new_line(char *line)
{
	size_t	i;

	if (line == NULL)
		return (0);
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*clean_save_cut(char *buffer, char *line, ssize_t nbytes)
{
	if (nbytes == 0 && *line == '\0')
	{
		free(line);
		return (NULL);
	}
	ft_bzero(buffer, BUFFER_SIZE);
	save_overflow(line, buffer);
	line = cut_line(line);
	return (line);
}
