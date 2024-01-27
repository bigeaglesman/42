CC = cc
CFLAGS = -c -Wall -Werror -Wextra
NAME = libftprintf.a
LIBFTDIR = libft
LIBFT = libft.a
HEADER = ft_printf.h

SOURCES =	ft_printf.c\
			ft_printf_utils.c\
			ft_printf_utils2.c\
			ft_printf_utils3.c\

OBJECTS = $(SOURCES:.c=.o)

all : $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) $< -o $@

$(NAME) : $(OBJECTS)
	$(MAKE) -C $(LIBFTDIR)
	cp ./$(LIBFTDIR)/$(LIBFT) $@
	ar rcs $@ $^

clean :
	$(MAKE) clean -C $(LIBFTDIR)
	rm -f $(OBJECTS)

fclean : clean
	$(MAKE) fclean -C $(LIBFTDIR)
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re