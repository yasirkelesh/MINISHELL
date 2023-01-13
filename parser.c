/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukeles <mukeles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:59:46 by mukeles           #+#    #+#             */
/*   Updated: 2023/01/13 18:07:00 by mukeles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

char *parser(char *str)
{
	int i;
	char *tmp;
	char *tmp2;

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
			{
				tmp2 = tmp;
				tmp = double_quotes(tmp2, &i);
				free(tmp2);
			}
		}
		else if (tmp[i] == '$')
		{
			if (ft_strrchr(tmp, '\'') == 0 && ft_strrchr(tmp, '\"') == 0)
			{
				if (tmp[0] == '$' && tmp[1] == '?')
				{
					tmp = ft_strdup(ft_itoa(g_list.exit_status));
					continue;
				}
				tmp2 = tmp;
				tmp = dollar(tmp2, &i);
				free(tmp2);
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
				tmp2 = tmp;
				tmp = quotes(tmp2, &i);
				free(tmp2);
			}
		}
		i++;
	}
	return (tmp);
}
