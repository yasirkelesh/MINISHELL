/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsh_split_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkalyonc <nkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:59:46 by mukeles           #+#    #+#             */
/*   Updated: 2023/01/09 18:05:31 by nkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

char	**lsh_split_line(char *line)
{
	int		i;
	int		j;
	int		size;
	char	**arr;

	size = get_cmd_num(line);
	arr = malloc(sizeof(char *) * (size));
	if (!arr)
		return (NULL);
	j = 0;
	i = 0;
	while (line[i])
	{
		while (line[i] == ' ' && line[i] != '\0')
			i++;
		arr[j] = command(line, &i, arr[j - 1], j);
		j++;
		while (line[i] == ' ' && line[i] != '\0')
			i++;
	}
	arr[j] = NULL;
	return (arr);
}
