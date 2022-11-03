NAME = cub3d

CC = gcc

ADDITIONAL_FLAGS = -fsanitize=address -g 

C_FLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

FUNCTIONS =	projection/my_mlx_pixel_put.c\
			projection/get_player_position.c\
			projection/get_keys.c\
			projection/3d_projection.c\
			projection/3d_projection_utils.c\
			projection/set_directions.c\
			projection/images_xpm.c\
			projection/moves/move_forward.c\
			projection/moves/move_left.c\
			projection/moves/move_right.c\
			projection/moves/move_backword.c\
			projection/destroy_window.c\
			projection/textures.c\
			map_parsing/libft/ft_atoi.c\
			map_parsing/libft/ft_strnstr.c\
			map_parsing/libft/ft_calloc.c\
			map_parsing/libft/ft_strlen.c\
			map_parsing/libft/ft_strncmp.c\
			map_parsing/libft/ft_strjoin.c\
			map_parsing/libft/ft_strtrim.c\
			map_parsing/libft/ft_putchar_fd.c\
			map_parsing/libft/ft_putstr_fd.c\
			map_parsing/cub_utils.c\
			map_parsing/errors.c\
			map_parsing/textur.c\
			map_parsing/color.c\
			map_parsing/get_next_line_utils.c\
			map_parsing/parsing.c\
			map_parsing/get_next_line.c\
			map_parsing/read_map.c\
			map_parsing/check_maze.c\
			map_parsing/position.c\
		
RM = rm -rf

all		:	$(NAME) 

$(NAME) : $(FUNCTIONS)
			$(CC) $(C_FLAGS) $(FUNCTIONS) $(MLX_FLAGS) ./projection/cub3d.c -o $(NAME) 

clean	:	
			$(RM) $(NAME)
fclean	:	clean

re 		:	fclean all
