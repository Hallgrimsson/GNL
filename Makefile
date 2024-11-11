CC = cc
CFLAGS = -Wall -Werror -Wextra -I.
BUF = -D BUFFER_SIZE=128
SRC = get_next_line.c get_next_line_utils.c
NAME = GNL.o
OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	ld -r -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) $(BUF) -c $^ -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re