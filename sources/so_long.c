/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachimi <hachimiyounes1337@gmail.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 19:05:00 by yhachimi          #+#    #+#             */
/*   Updated: 2026/02/03 19:27:12 by yhachimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

char	*read_map(int fd)
{
	char	*av;
	char	*tmp;

	if (fd <= 0)
		return (NULL);
	av = malloc(1);
	if (!av)
		return (NULL);
	av = '\0';
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

int	main(void)
{
	char	*str;
	char	**map;
	int		fd;
	size_t	height;
	size_t	width;

	fd = open("../maps/map1.ber", O_RDONLY);
	str = read_map(fd);
	height = count(str, '\n');
	map = ft_split(str, '\n');
	width = 0;
	while (map[0][width])
		width++;
	if (!check_map_boarder(map, height, width))
	{
		free_all(map, height);
		free(str);
		close(fd);
		return (1);
	}
	free(str);
	free_all(map, height);
	close(fd);
	return (0);
}
