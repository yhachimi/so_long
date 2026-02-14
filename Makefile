CFLAGS = -Wall -Wextra -Werror
NAME = so_long
BONUS_SRC =  bonus_s/so_long_bonus.c bonus_s/check_bonus.c bonus_s/display_bonus.c bonus_s/display_enemy_bonus.c bonus_s/flood_fill_bonus.c bonus_s/free_display_bonus.c bonus_s/ft_itoa_bonus.c bonus_s/ft_putchar_fd_bonus.c bonus_s/ft_putendl_fd_bonus.c bonus_s/ft_putstr_fd_bonus.c bonus_s/ft_split_bonus.c bonus_s/ft_strcmp_bonus.c bonus_s/gen_image_ptr_bonus.c bonus_s/get_next_line_bonus.c bonus_s/get_next_line_utils_bonus.c bonus_s/init_image_bonus.c bonus_s/put_chrs_bonus.c bonus_s/read_map_bonus.c

SRC = sources/so_long.c  sources/display.c sources/flood_fill.c sources/ft_putchar_fd.c sources/ft_putendl_fd.c sources/ft_putstr_fd.c sources/ft_split.c sources/get_next_line.c sources/get_next_line_utils.c sources/read_map.c sources/gen_image_ptr.c sources/put_chrs.c sources/ft_itoa.c sources/free_display.c sources/init_image.c sources/ft_strcmp.c
OBJ = $(SRC:.c=.o)
BONUS_OBJS:= $(BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) libs/so_long.h
	@cc $(OBJ) $(CFLAGS) -L/usr/include/minilibx-linux/ -lmlx -lXext -lX11 -o $(NAME)

%.o : %.c
	@cc $(CFLAGS) -c $< -o $@

bonus: $(BONUS_OBJS) libs/so_long_bonus.h
	@touch bonus
	@cc $(CFLAGS) $(BONUS_OBJS)  -L/usr/include/minilibx-linux/ -lmlx -lXext -lX11 -o $(NAME)

clean:
	@rm -rf $(OBJ) $(BONUS_OBJS)

fclean: clean
	@rm -rf $(NAME) bonus

re: fclean all
.PHONY : clean
.SECONDARY: $(OBJ)
