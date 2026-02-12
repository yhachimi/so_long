/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachimi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:17:44 by yhachimi          #+#    #+#             */
/*   Updated: 2026/02/12 12:43:49 by yhachimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libs/so_long.h"

static void	destroy_images_part1(t_data *data, t_image *img)
{
	if (img->r_wall)
		mlx_destroy_image(data->mlx_ptr, img->r_wall);
	if (img->c_wall)
		mlx_destroy_image(data->mlx_ptr, img->c_wall);
	if (img->re_wall)
		mlx_destroy_image(data->mlx_ptr, img->re_wall);
	if (img->ce_wall)
		mlx_destroy_image(data->mlx_ptr, img->ce_wall);
	if (img->lc_wall)
		mlx_destroy_image(data->mlx_ptr, img->lc_wall);
	if (img->lr_wall)
		mlx_destroy_image(data->mlx_ptr, img->lr_wall);
}

static void	destroy_images_part2(t_data *data, t_image *img)
{
	if (img->m_wall)
		mlx_destroy_image(data->mlx_ptr, img->m_wall);
	if (img->left_wall)
		mlx_destroy_image(data->mlx_ptr, img->left_wall);
	if (img->down_wall)
		mlx_destroy_image(data->mlx_ptr, img->down_wall);
	if (img->rd)
		mlx_destroy_image(data->mlx_ptr, img->rd);
	if (img->ru)
		mlx_destroy_image(data->mlx_ptr, img->ru);
	if (img->coin)
		mlx_destroy_image(data->mlx_ptr, img->coin);
}

static void	destroy_images_part3(t_data *data, t_image *img)
{
	if (img->rl)
		mlx_destroy_image(data->mlx_ptr, img->rl);
	if (img->rr)
		mlx_destroy_image(data->mlx_ptr, img->rr);
	if (img->path)
		mlx_destroy_image(data->mlx_ptr, img->path);
	if (img->portal)
		mlx_destroy_image(data->mlx_ptr, img->portal);
}

static void	destroy_images(t_data *data, t_image *img)
{
	if (!img)
		return ;
	destroy_images_part1(data, img);
	destroy_images_part2(data, img);
	destroy_images_part3(data, img);
}

void	free_display(t_data *data, t_image *img)
{
	if (!data)
		return ;
	destroy_images(data, img);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	if (data->map)
		free_all(data->map, data->height);
}
