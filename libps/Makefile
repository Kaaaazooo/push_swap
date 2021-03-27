# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sabrugie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/10 19:12:22 by sabrugie          #+#    #+#              #
#    Updated: 2021/03/27 18:52:51 by sabrugie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libps.a
CC = gcc

HEADER = .

OPTIONS = -I $(HEADER)
CFLAGS = -Wall -Werror -Wextra $(OPTIONS)

SRCS = push.c swap.c rotate.c stack_add_front.c \
	ilst_free_all.c ilst_is_sorted.c ilst_count_sorted.c ilst_get.c \
	sort_array.c check_duplicates.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(LDFLAGS) $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
