SRCS=srcs/main.c srcs/parsing.c
OBJS=$(SRCS:.c=.o)
NAME=ft_nmap
FLAGS=-Wall -Wextra -Werror -g

all: $(NAME)

%.o: %.c
	@gcc $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@gcc $(FLAGS) $(OBJS) -o $(NAME)

clean:
	@rm -f $(OBJS)

fclean:
	@rm -f $(NAME) $(OBJS)

re: fclean all

.PHONY: all re clean fclean