/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachimi <hachimiyounes1337@gmail.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 19:05:00 by yhachimi          #+#    #+#             */
/*   Updated: 2026/02/04 11:49:28 by yhachimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

int	main(void)
{
	char	*str;
	char	**map;
	int		fd;
	size_t	height;
	size_t	width;

	fd = open("../maps/map1.ber", O_RDONLY);
	str = read_map(fd);
	height = count(str, '\n');
	map = ft_split(str, '\n');
	width = 0;
	while (map[0][width])
		width++;
	if (!check_map_boarder(map, height, width))
	{
		free_all(map, height);
		free(str);
		close(fd);
		return (1);
	}
	free(str);
	free_all(map, height);
	close(fd);
	return (0);
}
