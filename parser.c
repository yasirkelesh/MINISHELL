/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukeles <mukeles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:59:46 by mukeles           #+#    #+#             */
/*   Updated: 2023/01/14 22:02:41 by mukeles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

static char	*tmp_dollar(char *tmp, char *tmp2, int *i)
{
	tmp2 = tmp;
	tmp = dollar(tmp2, i);
	free(tmp2);
	(*i) = 0;
	return (tmp);
}

char	*dollar_query(char *tmp, char *tmp2, int i)
{
	while (tmp[i])
	{
		if (tmp[i] == '$')
		{
			if (ft_strrchr(tmp, '\'') == 0 && ft_strrchr(tmp, '\"') == 0)
			{
				if (tmp[0] == '$' && tmp[1] == '?')
				{
					tmp2 = ft_itoa(g_list.exit_status);
					free(tmp);
					tmp = ft_strdup(tmp2);
					free(tmp2);
					return (tmp);
				}
				tmp = tmp_dollar(tmp, tmp2, &i);
			}
			i++;
			if (tmp == NULL)
				return (0);
		}
		i++;
	}
	return (tmp);
}

char	*parser(char *str)
{
	int		i;
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	tmp2 = 0;
	tmp = str;
	if (!tmp)
		return (str);
	if (tmp[0] == '$')
	{
		if (tmp[1] == '\0')
			return (tmp);
	}
	i = 0;
	tmp3 = dollar_query(tmp, tmp2, i);
	return (tmp3);
}
