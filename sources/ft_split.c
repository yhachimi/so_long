/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachimi <yhachimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 11:24:38 by yhachimi          #+#    #+#             */
/*   Updated: 2026/02/06 11:24:44 by yhachimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

void	*free_all(char **p, size_t len)
{
	while (len)
	{
		len--;
		free(p[len]);
	}
	free(p);
	return (NULL);
}

size_t	count(char const *s, char c)
{
	size_t	word;
	size_t	i;
	size_t	size;

	i = 0;
	word = 0;
	size = 0;
	while (s[i])
	{
		if (s[i] == c)
			word = 0;
		else if (s[i] != c && word == 0)
		{
			word = 1;
			size++;
		}
		i++;
	}
	return (size);
}

static size_t	split_len(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	*dup_word(char const *s, char c)
{
	char	*p;
	size_t	i;
	size_t	len;

	len = split_len(s, c);
	p = malloc(len + 1);
	i = 0;
	if (!p)
		return (NULL);
	while (i < len)
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	size_t	i;
	size_t	len;

	if (!s)
		return (NULL);
	len = count(s, c);
	p = malloc(sizeof(char *) * (len + 1));
	i = 0;
	while (i < len)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			p[i] = dup_word(s, c);
			if (!p[i])
				return (free_all(p, i));
			s += split_len(s, c);
			i++;
		}
	}
	p[i] = NULL;
	return (p);
}
