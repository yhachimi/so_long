/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_chrs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachimi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 14:21:45 by yhachimi          #+#    #+#             */
/*   Updated: 2026/02/13 13:15:29 by yhachimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libs/so_long_bonus.h"

static void	help_display(t_data *data, t_image *images, int row, int colm)
{
	int	last_row;
	int	last_col;

	last_row = data->height - 1;
	last_col = data->width - 1;
	if (row == 0 && colm == 0)
		data->img_ptr = images->ce_wall;
	else if (row == 0 && colm == last_col)
		data->img_ptr = images->re_wall;
	else if (row == last_row && colm == 0)
		data->img_ptr = images->lr_wall;
	else if (row == last_row && colm == last_col)
		data->img_ptr = images->lc_wall;
	else if (row == 0)
		data->img_ptr = images->c_wall;
	else if (row == last_row)
		data->img_ptr = images->down_wall;
	else if (colm == 0)
		data->img_ptr = images->left_wall;
	else if (colm == last_col)
		data->img_ptr = images->r_wall;
	else
		data->img_ptr = images->m_wall;
}

void	display_image(t_data *data, t_image *images, int row, int colm)
{
	char	tile;

	tile = data->map[row][colm];
	if (tile == '1')
	{
		help_display(data, images, row, colm);
		return ;
	}
	else
		data->img_ptr = images->path;
}

int	display_moves(t_data *data, int moves)
{
	char	*str;

	if (!data)
		return (0);
	str = ft_itoa(moves);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 10, 0xFFFFFF, str);
	free(str);
	return (1);
}
