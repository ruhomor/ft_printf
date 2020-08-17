# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kachiote <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/03 14:53:22 by kachiote          #+#    #+#              #
#    Updated: 2020/07/03 14:53:28 by kachiote         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = ft_printf

CFILES = ft_printf \
		main

SRCS = $(patsubst %, %.c, $(CFILES))

OUT = $(patsubst %, %.o, $(CFILES))

INCL = libft/libft.a

FLAGS = -Werror -Wall -Wextra

LIB = ./libft

test:
	@make -C $(LIB)
	@$(CC) -o test $(SRCS) $(INCL)

all: $(NAME)

%.o:%.c -I./
	@$(CC) $(FLAGS) $(INCL) $< -o $@

$(NAME):
	@make -C $(LIB)
	@$(CC) $(FLAGS) -o $(NAME) $(SRCS) $(INCL)

clean:
	@rm -f $(OUT)
	@make -C $(LIB) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIB) fclean

re: fclean all

.PHONY: all clean fclean re
