/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachimi <hachimiyounes1337@gmail.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 11:45:11 by yhachimi          #+#    #+#             */
/*   Updated: 2026/02/04 12:22:38 by yhachimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libs/so_long.h"

char	*read_map(int fd)
{
	char	*av;
	char	*tmp;

	av = NULL;
	if (fd < 0)
		return (NULL);
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			return (av);
		av = ft_strjoin(av, tmp);
		free(tmp);
	}
}

int	check_map_boarder(char **map, int height, int width)
{
	int	row;
	int	colm;

	if (!map || !*map)
		return (0);
	row = 0;
	colm = 0;
	while (row < height)
	{
		colm = 0;
		while (map[row][colm])
		{
			if (row == 0 && map[row][colm] != '1')
				return (0);
			if (row == height - 1 && map[row][colm] != '1')
				return (0);
			if (colm == 0 && map[row][colm] != '1')
				return (0);
			if (colm == width - 1 && map[row][colm] != '1')
				return (0);
			colm++;
		}
		row++;
	}
	return (1);
}

int	check_the_map_chars(char **map, int height)
{
	int	row;
	int	colm;
	int	c;
	int	e;
	int	p;

	row = 0;
	c = 0;
	e = 0;
	p = 0;
	while (row < height)
	{
		colm = 0;
		while (map[row][colm])
		{
			if (map[row][colm] == 'P')
				p += 1;
			if (map[row][colm] == 'C')
				c += 1;
			if (map[row][colm] == 'E')
				e += 1;
			colm++;
		}
		row++;
	}
	if (p != 1 | e != 1 | c <= 0)
		return (0);
	return (1);
}

void	check_valid_path(char **map, int height, int width)
{
	return ;
}
