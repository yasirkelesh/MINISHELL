/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chec_valid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkalyonc <nkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:59:46 by mukeles           #+#    #+#             */
/*   Updated: 2023/01/09 18:08:27 by nkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

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
			if (q == 0)
				q++;
			else
				q--;
		}
		if (line[i] == '\'' && q == 0)
		{
			if (q2 == 0)
				q2++;
			else
				q2--;
		}
		i++;
	}
	if (q != 0 || q2 != 0)
		return (0);
	else
		return (1);
}
