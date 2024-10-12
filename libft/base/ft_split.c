/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlucke <wlucke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:46:35 by wlucke            #+#    #+#             */
/*   Updated: 2024/05/02 16:07:24 by wlucke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c);
static char		**splitter(char const *s, char c, char	**split);
static char		**reverse(char **split, size_t words);
static char		*add_word(char *s, size_t word_start, size_t word_end);

char	**ft_split(char const *s, char c)
{
	size_t	words;
	char	**split;

	words = count_words(s, c);
	split = (char **)malloc((words + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	split = splitter(s, c, split);
	split[words] = NULL;
	return (split);
}

static size_t	count_words(char const *s, char c)
{
	size_t	words;
	size_t	len;

	len = ft_strlen(s);
	words = 0;
	while (len != 0)
	{
		while (s[len - 1] == c && len > 0)
			len--;
		while (s[len - 1] != c && len > 0)
			len--;
		if (s[len] != c)
			words++;
	}
	return (words);
}

static char	**splitter(char const *s, char c, char **split)
{
	size_t	words;
	size_t	word_end;
	size_t	word_start;

	word_end = ft_strlen(s);
	words = 0;
	while (word_end != 0)
	{
		while (s[word_end - 1] == c && word_end > 0)
			word_end--;
		word_start = word_end;
		while (s[word_start - 1] != c && word_start > 0)
			word_start--;
		if (s[word_start] != c)
		{
			split[words] = add_word((char *) s, word_start, word_end);
			words++;
		}
		word_end = word_start;
	}
	split = reverse(split, words);
	return (split);
}

static char	*add_word(char *s, size_t word_start, size_t word_end)
{
	char	*word;

	word = ft_substr(s, word_start, word_end - word_start);
	return (word);
}

static char	**reverse(char **split, size_t words)
{
	size_t	i;
	char	*tmp;

	i = 0;
	while (i < words / 2)
	{
		tmp = split[i];
		split[i] = split[words - i - 1];
		split[words - i - 1] = tmp;
		i++;
	}
	return (split);
}
