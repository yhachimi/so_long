/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachimi <yhachimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 11:24:23 by yhachimi          #+#    #+#             */
/*   Updated: 2026/02/11 14:10:23 by yhachimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libs/so_long.h"

void	put_rect(t_data *data, void *img, int row, int colm)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img, colm
		* data->cell_size, row * data->cell_size);
}

void	put_all_chars(t_data *data)
{
	int	row;
	int	colm;

	row = 0;
	while (row < data->height)
	{
		colm = 0;
		while (colm < data->width)
		{
			if (data->map[row][colm] == 'P')
				put_rect(data, data->images.rd, row, colm);
			colm++;
		}
		row++;
	}
}

void	set_moves(t_moves *moves, int row, int colm)
{
	moves->start[0] = row;
	moves->start[1] = colm;
}

void	flood_fill(char **map, int x, int y, t_size size)
{
	if ((x < 0 || y < 0) || (x >= size.height || y >= size.width))
		return ;
	if (map[x][y] == 'V' || map[x][y] == '1')
		return ;
	map[x][y] = 'V';
	flood_fill(map, (x + 1), y, size);
	flood_fill(map, (x - 1), y, size);
	flood_fill(map, x, (y + 1), size);
	flood_fill(map, x, (y - 1), size);
}
