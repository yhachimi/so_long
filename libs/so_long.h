/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachimi <yhachimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 11:25:38 by yhachimi          #+#    #+#             */
/*   Updated: 2026/02/13 17:16:02 by yhachimi         ###   ########.fr       */
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
typedef struct s_moves
{
	int		x;
	int		y;
	int		start[2];
	int		end;
}			t_moves;
typedef struct s_imags
{
	void	*r_wall;
	void	*c_wall;
	void	*re_wall;
	void	*ce_wall;
	void	*lc_wall;
	void	*lr_wall;
	void	*m_wall;
	void	*left_wall;
	void	*down_wall;
	void	*rd;
	void	*ru;
	void	*coin;
	void	*rl;
	void	*rr;
	void	*path;
	void	*portal;
}			t_image;
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
	void	*pd;
	int		coins_size;
	t_moves	moves;
	t_image	images;
}			t_data;
typedef struct s_size
{
	int		height;
	int		width;
}			t_size;
int			close_exit(t_data *data);
int			ft_strcmp(const char s1, const char *s2);
char		*ft_itoa(int n);
int			check_coins(t_data *data);
int			display_map(t_data *data, t_image *images);
void		set_moves(t_moves *moves, int row, int colm);
void		put_image(t_data *data, int x, int y);
void		*gen_image(char *img_path, t_data *data);
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
void		put_rect(t_data *data, void *img, int row, int colm);
void		free_display(t_data *data, t_image *img);
void		display_image(t_data *data, t_image *images, int row, int colm);
void		init_images(t_image *images, t_data *data);
void		put_all_chars(t_data *data);
#endif
