/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachimi <yhachimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 11:23:26 by yhachimi          #+#    #+#             */
/*   Updated: 2026/02/06 11:29:46 by yhachimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

int	free_exit(t_data data, char *str, int status)
{
	free(str);
	free_all(data.map, data.height);
	close(data.fd);
	return (status);
}

int	main(void)
{
	t_data	data;
	char	*str;

	data.fd = open("../maps/map1.ber", O_RDONLY);
	str = read_map(data.fd);
	if (!str)
		return (close(data.fd), 1);
	data.height = count(str, '\n');
	data.map = ft_split(str, '\n');
	if (!data.map)
		return ((close(data.fd), free(str), 1));
	data.width = 0;
	while (data.map[0][data.width])
		data.width++;
	if (!check_map_boarder(data.map, data.height, data.width)
		|| !check_the_map_chars(0, 0, data.map, data.height)
		|| !check_valid_path(data.map, data.height, data.width))
		return (free_exit(data, str, 1));
	return (free_exit(data, str, 0));
}
