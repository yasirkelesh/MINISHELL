/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_quetes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukeles <mukeles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:59:46 by mukeles           #+#    #+#             */
/*   Updated: 2023/01/11 14:52:40 by mukeles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

char	*double_quotes(char *str, int *i)
{
	int		j;
	char	*tmp;
	char	*tmp1;
	char	*tmp2;
	char	*tmp3;
	char	*tmp4;
	

	j = *i;
	while (str[++(*i)] != '\"')
		;
	tmp3 = ft_substr(str, 0, j);
	tmp1 = ft_substr(str, j + 1, *i - j - 1);
	tmp2 = ft_strdup(str + *i + 1);
	tmp4 = ft_strjoin(tmp3, tmp1);
	free(tmp3);
	free(tmp1);
	tmp = ft_strjoin(tmp4, tmp2);
	free(tmp2);
	free(tmp4);	
	return (tmp);
}
