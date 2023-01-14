/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukeles <mukeles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 21:28:56 by mukeles           #+#    #+#             */
/*   Updated: 2023/01/14 21:30:19 by mukeles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int	is_builtin(char *tmp)
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

void	exec_builtin(char *str)
{
	char	**tmp;
	char	*tmp2;
	int		i;

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

void	exec_builtin2(char **args)
{
	int		i;

	i = is_builtin(args[0]);
	if (i == 1)
		echo(args);
	else if (i == 2)
		lsh_cd(args);
	else if (i == 3)
		pwd();
	else if (i == 4)
		export(args);
	else if (i == 5)
		unset(args);
	else if (i == 6)
		env();
	else if (i == 7)
		lsh_exit();
}
