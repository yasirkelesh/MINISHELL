/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkalyonc <nkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:59:46 by mukeles           #+#    #+#             */
/*   Updated: 2023/01/09 18:06:09 by nkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int	get_cmd_num(const char *str)
{
	int		i;
	int		count;
	char	c;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			count++;
		while (str[i] == ' ')
			i++;
		if (str[i])
			count++;
		if (str[i] == '"' || str[i] == '\'' || str[i] == '$')
		{
			if (str[i] == '$')
			{
				while (ft_isalnum(str[++i]))
					;
			}
			else
			{
				c = str[i];
				while (str[i] != c)
					i++;
				i++;
			}
		}
		else
			while (str[i] != ' ' && str[i] != '\0'
				&& str[i] != '"' && str[i] != '\'')
				i++;
	}
	return (count);
}
