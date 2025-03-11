# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/10 17:00:00 by ycho2             #+#    #+#              #
#    Updated: 2025/02/20 10:12:01 by ycho2            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C++ = c++
FLAG = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

SRC = Animal.cpp\
	Dog.cpp\
	Cat.cpp\
	WrongAnimal.cpp\
	WrongCat.cpp\
	Brain.cpp\
	main.cpp
HEADER = Animal.hpp\
	Dog.hpp\
	Cat.hpp\
	WrongAnimal.hpp\
	WrongCat.hpp\
	Brain.hpp\
	main.hpp

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
