NAME = cub2d

CC = gcc

CFLAGS = -Wall -Werror -Wextra

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

FUNCTIONS = get_next_line/get_next_line.c\
			get_next_line/get_next_line_utils.c\
			libft/ft_split.c\
			libft/ft_strdup.c\
			libft/ft_strjoin.c\
			libft/ft_strlcpy.c\
			libft/ft_strlen.c\
			libft/ft_substr.c\

RM = -rm -rf

OBJECTS = $(FUNCTIONS:.c=.o)

all = $(NAME)

$(NAME) : $(OBJECTS)
		$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJECTS) cub2d.c -o $(NAME)

clean :
		$(RM) $(OBJECTS)

fclean : clean
		$(RM) $(OBJECTS) $(NAME)

re : fclean all