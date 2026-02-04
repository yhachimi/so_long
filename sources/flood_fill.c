/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachimi <hachimiyounes1337@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 19:12:35 by yhachimi          #+#    #+#             */
/*   Updated: 2026/02/04 19:12:36 by yhachimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	flood_fill(char **map, int x, int y, t_size size)
{
	if ((x < 0 || y < 0) || (x > size.height || y > size.width))
		return ;
	if (map[x][y] == 'V' || map[x][y] == '1')
		return ;
	map[x][y] = 'V';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}
