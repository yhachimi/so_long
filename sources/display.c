/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachimi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 11:13:44 by yhachimi          #+#    #+#             */
/*   Updated: 2026/02/10 14:28:23 by yhachimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libs/so_long.h"

int	hook_key(int keycode, t_data *data)
{
	if (keycode == 32)
		mlx_loop_end(data->mlx_ptr);
	return (0);
}

static int	calc_cell_size(t_data *data)
{
	data->cell_size = 40;
	data->bordr = 3;
}

void	display(t_data *data, t_moves *moves)
{
	data->mlx_ptr = mlx_init();
	calc_cell_size(data);
	data->win_width = data->width * data->cell_size;
	data->win_height = data->height * data->cell_size;
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->win_width,
			data->win_height, "so_long");
	mlx_key_hook(data->win_ptr, hook_key, data);
	mlx_loop(data->mlx_ptr);
}
