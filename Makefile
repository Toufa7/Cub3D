NAME = cub2d

CC = gcc

ADDITIONAL_FLAGS = -fsanitize=address

C_FLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

FUNCTION =	get_next_line/get_next_line.c\
			get_next_line/get_next_line_utils.c\
			libft/ft_split.c\
			libft/ft_strdup.c\
			libft/ft_strjoin.c\
			libft/ft_strlcpy.c\
			libft/ft_strlen.c\
			libft/ft_substr.c\
			libft/ft_strncmp.c\
			libft/ft_free.c\
		
OBJECTS = $(FUNCTION:.c=.o)

RM = rm -rf

all		:	$(OBJECTS)
			$(CC) $(C_FLAGS) $(MLX_FLAGS) $(OBJECTS) cub2d.c -o $(NAME)

clean	:	$(OBJECTS)
			$(RM) $(OBJECTS) $(NAME)