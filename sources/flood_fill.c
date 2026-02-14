/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachimi <yhachimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 11:24:23 by yhachimi          #+#    #+#             */
/*   Updated: 2026/02/14 13:35:07 by yhachimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libs/so_long.h"

void	put_rect(t_data *data, void *img, int row, int colm)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img, colm
		* data->cell_size, row * data->cell_size);
}

static void	draw_map_items(t_data *data, int px, int py)
{
	int	row;
	int	col;

	row = 0;
	while (row < data->height)
	{
		col = 0;
		while (col < data->width)
		{
			if (data->map[row][col] == 'C' && !(row == px && col == py))
				put_rect(data, data->images.coin, row, col);
			else if (data->map[row][col] == 'E')
				put_rect(data, data->images.portal, row, col);
			col++;
		}
		row++;
	}
}

void	put_all_chars(t_data *data)
{
	int	x;
	int	y;

	x = data->moves.start[0];
	y = data->moves.start[1];
	if (data->map[x][y] != '1')
	{
		if (data->map[x][y] == 'E' && !check_coins(data))
		{
			mlx_loop_end(data->mlx_ptr);
			free_display(data, &data->images);
			exit(0);
		}
		put_rect(data, data->pd, x, y);
		data->map[x][y] = '0';
	}
	draw_map_items(data, x, y);
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
	if (map[x][y] == 'E')
	{
		map[x][y] = 'V';
		return ;
	}
	map[x][y] = 'V';
	flood_fill(map, (x + 1), y, size);
	flood_fill(map, (x - 1), y, size);
	flood_fill(map, x, (y + 1), size);
	flood_fill(map, x, (y - 1), size);
}
