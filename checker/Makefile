NAME = checker

LIBFT_P = ../libft
LIBPS_P = ../libps
HEADER = includes

OPTIONS = -I $(LIBFT_P)/includes -I $(LIBPS_P)/. -I .
CFLAGS = -Wall -Werror -Wextra $(OPTIONS)
LDFLAGS = -L $(LIBFT_P) -lft -L $(LIBPS_P) -lps

SRCS = $(addprefix ./, main.c print_stack.c)

CC = gcc

all: $(NAME)

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	make -C $(LIBFT_P)
	make -C $(LIBPS_P)
	$(CC) $(CFLAGS) -o ./checker $(OBJS) $(LDFLAGS)

clean:
	make -C $(LIBFT_P) clean
	make -C $(LIBPS_P) clean
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(LIBFT_P)/libft.a
	rm -rf $(LIBPS_P)/libps.a
	rm -rf $(NAME)

re: fclean all
