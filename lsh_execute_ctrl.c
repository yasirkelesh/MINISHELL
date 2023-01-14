/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsh_execute_ctrl.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukeles <mukeles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:42:34 by mukeles           #+#    #+#             */
/*   Updated: 2023/01/14 19:39:05 by mukeles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int	export_unset(char **args, int i)
{
	if (i == 5)
	{
		export(args);
		return (1);
	}
	else if (i == 6)
	{
		unset(args);
		return (1);
	}
	return (-1);
}

int	pwd_env(int i)
{
	if (i == 3)
	{
		pwd();
		return (1);
	}
	else if (i == 4)
	{
		env();
		return (1);
	}
	return (-1);
}

int	cd_exit_echo(char **args, int i)
{
	if (i == 0)
	{
		lsh_cd(args);
		return (1);
	}
	else if (i == 1)
	{
		lsh_exit();
		return (0);
	}
	else if (i == 2)
	{
		echo(args);
		return (1);
	}
	return (-1);
}
