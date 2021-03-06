NAME = ft_ls
MAKE = make
override G += 
FLAGS = -Wall -Wextra -Werror
SRCS = main.c
OBJS = $(SRCS:.c=.o)
LIBFT = ./libft/libft.a
all: $(NAME)

$(NAME): $(LIBFT)
	@gcc ./libft/libft.a $(SRCS) -g -o $(NAME)

g:
	@gcc -g $(SRCS) -o $(NAME)

test:
	@gcc test.c ./libft/libft.a
	@./a.out

clean:
	@$(MAKE) -C ./libft clean

fclean: clean
	@rm -f $(NAME)

re: fclean all

$(LIBFT):
	@$(MAKE) -C ./libft re

git:
	git add .
	git commit -am "$(G)"
	git push

rerun: re
	@./$(NAME)