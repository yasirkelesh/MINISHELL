NAME =  minishell
CC =    gcc -g
FLAGS = -I /Users/mukeles/goinfre/homebrew/opt/readline/include
RM =        rm -rf
SOURCE =    $(wildcard *.c)
READLINE = -lreadline -L /Users/mukeles/goinfre/homebrew/opt/readline/lib
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