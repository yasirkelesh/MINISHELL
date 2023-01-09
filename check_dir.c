#include "mini_shell.h"
static int	is_executable(char *cmd_path)
{
	if (access(cmd_path, 0) == 0)
		return (1);
	return (0);
}
static int	find_path2(char *cmdline)
{
	t_temp_var	a;
	struct stat	s;

	if (cmdline == NULL)
		return (0);
	if (is_executable(cmdline) == 1)
		return (1);
	a.tmp = find_value("PATH");
	a.tmp_2ar = ft_split(a.tmp, ':');
	a.i = -1;
	while (a.tmp_2ar [++a.i])
	{
		a.tmp = ft_strjoin("/", cmdline);
		a.tmp2 = ft_strjoin(a.tmp_2ar [a.i], a.tmp);
		free(a.tmp);
		if (stat(a.tmp2, &s) == 0)
		{
			free(a.tmp2);
			ft_free_str(a.tmp_2ar);
			return (1);
		}
		free(a.tmp2);
	}
	ft_free_str(a.tmp_2ar);
	return (0);
}
void	execsimple(char **parse)
{
	int		pid;
	char	*path;
	int		res;
	extern char **environ;
	path = find_path(parse[0]);
	pid = fork();
	if (pid == 0)
	{
		if (execve(path, parse,environ) != 0)
		{
			g_list.exit_status = 127;
			printf(RED"This command not executed command!\n");
			exit(g_list.exit_status);
		}
		free(path);
		kill(getpid(), SIGTERM);
	}
	waitpid(pid, &res, 0);
	free(path);
	if (WIFEXITED(res))
		g_list.exit_status = WEXITSTATUS(res);
}
void	ft_putstrendl_fd(char *s, int fd)
{
	int	i;

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

void	here_doc2(char *file, char *eof)
{
	char	*line;
	int		flags;
	int		fd;

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
			break ;
	}
	if (line)
		free(line);
}
void	no_input_redir(int fd)
{
	ft_putstr_fd("no heredoc input\n", 2);
	g_list.exit_status = 1;
	close(fd);
}
int	process_string(char *str)
{
	char	**commands;

	if (!str[0])
		return (0);
	commands = ft_split(str, ' ');
	if (find_path2(commands[0]))
	{
		g_list.exit_status = 0;
		execsimple(commands);
	}
	else
	{
		g_list.exit_status = 127;
		printf(RED"This command not executed command!\n");
	}
	ft_free_str(commands);
	return (0);
}
char	*sub_redir(char **str, int i)
{
	char	*temp;
	int		m;
	int		k;
	int		j;

	j = 0;
	k = -1;
	temp = (char *)malloc(sizeof(char) * 100);
	while (++k < i)
	{
		m = 0;
		while (str[k][m])
			temp[j++] = str[k][m++];
		temp[j] = ' ';
		j++;
	}
	temp[j - 1] = '\0';
	return (temp);
}
void	exec_redir(char *s, int fd, int i)
{
	int		n_pipe;

	run_signals(2);
	n_pipe = count(s, '|');
	dup2(fd, i);
	close(fd);
	if (n_pipe)
		pipe_handle(s, n_pipe);
	else
		process_string(s);
	exit(g_list.exit_status);
}

void	execute_dir(char *s, int fd, int i)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		g_list.exit_status = 127;
		ft_putstr_fd("Failed forking child", 1);
	}
	else if (pid == 0)
		exec_redir(s, fd, i);
	waitpid(0, &g_list.exit_status, 0);
	if (WIFEXITED(g_list.exit_status))
		g_list.exit_status = WEXITSTATUS(g_list.exit_status);
	else
		g_list.exit_status = 0;
}
void	here_doc(char *file, char *eof)
{
	char	*line;
	int		flags;
	int		fd;

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
			break ;
	}
	close(fd);
	if (line)
		free(line);
}

void	mixed_redir2(char *str, char *temp, int fd)
{
	int		fdd;
	int		stdout_copy;

	stdout_copy = dup(1);
	fdd = open(str, O_WRONLY | O_CREAT | O_APPEND, 0777);
	dup2(fdd, 1);
	close(fdd);
	execute_dir(temp, fd, 0);
	dup2(stdout_copy, 1);
	close(stdout_copy);
}

void	mixed_redir(char *str, char *temp, int fd)
{
	int		fdd;
	int		stdout_copy;

	stdout_copy = dup(1);
	fdd = open(str, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	dup2(fdd, 1);
	close(fdd);
	execute_dir(temp, fd, 0);
	dup2(stdout_copy, 1);
	close(stdout_copy);
}

void	redir_in_handle(char **str, int i)
{
	char	*file;
	int		fd;
	char	*temp;

	temp = sub_redir(str, i);
	file = ft_strdup(str[i + 1]);
	fd = open(file, O_RDONLY, 0777);
	if (str[i + 2] && str[i + 2][0] == '>')
	{
		if (str[i + 2][1] || str[i + 2][1] == '>')
			mixed_redir2(str[i + 3], temp, fd);
		else
			mixed_redir(str[i + 3], temp, fd);
	}	
	else
		execute_dir(temp, fd, 0);
	free (file);
	free (temp);
}

void	redir2_in_handle(char **str, int i)
{
	int		fd;
	char	*eof;
	char	*temp;

	temp = sub_redir(str, i);
	if (str[i + 2] && str[i + 2][0] == '>')
	{
		eof = ft_strdup(str[i + 1]);
		here_doc2("b.txt", eof);
		fd = open("b.txt", O_RDONLY, 0777);
		mixed_redir(str[i + 3], temp, fd);
	}	
	else
	{
		eof = ft_strdup(str[i + 1]);
		here_doc(TMP_FILE, eof);
		fd = open(TMP_FILE, O_RDONLY, 0777);
		execute_dir(temp, fd, 0);
	}
	if (eof[0] != '\0')
		free(eof);
	if (temp[0] != '\0')
		free(temp);
}

int	check_another_redir(char **str, int i)
{
	int		pos;

	pos = i + 2;
	while (str[pos])
	{
		if (str[pos + 1] && (ft_strncmp(str[pos], ">", 1) == 0 || \
			ft_strncmp(str[pos], ">>", 2) == 0))
		{
			open(str[pos - 1], O_CREAT, 0777);
			if (str[pos + 2] == NULL)
			{
				i = pos;
				break ;
			}
		}
		pos = pos + 2;
	}
	return (i);
}

void	redir_out_handle(char **str, int i)
{
	t_redir_var	variables;

	variables.j = 0;
	variables.m = 0;
	variables.k = 0;
	variables.temp = (char *)malloc(sizeof(char) * 100);
	variables.flags = O_WRONLY | O_CREAT;
	if (str[i + 2])
		i = check_another_redir(str, i);
	variables.file = ft_strdup(str[i + 1]);
	while (ft_strncmp(str[variables.k], ">", 1))
	{
		variables.m = 0;
		while (str[variables.k][variables.m])
			variables.temp[variables.j++] = str[variables.k][variables.m++];
		variables.temp[variables.j] = ' ';
		variables.j++;
		variables.k++;
	}
	variables.temp[variables.j - 1] = '\0';
	variables.fd = open(variables.file, variables.flags | O_TRUNC, 0777);
	execute_dir(variables.temp, variables.fd, 1);
	free(variables.file);
	free(variables.temp);
}

void	redir2_out_handle(char **str, int i)
{
	char	*temp;
	int		fd;
	int		flags;
	char	*file;

	flags = O_WRONLY | O_CREAT;
	temp = sub_redir(str, i);
	if (str[i + 2])
		i = check_another_redir(str, i);
	file = ft_strdup(str[i + 1]);
	fd = open(file, flags | O_APPEND, 0777);
	execute_dir(temp, fd, 1);
	if (temp[0] != '\0')
		free(temp);
	if (file[0] != '\0')
		free(file);
}
int	redirect_out(char **str, int i)
{
	if (str[i + 1] == NULL || str[i + 1][0] == '>' || str[i + 1][0] == '<'
		|| str[i + 1][0] == '\0')
		return (0);
	if (!ft_strcmp(str[i], ">>"))
	{
		redir2_out_handle(str, i);
		return (0);
	}
	else if (!ft_strcmp(str[i], ">"))
	{
		redir_out_handle(str, i);
		return (0);
	}
	return (1);
}

int	redirect_in(char **str, int i)
{
	if (str[i + 1] && !ft_strcmp(str[i], "<"))
	{
		redir_in_handle(str, i);
		return (0);
	}
	else if (str[i + 1] && !ft_strcmp(str[i], "<<"))
	{
		redir2_in_handle(str, i);
		return (0);
	}
	return (1);
}

void	check_dir(char *str)
{
	int		i;
	char	**commands;

	i = 0;
	commands = ft_split(str, ' ');
	while (commands[i])
	{
		if ((!ft_strcmp(commands[i], ">") || !ft_strcmp(commands[i], ">>")))
		{
			redirect_out(commands, i);
			break ;
		}
		else if ((!ft_strcmp(commands[i], "<") || \
		!ft_strcmp(commands[i], "<<")))
		{
			redirect_in(commands, i);
			break ;
		}	
		i++;
	}
	ft_free_str(commands);
}
