# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/17 12:05:07 by ycho2             #+#    #+#              #
#    Updated: 2025/03/17 12:05:47 by ycho2            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C++ = c++
FLAG = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

SRC = main.cpp\
	Span.cpp

HEADER = Span.hpp

OBJ = $(SRC:.cpp=.o)
NAME = ex01

all: $(NAME)

$(NAME): $(OBJ)
	$(C++) $(FLAG) $(OBJ) -o $(NAME)
%.o: %.cpp %.hpp
	$(C++) $(FLAG) -c $< -o $@

clean :
	$(RM) $(OBJ)
fclean: clean
	$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re