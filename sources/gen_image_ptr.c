/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_image_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachimi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 15:09:07 by yhachimi          #+#    #+#             */
/*   Updated: 2026/02/11 10:46:07 by yhachimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libs/so_long.h"

void	*gen_image(char *img_path, t_data *data)
{
	int	y;
	int	x;

	return (mlx_xpm_file_to_image(data->mlx_ptr, img_path, &x, &y));
}

void	put_image(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, x, y);
}
