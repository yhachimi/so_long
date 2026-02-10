#minilibx-linux
Name = so_long
SRC = sources/so_long.c  sources/display.c sources/flood_fill.c sources/ft_putchar_fd.c sources/ft_putendl_fd.c sources/ft_putstr_fd.c sources/ft_split.c sources/get_next_line.c sources/get_next_line_utils.c sources/read_map.c

all:
	cc $(SRC) -Lminilibx-linux -lmlx -lXext -lX11
