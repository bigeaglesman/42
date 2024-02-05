NAME = fdf
cc = gcc
CFLAGS = -g -Wall -Werror -Wextra
RM = rm -rf

LIB_DIR = ./lib/

LIBFT_DIR = $(LIB_DIR)libft/
LIBFT = $(LIBFT_DIR)libft.a

MLX_DIR = $(LIB_DIR)mlx/
MLX = $(MLX_DIR)libmlx.a

LIBRARIES = -lmlx -lft -L$(MLX_DIR) -L$(LIBFT_DIR) \
	-framework OpenGL -framework Appkit

HEADERS_DIR = ./includes/
HEADERS_LIST = mac_key.h\
				fdf.h
HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LIST))

INCLUDES = -I$(HEADERS_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)

SRC_DIR = ./sources/
SRCS_LIST = fdf.c\
		event.c\
		draw.c\
		mat_utils.c\
		utils.c\
		parsing.c\
		get_next_line.c\
		get_next_line_utils.c
SRCS = $(addprefix $(SRC_DIR), $(SRCS_LIST))

OBJ_DIR = ./objects/
OBJ_LIST = $(SRCS_LIST:.c=.o)
OBJS = $(addprefix $(OBJ_DIR), $(OBJ_LIST))

all : $(NAME)

$(NAME) : $(LIBFT) $(MLX) $(OBJ_DIR) $(OBJS)
	$(cc) $(CFLAGS) $(INCLUDES) $(LIBRARIES) $(OBJECTS) -o $(NAME)

$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(HEADERS)
	$(cc) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT) :
	make -C $(LIBFT_DIR)

$(MLX) :
	make -C $(MLX_DIR)

clean : 
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean
	$(RM) $(OBJ_DIR)

fclean : clean
	$(RM) $(LIBFT)
	$(RM) $(MLX)
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re