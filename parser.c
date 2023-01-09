/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkalyonc <nkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:59:46 by mukeles           #+#    #+#             */
/*   Updated: 2023/01/09 18:05:13 by nkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

char	*parser(char *str)
{
	int		i;
	char	*tmp;

	tmp = str;
	if (!tmp)
		return (str);
	if (tmp[0] == '$')
	{
		if (tmp[1] == '\0')
			return (tmp);
	}
	i = 0;
	while (tmp[i])
	{
		if (tmp[i] == '\"')
		{
			if (tmp[i + 2] == '"')
				tmp = double_quotes(tmp, &i);
		}
		else if (tmp[i] == '$')
		{
			if (ft_strrchr(tmp, '\'') == 0 && ft_strrchr(tmp, '\"') == 0)
			{
				tmp = dollar(tmp, &i);
				i = 0;
			}
			i++;
			if (tmp == NULL)
				return (0);
		}
		else if (tmp[i] == '\\')
		{
			tmp = slash(tmp, &i);
		}
		else if (tmp[i] == '\'')
		{
			if (tmp[i + 2] == '\'')
			{
				tmp = quotes(tmp, &i);
			}
		}
		i++;
	}
	return (tmp);
}
