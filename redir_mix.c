/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_mix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukeles <mukeles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:59:46 by mukeles           #+#    #+#             */
/*   Updated: 2023/01/14 21:30:11 by mukeles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int	n_pipe;

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

int	check_another_redir(char **str, int i)
{
	int	pos;

	pos = i + 2;
	while (str[pos])
	{
		if (str[pos + 1] && (ft_strncmp(str[pos], ">", 1) == 0
				|| ft_strncmp(str[pos], ">>", 2) == 0))
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
