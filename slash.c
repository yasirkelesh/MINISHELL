/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkalyonc <nkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:59:46 by mukeles           #+#    #+#             */
/*   Updated: 2023/01/09 18:03:47 by nkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

char	*slash(char *str, int *i)
{
	char	*tmp;

	tmp = ft_substr(str, 0, *i);
	ft_strjoin(tmp, str + *i + 1);
	++(*i);
	return (tmp);
}
