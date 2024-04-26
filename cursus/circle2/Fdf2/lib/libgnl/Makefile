CC = cc
CFLAGS = -c -Wall -Werror -Wextra
TARGET = libgnl.a

SOURCES =	get_next_line.c\
			get_next_line_utils.c

OBJECTS = $(SOURCES:.c=.o)

all : $(TARGET)

%.o : %.c
	$(CC) $(CFLAGS) $< -o $@

$(TARGET) : $(OBJECTS)
	ar cr $@ $^

clean :
	rm -f $(OBJECTS)

fclean : clean
	rm -f $(TARGET)

re : fclean all

.PHONY : all clean fclaen re