NAME = pipex
cc = gcc
CFLAGS = -g -Wall -Werror -Wextra
RM = rm -rf

LIB_DIR= ./lib/
LIBFT_DIR = $(LIB_DIR)libft/
LIBFT = $(LIBFT_DIR)libft.a
LIBRARIES = -lft -L$(LIBFT_DIR)

HEADERS_DIR = ./includes/
HEADERS_LIST = pipex.h\
				ft_printf.h\
				get_next_line.h
HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LIST))

INCLUDES = -I$(HEADERS_DIR) -I$(LIBFT_DIR)

SRC_DIR = ./sources/
SRCS_LIST = pipex.c\
			pipex_pipe.c\
			pipex_parsing.c\
			pipex_pipe.c\
			pipex_here_doc.c\
			error.c\
			ft_printf_utils.c\
			ft_printf_utils2.c\
			ft_printf_utils3.c\
			ft_printf.c\
			get_next_line_utils.c\
			get_next_line.c

SRCS = $(addprefix $(SRC_DIR), $(SRCS_LIST))

OBJ_DIR = ./objects/
OBJ_LIST = $(SRCS_LIST:.c=.o)
OBJS = $(addprefix $(OBJ_DIR), $(OBJ_LIST))

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJ_DIR) $(OBJS)
	$(cc) $(CFLAGS) $(INCLUDES) $(LIBRARIES) $(OBJS) -o $(NAME)

$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)

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