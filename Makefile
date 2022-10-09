NAME = cub2d

CC = gcc

ADDITIONAL_FLAGS = -fsanitize=address

C_FLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

FUNCTIONS =	reading_map.c\
			map_filling.c\
			get_player_position.c\
			get_keys.c\
			projecting_rays.c\
			cast_rays.c\
			move_forward.c\
			move_left.c\
			move_right.c\
			move_backword.c\
			destroy_window.c\
			orbiay/check_textures_colors.c\
			orbiay/checking_walls.c\
			orbiay/ft_strcmp.c\
			orbiay/ft_strncmp.c \
			orbiay/ft_strdup.c\
			orbiay/ft_strjoin.c\
			orbiay/get_next_line.c\
			orbiay/get_next_line.c\
			orbiay/main.c\
			orbiay/ft_split.c\
		
OBJECTS = $(FUNCTIONS:.c=.o)

RM = rm -rf

all		:	$(OBJECTS)
			$(CC) $(C_FLAGS) $(MLX_FLAGS) $(OBJECTS) cub2d.c -o $(NAME)

clean	:	$(OBJECTS)
			$(RM) $(OBJECTS)

fclean :	clean
	$(RM) $(NAME)