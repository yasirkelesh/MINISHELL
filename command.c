/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukeles <mukeles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:59:46 by mukeles           #+#    #+#             */
/*   Updated: 2023/01/14 16:17:14 by mukeles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

char	*trim_quote(char *str, int *i, int j, char q)
{
	char	*tmp;

	(*i)++;
	if (str[*i] != q)
	{
		while (str[*i] != q && str[*i] != '\0')
			(*i)++;
		(*i)++;
		tmp = ft_substr(str, j, *i - (j));
	}
	else
		tmp = ft_substr(str, j, *i - (j + 1));
	return (tmp);
}

char	*trim_dollar(char *str, int *i, int j)
{
	char	*tmp;

	(*i)++;
	if (str[*i - 1] == '$' && str[*i] == '?')
	{
		(*i)++;
		tmp = ft_substr(str, j, *i - j);
		return (tmp);
	}
	while (ft_isalnum(str[*i]) && str[*i] != '\0')
		(*i)++;
	tmp = ft_substr(str, j, *i - j);
	return (tmp);
}

char	*trim_space(void)
{
	char	*tmp;

	tmp = malloc(2 * sizeof(char));
	tmp[0] = ' ';
	tmp[1] = '\0';
	return (tmp);
}

char	*command(char *str, int *i, char *args, int k)
{
	int		j;
	char	*tmp;

	j = *i;
	if (ft_isspace(str[*i - 1]) && strcmp(" ", args) && k != 1)
		return (trim_space());
	if (str[*i] == '$')
		return (trim_dollar(str, i, j));
	if (str[*i] == '\"')
		return (trim_quote(str, i, j, '\"'));
	if (str[*i] == '\'' && str[*i])
		return (trim_quote(str, i, j, '\''));
	while (str[*i] != ' ' && str[*i] != '\''
		&& str[*i] != '\"' && str[*i] != '\0')
		(*i)++;
	tmp = ft_substr(str, j, *i - (j));
	return (tmp);
}
