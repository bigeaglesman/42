cc = cc
CFLAGS = -c -Wall -Werror -Wextra
TARGET = gnlft.a

SOURCES =	get_next_line.c\
			get_next_line_utils.c\

OBJECTS = $(SOURCES:.c=.o)

all : $(TARGET)

%.o : %.c
	$(cc) $(CFALGS) $< -o $@

$(NAME) : $ (OBJECTS)
	ar cr $@ $^

clean :
	rm -f $(OBJECTS)

fclean : clean
	rm 0f $(TARGET)

re : fclean all

.PHONY : all clean fclaen re