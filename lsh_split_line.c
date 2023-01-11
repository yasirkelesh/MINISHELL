/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsh_split_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukeles <mukeles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:59:46 by mukeles           #+#    #+#             */
/*   Updated: 2023/01/10 18:17:50 by mukeles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

char	**lsh_split_line(char *line)
{
	int		i;
	int		j;
	int		size;
	char	**arr;
	char *tmp;
	char *tmp2;
	tmp = line;
	tmp2=line;
	size = get_cmd_num(tmp);
	arr = malloc(sizeof(char *) * (size));
	if (!arr)
		return (NULL);
	j = 0;
	i = 0;
	while (tmp[i])
	{
		while (tmp[i] == ' ' && tmp[i] != '\0')
			i++;
		system("leaks minishell > leaks5.txt");
		arr[j] = command(tmp, &i, arr[j - 1], j);
		system("leaks minishell > leaks4.txt");
		j++;
		free(tmp);
		while (tmp2[i] == ' ' && tmp2[i] != '\0')
			i++;
	}
	arr[j] = NULL;
	//free(tmp);
	return (arr);
}
