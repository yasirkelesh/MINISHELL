/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukeles <mukeles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:59:46 by mukeles           #+#    #+#             */
/*   Updated: 2023/01/15 02:25:38 by mukeles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void	echo_print(char **arr, int *i)
{
	if (ft_strrchr(arr[(*i)], '\'') == 0
		&& ft_strrchr(arr[(*i)], '\"') == 0)
		printf("%s", arr[(*i)++]);
	else if (ft_strrchr(arr[(*i)], '\'') == 0
		&& ft_strrchr(arr[(*i)], '\"') != 0)
		print_double_quote(arr, i);
	else if (ft_strrchr(arr[(*i)], '\'') != 0
		&& ft_strrchr(arr[(*i)], '\"') == 0)
		print_single_quote(arr, i);
	else if (ft_strrchr(arr[(*i)], '\'') != 0
		&& ft_strrchr(arr[(*i)], '\"') != 0)
		print_mixed_quote(arr, i);
}

void	echo(char **arr)
{
	int	i;
	int	n;

	n = 0;
	i = 1;
	while (arr[i] && (ft_strncmp(arr[i], "-n", 3) == 0
			|| (ft_strncmp(arr[i], " ", 2) == 0
				&& ft_strncmp(arr[i + 1], "-n", 3) == 0)))
	{
		n = 1;
		i++;
	}
	if (arr[1] == NULL)
		printf("\n");
	else if (arr[i] &&!ft_strcmp(arr[i], " "))
		i++;
	while (arr[i])
		echo_print(arr, &i);
	if (!n)
		printf("\n");
}
