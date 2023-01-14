/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chec_valid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukeles <mukeles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:59:46 by mukeles           #+#    #+#             */
/*   Updated: 2023/01/13 18:39:10 by mukeles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int	chek_q(int q)
{
	if (q == 0)
		q++;
	else
		q--;
	return (q);
}

int	chek_q2(int q2)
{
	if (q2 == 0)
		q2++;
	else
		q2--;
	return (q2);
}

int	check_valid(char *line)
{
	int	i;
	int	q;
	int	q2;

	i = 0;
	q = 0;
	q2 = 0;
	while (line[i])
	{
		if (line[i] == '\"' && q2 == 0)
		{
			q = chek_q(q);
		}
		if (line[i] == '\'' && q == 0)
		{
			q2 = chek_q2(q2);
		}
		i++;
	}
	if (q != 0 || q2 != 0)
		return (0);
	else
		return (1);
}
