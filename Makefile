NAME =  minishell
CC =    gcc -Wall -Wextra -g
FLAGS = -I /Users/mukeles/homebrew/Cellar/readline/8.2.1/include
RM =        rm -rf
SOURCE =    $(wildcard *.c Libft/*.c)
READLINE = -lreadline -L /Users/mukeles/homebrew/Cellar/readline/8.2.1/lib
OBJECTS =   $(SOURCE:.c=.o)
.c.o:
			$(CC) $(FLAGS) -c $< -o $(<:.c=.o)
all:		$(NAME)
$(NAME):	$(OBJECTS) mini_shell.h
			$(CC) $(FLAGS) $(READLINE) $(OBJECTS) -o $(NAME)
clean:
			$(RM) $(OBJECTS)
fclean:		clean
			$(RM) $(NAME)
re:			fclean all
.PHONY:		all clean fclean re