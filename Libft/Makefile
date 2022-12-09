# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkalyonc <nkalyonc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 19:10:19 by mukeles           #+#    #+#              #
#    Updated: 2022/12/08 20:00:04 by nkalyonc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
PATH_INCLUDE = ./
FLAG = -Wall -Wextra -Werror
OPTION = -c
SRC = $(wildcard *.c)
BONUS = *.c
OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME):
	gcc $(FLAG) $(OPTION) $(SRC) -I $(PATH_INCLUDE)
	ar rc $(NAME) *.o
	ranlib $(NAME)
bonus:
	gcc $(FLAG) $(OPTION) $(BONUS) -I $(PATH_INCLUDE)
	ar rc $(NAME) *.o
	ranlib $(NAME)

clean:
	/bin/rm -f  *.o
fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
