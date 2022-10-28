NAME = cub3d

CC = gcc

ADDITIONAL_FLAGS = -fsanitize=address -g 

C_FLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

FUNCTIONS =	projection/my_mlx_pixel_put.c\
			projection/get_player_position.c\
			projection/get_keys.c\
			projection/3d_projection.c\
			projection/set_directions.c\
			projection/images_xpm.c\
			projection/moves/move_forward.c\
			projection/moves/move_left.c\
			projection/moves/move_right.c\
			projection/moves/move_backword.c\
			projection/destroy_window.c\
			projection/textures.c\
			map_parssing/libft/ft_atoi.c\
			map_parssing/libft/ft_strnstr.c\
			map_parssing/libft/ft_calloc.c\
			map_parssing/libft/ft_strlen.c\
			map_parssing/libft/ft_strncmp.c\
			map_parssing/libft/ft_strjoin.c\
			map_parssing/libft/ft_strtrim.c\
			map_parssing/libft/ft_putchar_fd.c\
			map_parssing/libft/ft_putstr_fd.c\
			map_parssing/cub_utils.c\
			map_parssing/errors.c\
			map_parssing/textur.c\
			map_parssing/color.c\
			map_parssing/get_next_line_utils.c\
			map_parssing/parsing.c\
			map_parssing/get_next_line.c\
			map_parssing/read_map.c\
			map_parssing/check_maze.c\
			map_parssing/position.c\
		
RM = rm -rf

all		:	$(NAME) 

$(NAME) : $(FUNCTIONS)
			$(CC) $(C_FLAGS) $(FUNCTIONS) $(MLX_FLAGS) ./projection/cub3d.c -o $(NAME) 

clean	:	
			$(RM) $(NAME)
fclean	:	clean

run		: fclean all

			./cub3d ./maps/valid/map-no-0.cub
		
re 		:	fclean all
