NAME = cub3d

CC = gcc

#ADDITIONAL_FLAGS = -g -fsanitize=address

<<<<<<< HEAD
C_FLAGS = -Wall -Wextra -Werror -g
=======
C_FLAGS = 
>>>>>>> 1c5fe34fd7138cd1063357a9e72911771dc28555

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

FUNCTIONS =	projection/my_mlx_pixel_put.c\
			projection/get_player_position.c\
			projection/get_keys.c\
			projection/3d_projection.c\
			projection/moves/move_forward.c\
			projection/moves/move_left.c\
			projection/moves/move_right.c\
			projection/moves/move_backword.c\
			projection/destroy_window.c\
			map_parsing/check_textures_colors.c\
			map_parsing/rgb_to_hexa.c\
			map_parsing/checking_walls.c\
			map_parsing/check_map_utils.c\
			map_parsing/read_and_add.c\
			map_parsing/main.c\
			map_parsing/map_cheking.c\
			map_parsing/check_Path.c\
			libft/ft_strcmp.c\
			libft/ft_strlen.c\
			libft/ft_strncmp.c \
			libft/ft_strdup.c\
			libft/ft_strjoin.c\
			libft/ft_split.c\
			libft/ft_atoi.c\
			get_next_line/get_next_line.c\
			get_next_line/get_next_line_utils.c\
		
RM = rm -rf

all		:	$(NAME) 

$(NAME) : $(FUNCTIONS)
			$(CC) $(C_FLAGS)  $(FUNCTIONS) $(MLX_FLAGS) ./projection/cub3d.c -o $(NAME) 

clean	:	
			$(RM) $(NAME)
fclean	:	clean
		
re 		:	fclean all
