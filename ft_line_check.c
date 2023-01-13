/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukeles <mukeles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:59:46 by mukeles           #+#    #+#             */
/*   Updated: 2023/01/13 12:44:20 by mukeles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int	ft_line_check(char *line)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(line);
	if (line[0] == '\0')
		return (0);
	while (line[i] <= 32 && line[i])
	{
		i++;
	}
	if (len == i)
		return (0);
	return (1);
}
