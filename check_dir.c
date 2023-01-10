#include "mini_shell.h"
static int is_executable(char *cmd_path)
{
	if (access(cmd_path, 0) == 0)
		return (1);
	return (0);
}
static int find_path2(char *cmdline)
{
	t_temp_var a;
	struct stat s;

	if (cmdline == NULL)
		return (0);
	if (is_executable(cmdline) == 1)
		return (1);
	a.tmp = find_value("PATH");
	a.tmp_2ar = ft_split(a.tmp, ':');
	a.i = -1;
	while (a.tmp_2ar[++a.i])
	{
		a.tmp = ft_strjoin("/", cmdline);
		a.tmp2 = ft_strjoin(a.tmp_2ar[a.i], a.tmp);
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
void execsimple(char **parse)
{
	int pid;
	char *path;
	int res;
	extern char **environ;
	path = find_path(parse[0]);
	pid = fork();
	if (pid == 0)
	{
		if (execve(path, parse, environ) != 0)
		{
			g_list.exit_status = 127;
			printf(RED "This command not executed command!\n");
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

int process_string(char *str)
{
	char **commands;

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
		printf(RED "This command not executed command!\n");
	}
	ft_free_str(commands);
	return (0);
}

void execute_dir(char *s, int fd, int i)
{
	pid_t pid;

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

void check_dir(char *str)
{
	int i;
	char **commands;

	i = 0;
	commands = ft_split(str, ' ');
	while (commands[i])
	{
		if ((!ft_strcmp(commands[i], ">") || !ft_strcmp(commands[i], ">>")))
		{
			redirect_out(commands, i);
			break;
		}
		else if ((!ft_strcmp(commands[i], "<") ||
				  !ft_strcmp(commands[i], "<<")))
		{
			redirect_in(commands, i);
			break;
		}
		i++;
	}
	ft_free_str(commands);
}
