SRCS = fdf.c\
		event.c\
		draw.c\
		mat_utils.c\
		utils.c\
		validity.c\

all : $(SRCS)
	gcc -g -Wextra -Werror -Wall -I./mlx -L./mlx -lmlx -framework OpenGL \
	-framework Appkit $(SRCS) -o fdf