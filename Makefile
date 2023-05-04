NAME	= philo
CC		= cc
CFLAGS 	= -Wall -Wextra -Werror

SRCS =	philo.c\
		utils.c\
		ft_init.c\
		ft_start.c\

all: $(NAME)

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "make it"

clean:
	@rm -f $(OBJS)
	@echo "clean"

fclean: clean
	@rm -f $(NAME)
	@echo "fclean"

re: fclean $(NAME)

.PHONY: clean fclean re all