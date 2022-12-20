#include "mini_shell.h"

int exec_dir(char **str)
{
	int i;

	i = 1;
	if (ft_strcmp(str[0], "export") == 0)
	{
		env();
		return (0);
	}
	else if (ft_strcmp(str[0], "echo") == 0)
	{
		while (str[i][0] != '>' && str[i][0] != '<')
		{
			ft_putstr(str[i]);
			write(1, " ", 1);
			i++;
		}
		return (0);
	}
	else if (ft_strcmp(str[0], "pwd") == 0)
	{

		pwd();
		return (0);
	}
	return (1);
}
void redir_out_handle(char **str, int i, char **s)
{
	int fd;
	int k;
	int flags;
	char *file;

	k = 0;
	flags = O_WRONLY | O_CREAT;
	file = ft_strdup(str[i + 1]);
	while (k < i)
	{
		s[k] = (char *)malloc(sizeof(char) * 100);
		ft_strcpy(s[k], ft_strdup(str[k]));
		k++;
	}
	fd = open(file, flags | O_TRUNC, 0777);
	exec_fork(s, fd, 1);
	free(file);
}
void redir_in_handle(char **str, int i, char **s)
{
	int k;
	char *file;
	int fd;

	k = 0;
	while (k < i)
	{
		s[k] = (char *)malloc(sizeof(char) * 100);
		ft_strcpy(s[k], ft_strdup(str[k]));
		k++;
	}
	file = ft_strdup(str[i + 1]);
	fd = open(file, O_RDONLY, 0777);
	exec_fork(s, fd, 0);
}
extern char **environ;
void exec_fork(char **s, int fd, int i)
{
	pid_t pid;
	int status;
	char *str1 = find_path(s[0]);
	pid = fork();
	if (pid == 0)
	{
		dup2(fd, i);
		close(fd);
		if (exec_dir(s))
		{
			if (execve(str1, s, environ) == -1)
			{
				perror("");
			}
		}
		kill(pid, SIGKILL);
	}
	else if (pid < 0)
	{
		// Error forking
		ft_free_str(s);
		perror("lsh");
	}
	else
	{
		wait(NULL);
		/* printf(" benim pid %d\ngetpid() %d\n", pid, getpid());  */
		waitpid(pid, &status, WUNTRACED);
		/*         while (!WIFEXITED(status) && !WIFSIGNALED(status))
				{
				  printf("test");
				  waitpid(pid, &status, WUNTRACED);
				}  */
	}
}
void redir2_out_handle(char **str, int i, char **s)
{
	int fd;
	int k;
	int flags;
	char *file;

	k = 0;
	flags = O_WRONLY | O_CREAT;
	file = ft_strdup(str[i + 1]);
	fd = open(file, flags | O_APPEND, 0777);
	while (k < i)
	{
		s[k] = (char *)malloc(sizeof(char) * 100);
		ft_strcpy(s[k], ft_strdup(str[k]));
		k++;
	}
	exec_fork(s, fd, 1);
	free(file);
}
void ft_putstrendl_fd(char *s, int fd)
{
	int i;

	i = 0;
	if (s != 0 && fd != 0)
	{
		while (s[i] != '\0')
		{
			write(fd, &s[i], 1);
			i++;
		}
		write(fd, "\n", 1);
	}
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
		free(line);
		line = readline("heredoc> ");
		if (line && ft_strcmp(line, eof))
			ft_putstrendl_fd(line, fd);
		else
			break;
	}
	close(fd);
	free(line);
}
void redir2_in_handle(char **str, int i, char **s)
{
	int k;
	int fd;
	char *eof;

	k = 0;
	while (k < i)
	{
		s[k] = (char *)malloc(sizeof(char) * 100);
		ft_strcpy(s[k], ft_strdup(str[k]));
		k++;
	}
	eof = ft_strdup(str[i + 1]);
	here_doc(TMP_FILE, eof);
	fd = open(TMP_FILE, O_RDONLY, 0777);
	exec_fork(s, fd, 0);
}
int redirect_out(char **str, int i)
{
	char **s;

	s = (char **)malloc(sizeof(char *) * 100);
	if (str[i + 1] == NULL || str[i + 1][0] == '>' || str[i + 1][0] == '<' || str[i + 1][0] == '\0')
		return (0);
	if (!ft_strcmp(str[i], ">>"))
	{
		redir2_out_handle(str, i, s);
		return (0);
	}
	else if (!ft_strcmp(str[i], ">"))
	{
		redir_out_handle(str, i, s);
		return (0);
	}
	ft_free_str(s);
	return (1);
}

int redirect_in(char **str, int i)
{
	char **s;

	s = (char **)malloc(sizeof(char *) * 100);
	if (str[i + 1] && !ft_strcmp(str[i], "<"))
	{
		redir_in_handle(str, i, s);
		return (0);
	}
	else if (str[i + 1] && !ft_strcmp(str[i], "<<"))
	{
		redir2_in_handle(str, i, s);
		return (0);
	}
	ft_free_str(s);
	return (1);
}

int check_dir(char **str)
{
	int i;
	int ret;

	i = 0;
	ret = 1;
	//printf("test0\n");
	while (str[i])
	{
		//printf("dir str[%d] : %s\n", i, str[i]);
		if ((!ft_strcmp(str[i], ">") || !ft_strcmp(str[i], ">>")))
		{
			//printf("test\n");
			ret = redirect_out(str, i);
		}
		else if ((!ft_strcmp(str[i], "<") || !ft_strcmp(str[i], "<<")))
		{
			//printf("test2\n");
			ret = redirect_in(str, i);
		}
		i++;
	}
	return (ret);
}