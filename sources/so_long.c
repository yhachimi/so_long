/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachimi <yhachimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 11:23:26 by yhachimi          #+#    #+#             */
/*   Updated: 2026/02/14 18:23:10 by yhachimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"
#include "stdio.h"

static int	check_all_map(char **map, int height)
{
	int		row;
	int		colm;
	char	*p;

	row = 0;
	p = "EPC10";
	while (row < height)
	{
		colm = 0;
		while (map[row][colm])
		{
			if (ft_strcmp(map[row][colm], p))
			{
				return (ft_putend("Error", 2), 0);
			}
			colm++;
		}
		row++;
	}
	return (1);
}

static int	free_exit(t_data data, char *str, int status)
{
	free(str);
	free_all(data.map, data.height);
	close(data.fd);
	return (status);
}

static int	parsing_help(t_data data, t_moves *moves)
{
	if (!check_map_boarder(data.map, data.height, data.width)
		|| !check_the_map_chars(0, 0, data.map, data.height)
		|| !check_valid_path(data.map, data.height, data.width, moves))
		return (1);
	return (0);
}

static int	map_read(t_data *data, t_moves *moves)
{
	char	*str;
	char	**tmp;

	data->fd = open(data->path, O_RDONLY);
	str = read_map(data->fd);
	if (!str)
		return (close(data->fd), 1);
	data->height = count(str, '\n');
	data->map = ft_split(str, '\n');
	tmp = ft_split(str, '\n');
	if (!data->map || !tmp)
		return ((close(data->fd), free(str), 1));
	data->width = 0;
	while (data->map[0][data->width])
		data->width++;
	if (parsing_help(*data, moves))
	{
		free_all(tmp, data->height);
		return (free_exit(*data, str, 1));
	}
	free_all(data->map, data->height);
	data->map = tmp;
	return (free(str), 0);
}

int	main(int ac, char **av)
{
	t_data	data;
	t_moves	moves;

	if (ac != 2)
		return (1);
	data.path = av[1];
	if (map_read(&data, &moves))
		return (1);
	if (!check_all_map(data.map, data.height))
		return (free_exit(data, NULL, 1));
	display(&data, &moves);
	return (free_exit(data, NULL, 0));
}
