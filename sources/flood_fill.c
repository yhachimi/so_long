/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachimi <yhachimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 11:24:23 by yhachimi          #+#    #+#             */
/*   Updated: 2026/02/10 14:56:52 by yhachimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libs/so_long.h"

void	set_moves(t_moves *moves, int row, int colm)
{
	moves->start[0] = row;
	moves->start[1] = colm;
}

void	flood_fill(char **map, int x, int y, t_size size)
{
	if ((x < 0 || y < 0) || (x > size.height || y > size.width))
		return ;
	if (map[x][y] == 'V' || map[x][y] == '1')
		return ;
	map[x][y] = 'V';
	flood_fill(map, (x + 1), y, size);
	flood_fill(map, (x - 1), y, size);
	flood_fill(map, x, (y + 1), size);
	flood_fill(map, x, (y - 1), size);
}
