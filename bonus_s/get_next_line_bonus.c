/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachimi <yhachimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:46:57 by yhachimi          #+#    #+#             */
/*   Updated: 2026/02/03 19:24:28 by yhachimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libs/get_next_line.h"

int	line_len(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
		{
			i += 1;
			return (i);
		}
		i++;
	}
	return (i);
}

static char	*dup_line(char	*str)
{
	int		i;
	char	*p;

	if (!str)
		return (NULL);
	p = malloc(line_len(str) + 1);
	i = 0;
	if (!p)
		return (NULL);
	while (str[i])
	{
		p[i] = str[i];
		if (str[i] == '\n')
			break ;
		i++;
	}
	if (str[i] == '\n')
		p[i++] = '\n';
	p[i] = '\0';
	return (p);
}

static char	*read_tell_line(int fd, char *tmp)
{
	char	*p;
	ssize_t	byte_read;

	p = malloc(BUFFER_SIZE + 1);
	if (!p)
		return (NULL);
	byte_read = 1;
	while (!ft_strchr(tmp, '\n') && byte_read > 0)
	{
		byte_read = read(fd, p, BUFFER_SIZE);
		if (byte_read < 0)
		{
			free(p);
			return (free(tmp), NULL);
		}
		p[byte_read] = '\0';
		tmp = ft_strjoin(tmp, p);
		if (!tmp)
		{
			free(p);
			return (NULL);
		}
	}
	free(p);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*tmp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp = read_tell_line(fd, tmp);
	if (!tmp || !*tmp)
	{
		free(tmp);
		tmp = NULL;
		return (NULL);
	}
	line = dup_line(tmp);
	if (!line)
	{
		free(tmp);
		tmp = NULL;
		return (NULL);
	}
	if (line[0] == '\0')
		free(line);
	tmp = del_cat(tmp);
	return (line);
}
