/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukeles <mukeles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:44:44 by mukeles           #+#    #+#             */
/*   Updated: 2023/01/14 18:39:39 by mukeles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void	lsh_cd(char **arr)
{
	int		size;
	char	*str;

	size = 0;
	while (arr[size])
		size++;
	if (size > 2)
		printf("arguments\n");
	else if (size == 1)
	{
		str = getenv("HOME");
		chdir(str);
	}
	else
	{
		if (chdir(arr[1]))
			printf("error\n");
	}
}

int	lsh_exit(void)
{
	return (0);
}
