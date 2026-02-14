/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachimi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 13:00:43 by yhachimi          #+#    #+#             */
/*   Updated: 2026/02/13 13:14:34 by yhachimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libs/so_long.h"

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
	images->ru = gen_image("chrs/run/ru1.xpm", data);
	data->pd = images->rd;
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
	return (0);
}
