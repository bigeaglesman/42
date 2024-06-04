NAME = minishell
cc = cc
CFLAGS = -g 
RM = rm -rf

LIB_DIR = ./lib/

LIBFT_DIR = $(LIB_DIR)libft/
LIBFT = $(LIBFT_DIR)libft.a

LIBRARIES = -lft -lreadline -L$(LIBFT_DIR)

HEADERS_DIR = ./includes/

HEADERS_LIST = minishell.h
HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LIST))

INCLUDES = -I$(HEADERS_DIR) -I$(LIBFT_DIR)

SRC_DIR = ./sources/
SRCS_LIST = main.c\
		signal.c\
		terminal.c\
		error.c\
		cd.c\
		echo.c\
		env.c\
		export.c\
		pwd.c\
		unset.c\
		exit.c\

SRCS = $(addprefix $(SRC_DIR), $(SRCS_LIST))

OBJ_DIR = ./objects/
OBJ_LIST = $(SRCS_LIST:.c=.o)
OBJS = $(addprefix $(OBJ_DIR), $(OBJ_LIST))

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJ_DIR) $(OBJS)
	$(cc) $(CFLAGS) $(INCLUDES) $(LIBRARIES) $(OBJS) -o $(NAME)

$(OBJ_DIR) :
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(HEADERS)
	$(cc) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT) :
	make -C $(LIBFT_DIR)

clean : 
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJ_DIR)

fclean : clean
	$(RM) $(LIBFT)
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re