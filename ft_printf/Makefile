# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tholzheu <tholzheu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/10 16:42:11 by tholzheu          #+#    #+#              #
#    Updated: 2018/11/25 14:42:04 by ale-goff         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HEADER = ft_printf.h

FLAGS = -Wall -Werror -Wextra -c

DEBUG = fsanitize=address -g

SRCS = ft_printf.c \
	   init.c \
	   nb_size.c \
	   padding.c \
	   parsing.c \
	   print_all_nbs.c \
	   print_conversion.c \
	   print_other.c \
	   print_special.c \
	   set_params.c \
	   unsigned_helpers.c \
	   minilibft.c \

SRCO = $(SRCS:.c=.o)

$(NAME):
	@gcc $(FLAGS) $(SRCS) -I=$(HEADER)
	@ar rcs $(NAME) $(SRCO)

all: $(NAME)

run: re
	@gcc main.c print_bits.c $(NAME)

san: fclean
	@gcc $(DEBUG) $(SRCS) main.c print_bits.c

clean:
	@/bin/rm -f $(SRCO)

fclean: clean
	@/bin/rm -rf $(NAME) *.out* *.dSYM

re: fclean all

git: fclean
	git add .
	git reset HEAD *main*
	git status
	git commit -m "update"
	git push
