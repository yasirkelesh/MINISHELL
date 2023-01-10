#include "mini_shell.h"
void here_doc2(char *file, char *eof)
{
	char *line;
	int flags;
	int fd;

	flags = O_RDWR | O_CREAT | O_TRUNC;
	line = ft_strdup("");
	fd = open(file, flags, 0777);
	while (ft_strcmp(line, eof))
	{
		if (line)
			free(line);
		line = readline("heredoc> ");
		if (!line)
			no_input_redir(fd);
		if (line && ft_strcmp(line, eof))
			ft_putstrendl_fd(line, fd);
		else
			break;
	}
	if (line)
		free(line);
}
void here_doc(char *file, char *eof)
{
	char *line;
	int flags;
	int fd;

	flags = O_RDWR | O_CREAT | O_TRUNC;
	line = ft_strdup("");
	fd = open(file, flags, 0777);
	while (ft_strcmp(line, eof))
	{
		if (line)
			free(line);
		line = readline("heredoc> ");
		if (!line)
			no_input_redir(fd);
		if (line && ft_strcmp(line, eof))
			ft_putstrendl_fd(line, fd);
		else
			break;
	}
	close(fd);
	if (line)
		free(line);
}
