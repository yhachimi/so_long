/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachimi <yhachimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 11:25:38 by yhachimi          #+#    #+#             */
/*   Updated: 2026/02/10 16:19:56 by yhachimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../minilibx-linux/mlx.h"
# include "fcntl.h"
# include "get_next_line.h"
# include "stdio.h"
# include "unistd.h"

char		**ft_split(char const *s, char c);
size_t		count(char const *s, char c);
typedef struct s_moves
{
	int		x;
	int		y;
	int		start[2];
	int		end;
}			t_moves;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*data;
	int		win_height;
	int		win_width;
	int		bordr;
	int		cell_size;
	char	**map;
	char	*path;
	void	*win_ptr;
	void	*img_ptr;
	int		fd;
	int		height;
	int		width;
}			t_data;
typedef struct s_size
{
	int		height;
	int		width;
}			t_size;
char		*ft_itoa(int n);
void		set_moves(t_moves *moves, int row, int colm);
void		put_image(t_data *data, int x, int y);
void		gen_image(char *img_path, t_data *data);
void		flood_fill(char **map, int x, int y, t_size size);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putend(char *s, int fd);
void		*free_all(char **p, size_t len);
int			check_map_boarder(char **map, int height, int width);
int			check_the_map_chars(int e, int c, char **map, int height);
char		*read_map(int fd);
int			display_moves(t_data *data, int moves);
int			check_valid_path(char **map, int h, int w, t_moves *moves);
void		display(t_data *data, t_moves *moves);
#endif
