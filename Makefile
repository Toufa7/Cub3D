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
			projection/textures.c\
			projection/moves/move_forward.c\
			projection/moves/move_left.c\
			projection/moves/move_right.c\
			projection/moves/move_backword.c\
			projection/destroy_window.c\
			# Put your function down here\
			map_parsing/..\
			# that set \
		
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
