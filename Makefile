NAME = mini_shell

CFILES = cd_exit_unset.c dquote.c echo_pwd_export.c \
		env.c init.c shmain.c strtok.c utils.c \
		mini_shell.h line_write.c get_next_line.c \
		get_next_line_utils.c check_line.c \
		dollar_quotes.c parser.c

OBJECTS = $(CFILES:.c=.o)

LIBFT = ./libft/libft.a

CC = gcc

CFLAGS = -g -lreadline

all:	$(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) $(CFLAGS)  $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJECTS)

fclean:	clean
	rm -f $(NAME)

re: fclean all