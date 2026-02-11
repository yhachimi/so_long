/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachimi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 11:13:44 by yhachimi          #+#    #+#             */
/*   Updated: 2026/02/11 18:11:49 by yhachimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libs/so_long.h"

int	hook_key(int keycode, t_data *data)
{
	static int	mvs;
	t_image		images;

	if (keycode == 32)
		mlx_loop_end(data->mlx_ptr);
	if (keycode == 119)
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		display_map(data, &data->images);
		data->moves.start[0] -= 1;
		if (data->map[data->moves.start[0]][data->moves.start[1]] == '1'
			|| (data->map[data->moves.start[0]][data->moves.start[1]] == 'E')
			&& check_coins(data))
			data->moves.start[0] += 1;
		else
			mvs += 1;
		put_all_chars(data);
		ft_putend(ft_itoa(mvs), 1);
		display_moves(data, mvs);
	}
	if (keycode == 100)
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		display_map(data, &data->images);
		data->moves.start[1] += 1;
		if (data->map[data->moves.start[0]][data->moves.start[1]] == '1'
			|| (data->map[data->moves.start[0]][data->moves.start[1]] == 'E')
			&& check_coins(data))
			data->moves.start[1] -= 1;
		else
			mvs += 1;
		put_all_chars(data);
		ft_putend(ft_itoa(mvs), 1);
		display_moves(data, mvs);
	}
	if (keycode == 97)
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		display_map(data, &data->images);
		data->moves.start[1] -= 1;
		if (data->map[data->moves.start[0]][data->moves.start[1]] == '1'
			|| (data->map[data->moves.start[0]][data->moves.start[1]] == 'E')
			&& check_coins(data))
			data->moves.start[1] += 1;
		else
			mvs += 1;
		put_all_chars(data);
		ft_putend(ft_itoa(mvs), 1);
		display_moves(data, mvs);
	}
	if (keycode == 115)
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		display_map(data, &data->images);
		data->moves.start[0] += 1;
		if (data->map[data->moves.start[0]][data->moves.start[1]] == '1'
			|| (data->map[data->moves.start[0]][data->moves.start[1]] == 'E')
			&& check_coins(data))
			data->moves.start[0] -= 1;
		else
			mvs += 1;
		put_all_chars(data);
		ft_putend(ft_itoa(mvs), 1);
		display_moves(data, mvs);
	}
	return (0);
}

static void	calc_cell_size(t_data *data)
{
	data->cell_size = 40;
	data->bordr = 3;
}

void	init_images(t_image *images, t_data *data)
{
	images->r_wall = gen_image("chrs/normlwall.xpm", data);
	images->c_wall = gen_image("chrs/0s_wall.xpm", data);
	images->rd = gen_image("chrs/run/rd1.xpm", data);
	images->path = gen_image("chrs/path.xpm", data);
	images->rl = gen_image("chrs/run/rl1.xpm", data);
	images->rr = gen_image("chrs/run/re1.xpm", data);
	images->re_wall = gen_image("chrs/wdt_wall.xpm", data);
	images->ce_wall = gen_image("chrs/left_top.xpm", data);
	images->lc_wall = gen_image("chrs/end_swall.xpm", data);
	images->lr_wall = gen_image("chrs/ends_nwall.xpm", data);
	images->m_wall = gen_image("chrs/midle_wall.xpm", data);
	images->down_wall = gen_image("chrs/down_wall.xpm", data);
	images->left_wall = gen_image("chrs/left_wall.xpm", data);
	images->portal = gen_image("chrs/portal.xpm", data);
	images->coin = gen_image("chrs/coin.xpm", data);
	data->images = *images;
}

int	display_map(t_data *data, t_image *images)
{
	int	row;
	int	colm;

	row = 0;
	colm = 0;
	while (row < data->height)
	{
		colm = 0;
		while (colm < data->width)
		{
			display_image(data, images, row, colm);
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr,
				colm * data->cell_size, row * data->cell_size);
			colm++;
		}
		row++;
	}
}

void	display(t_data *data, t_moves *moves)
{
	t_image	images;

	data->mlx_ptr = mlx_init();
	calc_cell_size(data);
	data->win_width = data->width * data->cell_size;
	data->win_height = data->height * data->cell_size;
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->win_width,
			data->win_height, "so_long");
	init_images(&images, data);
	data->moves = *moves;
	mlx_key_hook(data->win_ptr, hook_key, data);
	display_map(data, &images);
	put_all_chars(data);
	mlx_loop(data->mlx_ptr);
}
