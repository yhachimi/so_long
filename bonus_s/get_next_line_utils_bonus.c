/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachimi <yhachimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 18:03:48 by yhachimi          #+#    #+#             */
/*   Updated: 2026/02/03 18:28:53 by yhachimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libs/get_next_line.h"

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

static void	ft_strm(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[n] = src[i];
		n++;
		i++;
	}
	dest[n] = '\0';
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i;

	if (!s2)
		return (NULL);
	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (NULL);
		*s1 = '\0';
	}
	i = 0;
	res = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		return (free(s1), NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	ft_strm(res, s2, i);
	free(s1);
	return (res);
}

int	ft_strchr(char	*s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return (1);
		i++;
	}
	return (0);
}

char	*del_cat(char	*str)
{
	int		i;
	int		len;
	char	*new;

	if (!str)
		return (NULL);
	i = line_len(str);
	len = 0;
	while (str[i + len])
		len++;
	if (len == 0)
		return (free(str), NULL);
	new = malloc(len + 1);
	if (!new)
		return (free(str), NULL);
	len = 0;
	ft_strm(new, &str[i], 0);
	free(str);
	return (new);
}
