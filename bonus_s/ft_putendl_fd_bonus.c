/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachimi <yhachimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 11:53:30 by yhachimi          #+#    #+#             */
/*   Updated: 2026/02/11 18:38:07 by yhachimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long_bonus.h"

int	check_coins(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	data->coins_size = 0;
	while (x < data->height)
	{
		y = 0;
		while (data->map[x][y])
		{
			if (data->map[x][y] == 'C')
			{
				data->coins_size += 1;
			}
			y++;
		}
		x++;
	}
	if (data->coins_size == 0)
		return (0);
	return (1);
}

void	ft_putend(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
