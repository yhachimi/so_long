/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_enemy_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachimi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 14:15:54 by yhachimi          #+#    #+#             */
/*   Updated: 2026/02/14 13:41:20 by yhachimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long_bonus.h"

void	enemy_attack(t_data *data, int count, int row, int colm)
{
	static int	i;
	int			s;

	s = 0;
	if (i == count)
		i = 0;
	while (s < 451211211)
		s++;
	put_rect(data, data->images.atack[i], row, colm);
	i += 1;
}

void	enemy_show(t_data *data, int count, int row, int colm)
{
	static int	i;
	long		c;

	if (i == count)
		i = 0;
	c = 0;
	while (c < 451212111)
		c++;
	put_rect(data, data->images.enemy[i], row, colm);
	i += 1;
}

int	srearch_enemy(t_data *data)
{
	int	row;
	int	colm;

	row = 0;
	colm = 0;
	while (row < data->height)
	{
		colm = 0;
		while (data->map[row][colm])
		{
			if (data->map[row][colm] == 'M' && data->typ != 'A')
				enemy_show(data, 4, row, colm);
			else if (data->map[row][colm] == 'M' && data->typ == 'A')
				enemy_attack(data, 4, row, colm);
			colm++;
		}
		row++;
	}
	return (0);
}
