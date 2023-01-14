/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_mix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukeles <mukeles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:59:46 by mukeles           #+#    #+#             */
/*   Updated: 2023/01/14 19:00:32 by mukeles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void no_input_redir(int fd)
{
	ft_putstr_fd("no heredoc input\n", 2);
	g_list.exit_status = 1;
	close(fd);
}

char *sub_redir(char **str, int i)
{
	char *temp;
	int m;
	int k;
	int j;

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
int is_builtin(char *tmp)
{
	if (!tmp)
		return (0);
	if (is_echo(tmp))
		return (1);
	else if (!ft_strncmp(tmp, "cd", 2))
		return (2);
	else if (!ft_strncmp(tmp, "pwd", 3))
		return (3);
	else if (!ft_strncmp(tmp, "export", 6))
		return (4);
	else if (!ft_strncmp(tmp, "unset", 5))
		return (5);
	else if (!ft_strcmp(tmp, "env"))
	{
		g_list.exit_status = 127;
		return (6);
	}
	else if (!ft_strncmp(tmp, "exit", 4))
		return (7);
	return (0);
}
void exec_builtin(char *str)
{
	char **tmp;
	char *tmp2;
	int i;

	tmp = ft_split(str, ' ');
	tmp2 = ft_strtrim(str, " ");
	i = is_builtin(*tmp);
	if (i == 1)
		echo(tmp);
	else if (i == 2)
		lsh_cd(tmp);
	else if (i == 3)
		pwd();
	else if (i == 4)
		export(tmp);
	else if (i == 5)
		unset(tmp);
	else if (i == 6)
		env();
	else if (i == 7)
		lsh_exit();
	ft_free_str(tmp);
}
void exec_redir(char *s, int fd, int i)
{
	int n_pipe;

	run_signals(2);
	n_pipe = count(s, '|');
	dup2(fd, i);
	close(fd);
	if (n_pipe)
		pipe_handle(s, n_pipe);
	else if (is_builtin(s))
	{
		printf("TEST****\n");
		exec_builtin(s);
	}
	else
		process_string(s);
	exit(g_list.exit_status);
}

int check_another_redir(char **str, int i)
{
	int pos;

	pos = i + 2;
	while (str[pos])
	{
		if (str[pos + 1] && (ft_strncmp(str[pos], ">", 1) == 0 || ft_strncmp(str[pos], ">>", 2) == 0))
		{
			open(str[pos - 1], O_CREAT, 0777);
			if (str[pos + 2] == NULL)
			{
				i = pos;
				break;
			}
		}
		pos = pos + 2;
	}
	return (i);
}
