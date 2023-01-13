/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukeles <mukeles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:59:46 by mukeles           #+#    #+#             */
/*   Updated: 2023/01/13 14:25:17 by mukeles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

char	*get_value(char *key)
{
	char	*value;
	size_t	key_len;
	t_list	*tmp;

	tmp = g_list.g_env;
	tmp = tmp->next;
	key_len = ft_strlen(key);
	while (tmp)
	{
		if (!ft_strncmp(key, (char *)tmp->content, key_len)
			&& ((char *)(tmp->content))[key_len] == '=')
		{
			value = ft_strdup((char *)tmp->content + key_len + 1);
			return (value);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

char	*dollar(char *str, int *i)
{
	int		j;
	char	*key;
	char	*value;

	j = *i;
	while (str[++(*i)] && str[*i] != ' ' && ft_isalnum(str[*i]))
		;

	key = ft_substr(str, j + 1, *i - j - 1);
	value = get_value(key);
	free(key);
	if (!value)
		return (NULL);
	return (value);
}
