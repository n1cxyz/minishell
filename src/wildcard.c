/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasal <dasal@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:28:08 by dasal             #+#    #+#             */
/*   Updated: 2024/10/08 10:28:09 by dasal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

char	*match_files(t_vars *vars, struct dirent *entry, 
	char *prefix, char *suffix)
{
	char	tmp[BUFFER_SIZE];
	int		len;
	int		len_prefix;

	len = 0;
	len_prefix = ft_strlen(prefix);
	vars->first_file = 1;
	tmp[0] = '\0';
	while (entry)
	{
		if (!ft_strncmp(entry->d_name, prefix, len_prefix))
		{
			if (!suffix || ft_strnstr(entry->d_name, suffix, 
					ft_strlen(entry->d_name)))
			{
				if (!vars->first_file)
					tmp[len++] = ' ';
			}
			ft_strlcpy(tmp + len, entry->d_name, ft_strlen(entry->d_name) + 1);
			len += ft_strlen(entry->d_name);
			vars->first_file = 0;
		}
		entry = readdir(vars->dir);
	}
	return (alloc_result_w(tmp, len));
}

void	match_suffix(t_vars *vars, struct dirent *entry, char *suffix)
{
	char	tmp[BUFFER_SIZE];
	size_t	len;
	size_t	entry_len;

	len = 0;
	tmp[0] = '\0';
	while (entry)
	{
		if (ft_str_suffix(entry->d_name, suffix))
		{
			entry_len = ft_strlen(entry->d_name);
			if (len > 0)
				tmp[len++] = ' ';
			ft_strlcpy(tmp + len, entry->d_name, ft_strlen(entry->d_name) + 1);
			len += entry_len;
		}
		entry = readdir(vars->dir);
	}
	if (len > 0)
	{
		free(vars->cur->content);
		vars->cur->content = ft_strdup(tmp);
	}
}

void	match_all(t_vars *vars, struct dirent *entry)
{
	char	tmp[BUFFER_SIZE];
	int		len;

	vars->first_file = 1;
	len = 0;
	while (entry)
	{
		if (entry->d_name[0] != '.')
		{
			if (!vars->first_file)
				tmp[len++] = ' ';
			ft_strlcpy(tmp + len, entry->d_name, ft_strlen(entry->d_name) + 1);
			len += ft_strlen(entry->d_name);
			vars->first_file = 0;
		}
		entry = readdir(vars->dir);
	}
	if (len > 0)
	{
		free(vars->cur->content);
		vars->cur->content = ft_strdup(tmp);
	}
}

void	search_wildcard(t_vars *vars, struct dirent *entry)
{
	vars->prefix = NULL;
	vars->suffix = NULL;
	if (wildcard_in_quotes(vars) == -1)
		return ;
	remove_quotes(vars);
	if (vars->y > 0)
		vars->prefix = ft_strndup(vars->cur->content, vars->y);
	if (vars->cur->content[vars->y] != '\0')
	{
		if (vars->cur->content[vars->y + 1])
			vars->suffix = ft_strdup(vars->cur->content + vars->y + 1);
	}
	if (!vars->prefix && !vars->suffix)
		match_all(vars, entry);
	else if (!vars->prefix)
		match_suffix(vars, entry, vars->suffix);
	else
	{
		vars->tmp = match_files(vars, entry, vars->prefix, vars->suffix);
		if (vars->tmp && vars->tmp[0])
			alloc_content(vars);
	}
	free (vars->prefix);
	free (vars->suffix);
}

void	wildcard(t_vars *vars)
{
	struct dirent	*entry;

	vars->dir = opendir(".");
	if (!vars->dir)
	{
		perror("opendir");
		return ;
	}
	entry = readdir(vars->dir);
	search_wildcard(vars, entry);
	closedir(vars->dir);
}
