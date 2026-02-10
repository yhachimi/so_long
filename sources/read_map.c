/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachimi <yhachimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 11:24:53 by yhachimi          #+#    #+#             */
/*   Updated: 2026/02/10 15:03:51 by yhachimi         ###   ########.fr       */
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
				return (ft_putend("Error: Invalid map border", 2), 0);
			if (row == height - 1 && map[row][colm] != '1')
				return (ft_putend("Error: Invalid map border", 2), 0);
			if (colm == 0 && map[row][colm] != '1')
				return (ft_putend("Error: Invalid map border", 2), 0);
			if (colm == width - 1 && map[row][colm] != '1')
				return (ft_putend("Error: Invalid map border", 2), 0);
			colm++;
		}
		row++;
	}
	return (1);
}

int	check_the_map_chars(int e, int c, char **map, int height)
{
	int	row;
	int	colm;
	int	p;

	row = 0;
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
	if (p != 1 || e != 1 || c <= 0)
		return (ft_putend("Error: Bad character input", 2), 0);
	return (1);
}

static int	help_check(char **map, int height)
{
	int	row;
	int	colm;

	row = 0;
	while (row < height)
	{
		colm = 0;
		while (map[row][colm])
		{
			if (map[row][colm] == 'E' || map[row][colm] == 'C')
			{
				ft_putend("Error: no path found to (exit/coins)", 2);
				return (0);
			}
			colm++;
		}
		row++;
	}
	return (1);
}

int	check_valid_path(char **map, int h, int w, t_moves *moves)
{
	t_size	size;
	int		row;
	int		colm;

	if (!map || !*map)
		return (0);
	row = 0;
	colm = 0;
	size.height = h;
	size.width = w;
	while (row < size.height)
	{
		colm = 0;
		while (map[row][colm])
		{
			if (map[row][colm] == 'P')
				break ;
			colm++;
		}
		if (map[row][colm] == 'P')
			break ;
		row++;
	}
	flood_fill(map, row, colm, size);
	return (set_moves(moves, row, colm), help_check(map, h));
}
