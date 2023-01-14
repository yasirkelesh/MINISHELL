/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukeles <mukeles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:59:46 by mukeles           #+#    #+#             */
/*   Updated: 2023/01/14 21:20:03 by mukeles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void	execsimple(char **parse)
{
	int			pid;
	char		*path;
	int			res;
	extern char	**environ;

	path = find_path(parse[0]);
	pid = fork();
	if (pid == 0)
	{
		if (execve(path, parse, environ) != 0)
			execve_error();
		free(path);
		kill(getpid(), SIGTERM);
	}
	waitpid(pid, &res, 0);
	free(path);
	if (WIFEXITED(res))
		g_list.exit_status = WEXITSTATUS(res);
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
		printf(RED "This command not executed command!\n");
	}
	ft_free_str(commands);
	return (0);
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

void	check_dir(char *str)
{
	int		i;
	char	**commands;

	i = 0;
	commands = ft_split(str, ' ');
	while (commands[i])
	{
		if ((!ft_strcmp(commands[i], ">")
				|| !ft_strcmp(commands[i], ">>")))
		{
			redirect_out(commands, i);
			break ;
		}
		else if ((!ft_strcmp(commands[i], "<")
				|| !ft_strcmp(commands[i], "<<")))
		{
			redirect_in(commands, i);
			break ;
		}
		i++;
	}
	ft_free_str(commands);
}
