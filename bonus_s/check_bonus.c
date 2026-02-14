/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachimi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 12:56:44 by yhachimi          #+#    #+#             */
/*   Updated: 2026/02/14 13:20:39 by yhachimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libs/so_long_bonus.h"

static void	count_chars(char **map, int height, int *counts)
{
	int	row;
	int	colm;

	row = 0;
	while (row < height)
	{
		colm = 0;
		while (map[row][colm])
		{
			if (map[row][colm] == 'P')
				counts[0]++;
			else if (map[row][colm] == 'C')
				counts[1]++;
			else if (map[row][colm] == 'E')
				counts[2]++;
			else if (map[row][colm] == 'M')
				counts[3]++;
			colm++;
		}
		row++;
	}
}

int	close_exit(t_data *data)
{
	mlx_loop_end(data->mlx_ptr);
	free_display(data, &data->images);
	exit(0);
	return (0);
}

int	check_the_map_chars(char **map, int height, t_data *data)
{
	int	counts[4];

	counts[0] = 0;
	counts[1] = 0;
	counts[2] = 0;
	counts[3] = 0;
	count_chars(map, height, counts);
	if (counts[0] != 1 || counts[2] != 1 || counts[1] <= 0 || counts[3] < 1)
		return (ft_putend("Error: Bad character input", 2), 0);
	data->enemy_counts = counts[3];
	return (1);
}
