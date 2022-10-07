NAME =		miniShell
CC =		gcc
FLAGS =		-Wall -Werror -Wextra -pthread
RM =		rm -rf

SRC =		lib.c lsh.c main.c split_line.c strtok.c

OBJECTS =	$(SRC:.c=.o)

.c.o:
			$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJECTS) mini_shell.h
			$(CC) $(FLAGS) $(OBJECTS) -o $(NAME)

clean:
			$(RM) $(OBJECTS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re