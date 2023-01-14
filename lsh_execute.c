/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsh_execute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukeles <mukeles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 12:19:48 by mukeles           #+#    #+#             */
/*   Updated: 2023/01/14 20:00:56 by mukeles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int	lsh_num_builtins(t_builtin_str *str, char *args)
{
	int	i;

	i = 0;
	while (i <= 6)
	{
		if (!ft_strcmp(args, str->builtin_str[i]))
			return (i);
		i++;
	}
	return (-1);
}

int	lsh_execute(char **args, t_builtin_str *str)
{
	int	i;

	i = 8;
	if (!ft_strcmp(args[0], "echo") && args[1] == NULL)
		return (1);
	i = lsh_num_builtins(str, args[0]);
	if (i >= 0 && i <= 2)
		return (cd_exit_echo(args, i));
	else if (i >= 3 && i <= 4)
		return (pwd_env(i));
	else if (i >= 5 && i <= 6)
		return (export_unset(args, i));
	return (lsh_launch(args, str));
}
