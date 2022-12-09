/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukeles <mukeles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:58:35 by mukeles           #+#    #+#             */
/*   Updated: 2022/02/15 10:58:36 by mukeles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int nn)
{
	int	len;

	len = 0;
	if (nn == 0)
		return (1);
	while (nn)
	{
		len++;
		nn /= 10;
	}
	return (len);
}

static char	*writetos(char *str, int i, long nbr, int n)
{
	str[i--] = '\0';
	while (nbr > 0)
	{
		str[i--] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (n == 0 && str[1] == '\0')
		str[0] = '0';
	else if (n < 0)
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nbr;
	size_t	i;

	i = 0;
	nbr = n;
	if (nbr < 0)
	{
		i = 1;
		nbr = -nbr;
	}
	i += ft_intlen(n);
	str = (char *)malloc(i + 1);
	if (!str)
		return (NULL);
	return (writetos(str, i, nbr, n));
}
/*int main()
{
	//char str[284]= "1265";

	printf("%s" , ft_itoa(-1265));
}*/
