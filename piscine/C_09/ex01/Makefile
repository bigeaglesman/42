CC = cc
CFLAGS = -c -Wall -Werror -Wextra
TARGET = libft.a

SRCDIR = srcs
INCDIR = includes

SOURCES = $(SRCDIR)/ft_putchar.c $(SRCDIR)/ft_swap.c $(SRCDIR)/ft_putstr.c $(SRCDIR)/ft_strlen.c $(SRCDIR)/ft_strcmp.c

OBJECTS = $(SOURCES:.c=.o)

all : $(TARGET)

%.o : %.c
	$(CC) $(CFLAGS) $< -o $@ -I$(INCDIR)

$(TARGET) : $(OBJECTS)
	ar cr $@ $^

clean :
	rm -f $(OBJECTS)

fclean : clean
	rm -f $(TARGET)

re : fclean all

.PHONY: all clean fclean re
