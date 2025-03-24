TARGET = pushswap.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

AR      = ar
ARFLAGS = -rcs
RM = rm -rf

SOURCE  = $(shell find . -name "*.c")
OBJ     = $(SOURCE:.c=.o)
INCLUDE = push_swap.h

all : $(TARGET)


$(TARGET) : $(OBJ)
	$(AR) $(ARFLAGS) $(TARGET) $(OBJ)

%.o : %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(TARGET)

re : fclean all

.PHONY : all re clean fclean
