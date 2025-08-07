NAME= minitalk.a
SRCS= client.c server.c

COMP_LIB= ar rcs
RM= rm -f
CC= cc
CC_FLAGS= -Wall -Wextra -Werror

OBJS= $(SRCS:.c=.o)

%.o : %.c
	$(CC) $(CC_FLAGS) -c $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

$(NAME): $(OBJS)
	$(COMP_LIB) $(NAME) $(OBJS)

.PHONY: all clean fclean re
