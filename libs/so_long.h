/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachimi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 20:14:10 by yhachimi          #+#    #+#             */
/*   Updated: 2026/02/04 19:08:23 by yhachimi         ###   ########.fr       */
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
void	flood_fill(char	**map, int x, int y, t_size size);
void	*free_all(char **p, size_t len);
int		check_map_boarder(char **map, int height, int width);
char	*read_map(int fd);
typedef struct s_data
{
	void	*mlx_ptr;
	void	*data;
	void	*win_ptr;
	int		height;
	int		width;
	int		color;
}	t_data;
typedef struct s_size
{
	int	hight;
	int	width;
}	t_size;
#endif
