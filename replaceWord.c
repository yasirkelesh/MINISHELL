/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replaceWord.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkalyonc <nkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:59:46 by mukeles           #+#    #+#             */
/*   Updated: 2023/01/09 18:04:42 by nkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

char	*replaceword(char *s, char *oldw, char *neww)
{
	char	*result;
	int		i;
	int		cnt;
	int		newwlen;
	int		oldwlen;

	i = 0;
	cnt = 0;
	newwlen = ft_strlen(neww);
	oldwlen = ft_strlen(oldw);
	while (s[i] != '\0')
	{
		if (strstr(&s[i], oldw) == &s[i])
		{
			cnt++;
			i += oldwlen - 1;
		}
		i++;
	}
	result = (char *)malloc(i + cnt * (newwlen - oldwlen) + 1);
	if (!result)
		return (result);
	i = 0;
	while (*s)
	{
		if (strstr(s, oldw) == s)
		{
			strcpy(&result[i], neww);
			i += newwlen;
			s += oldwlen;
		}
		else
			result[i++] = *s++;
	}
	result[i] = '\0';
	return (result);
}
