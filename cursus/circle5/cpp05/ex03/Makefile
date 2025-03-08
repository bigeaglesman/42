# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/23 00:04:47 by ycho2             #+#    #+#              #
#    Updated: 2025/03/08 02:40:12 by ycho2            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C++ = c++
FLAG = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

SRC = main.cpp\
	Bureaucrat.cpp\
	AForm.cpp\
	ShrubberyCreationForm.cpp\
	RobotomyRequestForm.cpp\
	PresidentialPardonForm.cpp\
	Intern.cpp
HEADER = Bureaucrat.hpp\
	AForm.hpp\
	ShrubberyCreationForm.hpp\
	RobotomyRequestForm.hpp\
	PresidentialPardonForm.hpp\
	Intern.hpp

OBJ = $(SRC:.cpp=.o)
NAME = ex03

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