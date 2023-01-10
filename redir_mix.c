#include "mini_shell.h"

void	no_input_redir(int fd)
{
	ft_putstr_fd("no heredoc input\n", 2);
	g_list.exit_status = 1;
	close(fd);
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