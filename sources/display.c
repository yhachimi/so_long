/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachimi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 11:13:44 by yhachimi          #+#    #+#             */
/*   Updated: 2026/02/13 17:21:46 by yhachimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libs/so_long.h"

static void	help_moves(t_data *data, int keycode, int *mvs)
{
	if (data->map[data->moves.start[0]][data->moves.start[1]] == '1'
		|| (data->map[data->moves.start[0]][data->moves.start[1]] == 'E'
			&& check_coins(data)))
	{
		if (keycode == 119)
			data->moves.start[0] += 1;
		else if (keycode == 115)
			data->moves.start[0] -= 1;
		else if (keycode == 97)
			data->moves.start[1] += 1;
		else if (keycode == 100)
			data->moves.start[1] -= 1;
		*mvs -= 1;
	}
}

static void	move_player(t_data *data, int keycode, int *mvs)
{
	if (keycode == 119)
	{
		data->pd = data->images.ru;
		data->moves.start[0] -= 1;
		*mvs += 1;
	}
	else if (keycode == 115)
	{
		data->pd = data->images.rd;
		data->moves.start[0] += 1;
		*mvs += 1;
	}
	else if (keycode == 97)
	{
		data->pd = data->images.rl;
		data->moves.start[1] -= 1;
		*mvs += 1;
	}
	else if (keycode == 100)
	{
		data->pd = data->images.rr;
		data->moves.start[1] += 1;
		*mvs += 1;
	}
	help_moves(data, keycode, mvs);
}

int	hook_key(int keycode, t_data *data)
{
	static int	mvs;
	static int	tmp;
	char		*str;

	if (keycode == 65307)
	{
		free_display(data, &data->images);
		exit(0);
	}
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	display_map(data, &data->images);
	move_player(data, keycode, &mvs);
	put_all_chars(data);
	if ((keycode == 119 || keycode == 100 || keycode == 97 || keycode == 115)
		&& tmp != mvs)
	{
		str = ft_itoa(mvs);
		ft_putend(str, 1);
		free(str);
	}
	tmp = mvs;
	return (0);
}

static void	calc_cell_size(t_data *data)
{
	data->cell_size = 40;
	data->bordr = 3;
}

void	display(t_data *data, t_moves *moves)
{
	static t_image	images;

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
	mlx_hook(data->win_ptr, 33, 0, close_exit, data);
	mlx_loop(data->mlx_ptr);
}
