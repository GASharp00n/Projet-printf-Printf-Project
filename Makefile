CC = clang

NAME = printf.a

CFLAGS = -Wall -Wextra -Werror -Iinclude

SRCS = src/dprintf.c \
       src/run_format.c \
	   src/strlen_token.c \
       src/print_char.c \
       src/print_string.c \
       src/print_int.c \
       src/printbase_16.c \
       src/printbase_16_int.c \
       src/printbase_8.c \
       src/printbase_2.c \
       src/print_ptr.c

TEST = test/dprintf.c \
	   test/strlen_token.c

OBJS = $(SRCS:.c=.o)

OBJS_TEST = $(TEST:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME) : $(OBJS)
	ar rc printf.a $(OBJS)

ut.out: $(OBJS) $(OBJS_TEST)
	$(CC) $(OBJS) $(OBJS_TEST) -lcriterion -o ut.out

clean:
	rm -f $(OBJS) $(OBJS_TEST) *.o

fclean: clean
	rm -f printf.a ut.out

re: fclean all
