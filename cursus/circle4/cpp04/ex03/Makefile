# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/24 22:47:07 by ycho2             #+#    #+#              #
#    Updated: 2025/02/22 21:57:14 by ycho2            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C++ = c++
FLAG = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

SRC = AMateria.cpp\
	Character.cpp\
	Cure.cpp\
	Ice.cpp\
	MateriaSource.cpp\
	main.cpp

HEADER = AMateria.hpp\
		Character.hpp\
		Cure.hpp\
		Ice.hpp\
		MateriaSource.hpp

IHEADER = Debug.hpp\
		IMateriaSource.hpp\
		ICharacter.hpp

OBJ = $(SRC:.cpp=.o)
NAME = ex03

all: $(NAME)

$(NAME): $(OBJ) $(IHEADER)
	$(C++) $(FLAG) $(OBJ) -o $(NAME)
%.o: %.cpp %.hpp
	$(C++) $(FLAG) -c $< -o $@

clean :
	$(RM) $(OBJ)
fclean: clean
	$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re
