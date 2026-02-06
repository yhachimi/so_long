/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachimi <yhachimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 11:25:38 by yhachimi          #+#    #+#             */
/*   Updated: 2026/02/06 12:02:59 by yhachimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "fcntl.h"
# include "get_next_line.h"
# include "unistd.h"

char		**ft_split(char const *s, char c);
size_t		count(char const *s, char c);

typedef struct s_data
{
	void	*mlx_ptr;
	void	*data;
	char	**map;
	void	*win_ptr;
	int		fd;
	int		height;
	int		width;
	int		color;
}			t_data;
typedef struct s_size
{
	int		height;
	int		width;
}			t_size;

void		flood_fill(char **map, int x, int y, t_size size);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putend(char *s, int fd);
void		*free_all(char **p, size_t len);
int			check_map_boarder(char **map, int height, int width);
int			check_the_map_chars(int e, int c, char **map, int height);
char		*read_map(int fd);
int			check_valid_path(char **map, int h, int w);

#endif
