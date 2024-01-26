SRCS = fdf.c\
		event.c\
		draw.c\

all : $(SRCS)
	gcc -Wextra -Werror -Wall -I./mlx -L./mlx -lmlx -framework OpenGL \
	-framework Appkit $(SRCS) -o fdf