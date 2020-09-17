# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kachiote <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/03 14:53:22 by kachiote          #+#    #+#              #
#    Updated: 2020/09/18 00:21:11 by sslift           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = libftprintf.a

CFILES = ft_printf \
		flags \
		conversions \
		ft_ftoa \
		ft_lennb \
        ft_itoa_basehl \
        ft_based \
        ft_nbrmod \
        ft_printarg \
        ft_printout_cond \
        ft_numstart \
        ft_doxc \
        ft_doxc_new \
        ft_sp_s \
        ft_sp_f

SRCS = $(patsubst %, %.c, $(CFILES))

OUT = $(patsubst %, %.o, $(CFILES))

INCL = ./

FLAGS = -Werror -Wextra -Wall

LIB = ./libft

all: $(NAME)

%.o:%.c -I$(INCL)
	@$(CC) $(FLAGS) $(INCL) $< -o $@

$(NAME): $(OUT)
	@make -C $(LIB)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OUT)
	@ranlib $(NAME)

clean:
	@rm -f $(OUT)
	@make -C $(LIB) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIB) fclean

re: fclean all

.PHONY: all clean fclean re
