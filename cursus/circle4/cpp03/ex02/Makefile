# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/10 17:00:00 by ycho2             #+#    #+#              #
#    Updated: 2025/02/19 17:02:27 by ycho2            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C++ = c++
FLAG = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

SRC = ClapTrap.cpp\
	ScavTrap.cpp\
	FragTrap.cpp\
	main.cpp
HEADER = ClapTrap.hpp\
	FragTrap.hpp\
	ScavTrap.hpp

OBJ = $(SRC:.cpp=.o)
NAME = ex02

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
