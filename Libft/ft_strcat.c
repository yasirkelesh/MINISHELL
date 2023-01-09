/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkalyonc <nkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:59:46 by mukeles           #+#    #+#             */
/*   Updated: 2023/01/09 18:10:07 by nkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcat(char *dest, const char *src)
{
	size_t	i;
	size_t	dsize;

	dsize = 0;
	while (dest[dsize] != '\0')
		dsize ++;
	i = dsize;
	while (src[dsize - i])
	{
		dest[dsize] = src[dsize - i];
		dsize++;
	}
	return (i + ft_strlen(src));
}
