CC		= cc
CFLAGS	= -Wall -Wextra -Werror
SRC	= srcs
SRCS	= $(SRC)/iroiro.c $(SRC)/main.c $(SRC)/read.c $(SRC)/test2.c
TARGET	= rush-02
OBJS	= $(SRCS:$(SRC)/%.c=$(SRC)/%.o)

all : $(SRC)/%.c
	$(CC) $(CFLAGS) -I includes -o $(TARGET)

fclean:
	rm -f $(TARGET)
