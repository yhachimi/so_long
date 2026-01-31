/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachimi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 20:14:10 by yhachimi          #+#    #+#             */
/*   Updated: 2026/01/31 20:20:04 by yhachimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"

typedef struct s_data
{
	void 	*mlx_ptr;
	void	*data;
	void	*win_ptr;
	int		height;
	int		width;
	int		color;
} t_data;

#endif
