/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachimi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 20:14:10 by yhachimi          #+#    #+#             */
/*   Updated: 2026/02/03 19:09:32 by yhachimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "get_next_line.h"
# include "unistd.h"
# include "fcntl.h"

char	**ft_split(char const *s, char c);
size_t	count(char const *s, char c);
typedef struct s_data
{
	void	*mlx_ptr;
	void	*data;
	void	*win_ptr;
	int		height;
	int		width;
	int		color;
}	t_data;

#endif
