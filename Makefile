NAME =  minishell
CC =    gcc -Wall -Wextra -Werror -g
FLAGS = -I /goinfre/homebrew/opt/readline/include
RM =        rm -rf
SOURCE =    $(wildcard *.c Libft/*.c)
READLINE = -lreadline -L /goinfre/homebrew/opt/readline/lib
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