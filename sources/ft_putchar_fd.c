/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachimi <yhachimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 12:00:50 by yhachimi          #+#    #+#             */
/*   Updated: 2026/02/13 17:15:10 by yhachimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

int	close_exit(t_data *data)
{
	free_display(data, &data->images);
	mlx_loop_end(data->mlx_ptr);
	exit(0);
	return (0);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
