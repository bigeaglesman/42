TARGET = push_swap
cc = cc
CFLAGS = -g -Wall -Werror -Wextra
RM = rm -rf

LIB_DIR= ./lib/
LIBFT_DIR = $(LIB_DIR)libft/
LIBFT = $(LIBFT_DIR)libft.a
LIBRARIES = -lft -L$(LIBFT_DIR)

HEADERS_DIR = ./includes/

HEADERS_LIST_MAND = push_swap.h
HEADERS_MAND = $(addprefix $(HEADERS_DIR), $(HEADERS_LIST_MAND))

# HEADERS_LIST_BONUS = push_swap_bonus.h	
# HEADERS_BONUS = $(addprefix $(HEADERS_DIR), $(HEADERS_LIST_BONUS))

INCLUDES = -I$(HEADERS_DIR) -I$(LIBFT_DIR)

SRC_DIR_MAND = ./sources/mand/
SRCS_LIST_MAND = com_push_swap.c\
			com_reverse.c\
			com_rotate.c\
			sort_hardcoding.c\
			sort_n.c\
			sort_optimize.c\
			push_swap.c
SRCS_MAND = $(addprefix $(SRC_DIR_MAND), $(SRCS_LIST_MAND))

# SRC_DIR_BONUS = ./sources/bonus/
# SRCS_LIST_BONUS = error_bonus.c\
# 			get_next_line_utils_bonus.c\
# 			get_next_line_bonus.c\
# 			pipex_here_doc_bonus.c\
# 			pipex_parsing_bonus.c\
# 			pipex_bonus.c
# SRCS_BONUS = $(addprefix $(SRC_DIR_BONUS), $(SRCS_LIST_BONUS))

OBJ_DIR = ./objects/

OBJ_DIR_MAND = ./objects/mand/
OBJ_LIST_MAND = $(SRCS_LIST_MAND:.c=.o)
OBJS_MAND = $(addprefix $(OBJ_DIR_MAND), $(OBJ_LIST_MAND))

# OBJ_DIR_BONUS = ./objects/bonus/
# OBJ_LIST_BONUS = $(SRCS_LIST_BONUS:.c=.o)
# OBJS_BONUS = $(addprefix $(OBJ_DIR_BONUS), $(OBJ_LIST_BONUS))

all : push_swap_mandatory
# bonus : push_swap_bonus

push_swap_mandatory : $(LIBFT) $(OBJ_DIR_MAND) $(OBJS_MAND)
	$(cc) $(CFLAGS) $(INCLUDES) $(LIBRARIES) $(OBJS_MAND) -o $(TARGET)
	touch $@

# push_swap_bonus : $(LIBFT) $(OBJ_DIR_BONUS) $(OBJS_BONUS)
# 	$(cc) $(CFLAGS) $(INCLUDES) $(LIBRARIES) $(OBJS_BONUS) -o $(TARGET)
# 	touch $@

$(OBJ_DIR_MAND) :
	mkdir -p $(OBJ_DIR_MAND)

$(OBJ_DIR_MAND)%.o : $(SRC_DIR_MAND)%.c $(HEADERS_MAND)
	$(cc) $(CFLAGS) $(INCLUDES) -c $< -o $@

# $(OBJ_DIR_BONUS) :
# 	mkdir -p $(OBJ_DIR_BONUS)

# $(OBJ_DIR_BONUS)%.o : $(SRC_DIR_BONUS)%.c $(HEADERS_BONUS)
# 	$(cc) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT) :
	make -C $(LIBFT_DIR)

clean :
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJ_DIR)
	$(RM) pipex_mandatory
# $(RM) pipex_bonus

fclean : clean
	$(RM) $(LIBFT)
	$(RM) $(TARGET)

re : fclean all

.PHONY: all clean fclean re