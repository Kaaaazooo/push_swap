NAME = push_swap

LIBFT_P = ../libft
LIBPS_P = ../libps
UTILS_P = ../utils
HEADER = includes

OPTIONS = -I $(LIBFT_P)/includes -I $(LIBPS_P)/. -I $(UTILS_P) -I .
CFLAGS = -Wall -Werror -Wextra $(OPTIONS)
LDFLAGS = -L $(LIBFT_P) -lft -L $(LIBPS_P) -lps

SRCS = $(addprefix ./, main.c)
UTILS = $(addprefix ../utils/, utils.c print_ilst.c)

CC = gcc

all: $(NAME)

OBJS = $(SRCS:.c=.o)
UTILS_OBJS = $(UTILS:.c=.o)

$(NAME): $(OBJS) $(UTILS_OBJS)
	make -C $(LIBFT_P)
	make -C $(LIBPS_P)
	$(CC) $(CFLAGS) -o ./$(NAME) $(OBJS) $(UTILS_OBJS) $(LDFLAGS)

clean:
	make -C $(LIBFT_P) clean
	make -C $(LIBPS_P) clean
	rm -rf $(OBJS) $(UTILS_OBJS)

fclean: clean
	rm -rf $(LIBFT_P)/libft.a
	rm -rf $(LIBPS_P)/libps.a
	rm -rf $(NAME)

re: fclean all
