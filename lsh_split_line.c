/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsh_split_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukeles <mukeles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:59:46 by mukeles           #+#    #+#             */
/*   Updated: 2023/01/13 14:51:14 by mukeles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

char **lsh_split_line(char *line)
{
	int i;
	int j;
	int size;
	char **arr;
	char *tmp;
	
	tmp = line;
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
		arr[j] = command(tmp, &i, arr[j - 1], j);
		
		j++;
		while (tmp[i] == ' ' && tmp[i] != '\0')
			i++;
	}
	arr[j] = NULL;


	return (arr);

}
