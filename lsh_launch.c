/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsh_launch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkalyonc <nkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:59:46 by mukeles           #+#    #+#             */
/*   Updated: 2023/01/09 18:05:45 by nkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

extern char	**environ;

int	lsh_launch(char **args, t_builtin_str *str)
{
	pid_t	pid;
	int		status;
	int		k;
	char	*str1 = find_path(args[0]);

	k = 0;
	if ((lsh_num_builtins(str, args[0]) != -1) && k == 0)
	{
		k++;
	}
	pid = fork();
	if (pid == 0)
	{
		if (k == 0)
		{
			if (execve(str1, args, environ) == -1)
			{
				perror("");
			}
		}
		else
		{
			return (1);
		}
		exit(EXIT_FAILURE);
	}
	waitpid(pid, &status, WUNTRACED);
	return (1);
}
