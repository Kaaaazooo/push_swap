# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sabrugie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/10 19:12:22 by sabrugie          #+#    #+#              #
#    Updated: 2020/02/23 10:44:25 by sabrugie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libps.a
CC = gcc

HEADER = .

OPTIONS = -I $(HEADER)
CFLAGS = -Wall -Werror -Wextra $(OPTIONS)

SRCS = push.c swap.c rotate.c stack_add_front.c stack_free_all.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(LDFLAGS) $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
