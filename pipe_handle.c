/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukeles <mukeles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:59:46 by mukeles           #+#    #+#             */
/*   Updated: 2023/01/14 21:29:17 by mukeles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void	execute_pipe(int *fd, int j, t_list *temp)
{
	extern char	**environ;
	int			i;
	char		**cmd;
	char		*path;

	if (j != 0)
		if (dup2(fd[(j - 1) * 2], 0) < 0)
			exit(1);
	if (temp->next)
		if (dup2(fd[j * 2 + 1], 1) < 0)
			exit(1);
	i = -1;
	while (fd[++i])
		close(fd[i]);
	cmd = cmd_split_content(temp->content);
	path = find_path(cmd[0]);
	if (is_builtin(cmd[0]))
		exec_builtin2(cmd);
	else if (execve(path, cmd, environ) != 0)
		execve_error();
	free(path);
	ft_free_str(cmd);
	exit(g_list.exit_status);
}

char	**cmd_split_content(char *content)
{
	char	**tmp;
	int		k;

	tmp = lsh_split_line(content);
	k = 0;
	while (tmp[k])
	{
		tmp[k] = parser(tmp[k]);
		if (!tmp[k])
			perror("");
		k++;
	}
	return (tmp);
}

static void	split_piped(int *fd, t_list *mini)
{
	int		j;
	int		pid;
	t_list	*temp;

	j = 0;
	temp = mini;
	while (temp)
	{
		signals(1);
		pid = fork();
		if (pid == 0)
		{
			signals(2);
			execute_pipe(fd, j, temp);
		}
		temp = temp->next;
		j++;
	}
	free(temp);
}

void	execpiped(t_list **mini, int countpipe)
{
	int	i;
	int	*fd;

	i = -1;
	fd = (int *)malloc(sizeof(int) * countpipe * 2);
	while (++i < countpipe)
	{
		if (pipe(fd + i * 2) < 0)
			exit(1);
	}
	split_piped(fd, (*mini));
	i = -1;
	while (++i < 2 * countpipe)
		close(fd[i]);
	countpipe++;
	while (countpipe--)
		waitpid(0, &g_list.exit_status, WUNTRACED);
	if (WIFEXITED(g_list.exit_status))
		g_list.exit_status = WEXITSTATUS(g_list.exit_status);
	else
		g_list.exit_status = 0;
	if (fd[0] != '\0')
		free(fd);
}

void	pipe_handle(char *str, int n_pipe)
{
	char	**tmp;
	t_list	**list;

	tmp = ft_split(str, '|');
	list = (t_list **)malloc(sizeof(t_list *));
	*list = NULL;
	add_list(tmp, list);
	execpiped(list, n_pipe);
	ft_free_list(list);
	ft_free_str(tmp);
}
