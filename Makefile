NAME = cub2d

CC = gcc

ADDITIONAL_FLAGS = -fsanitize=address

C_FLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

FUNCTIONS =	get_next_line/get_next_line.c\
			get_next_line/get_next_line_utils.c\
			reading_map.c\
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
			libft/ft_split.c\
			libft/ft_strdup.c\
			libft/ft_strjoin.c\
			libft/ft_strlcpy.c\
			libft/ft_strlen.c\
			libft/ft_substr.c\
			libft/ft_strncmp.c\
			libft/ft_free.c\
		
OBJECTS = $(FUNCTIONS:.c=.o)

RM = rm -rf

all		:	$(OBJECTS)
			$(CC) $(C_FLAGS) $(MLX_FLAGS) $(OBJECTS) cub2d.c -o $(NAME)

clean	:	$(OBJECTS)
			$(RM) $(OBJECTS)

fclean :	clean
	$(RM) $(NAME)