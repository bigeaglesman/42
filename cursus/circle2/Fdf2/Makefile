NAME = fdf
cc = cc
CFLAGS = -g -Wall -Werror -Wextra
RM = rm -rf

LIB_DIR = ./lib/

LIBFT_DIR = $(LIB_DIR)libft/
LIBFT = $(LIBFT_DIR)libft.a

LIBGNL_DIR = $(LIB_DIR)libgnl/
LIBGNL = $(LIBGNL_DIR)libgnl.a

MLX_DIR = $(LIB_DIR)mlx/
MLX = $(MLX_DIR)libmlx.dylib

LIBRARIES = -lmlx -lft -lgnl -L$(MLX_DIR) -L$(LIBFT_DIR) -L$(LIBGNL_DIR) \
	-framework OpenGL -framework Appkit

HEADERS_DIR = ./includes/

HEADERS_LIST = mac_key.h\
				fdf.h
HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LIST))

INCLUDES = -I$(HEADERS_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR) -I$(LIBGNL_DIR)

SRC_DIR = ./sources/
SRCS_LIST = fdf.c\
		main.c\
		event.c\
		draw_line.c\
		draw_asc_desc.c\
		error.c\
		file_check.c\
		mat_utils.c\
		utils.c\
		parsing.c\
		# trans_coord.c\


SRCS = $(addprefix $(SRC_DIR), $(SRCS_LIST))

OBJ_DIR = ./objects/
OBJ_LIST = $(SRCS_LIST:.c=.o)
OBJS = $(addprefix $(OBJ_DIR), $(OBJ_LIST))

all : $(NAME)

$(NAME) : $(LIBFT) $(MLX) $(LIBGNL) $(OBJ_DIR) $(OBJS)
	$(cc) $(CFLAGS) $(INCLUDES) $(LIBRARIES) $(OBJS) -o $(NAME)

$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(HEADERS)
	$(cc) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT) :
	make -C $(LIBFT_DIR)

$(MLX) :
	make -C $(MLX_DIR)

$(LIBGNL) :
	make -C $(LIBGNL_DIR)

clean : 
	make -C $(LIBFT_DIR) clean
	make -C $(LIBGNL_DIR) clean
	make -C $(MLX_DIR) clean
	$(RM) $(OBJ_DIR)

fclean : clean
	$(RM) $(LIBFT)
	$(RM) $(LIBGNL)
	$(RM) $(MLX)
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re