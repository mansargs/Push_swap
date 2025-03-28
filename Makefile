TARGET = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

SOURCE  = $(shell find ./mandatory/ -name "*.c")
OBJ     = $(SOURCE:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(TARGET)

re: fclean all

.PHONY: all re clean fclean

