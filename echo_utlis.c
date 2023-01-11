/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_utlis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukeles <mukeles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:59:46 by mukeles           #+#    #+#             */
/*   Updated: 2023/01/11 19:12:16 by mukeles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void	print_double_quote(char **arr, int *i)
{
	int		k;
	int		len;
	char	*tmp;
	char	*tmp2;

	k = 0;
	len = ft_strlen(arr[(*i)]);
	tmp2 = arr[(*i)];
	arr[(*i)] = ft_substr(tmp2, 1, len - 2);
	free(tmp2);
	while (arr[(*i)][k] && arr[(*i)])
	{
		if (arr[(*i)][k] != '$' && arr[(*i)][k] != '\'' && arr[(*i)][k] != '\"')
		{
			printf("%c", arr[(*i)][k]);
			k++;
		}
		else if (arr[(*i)][k] == '$')
		{
			while (ft_isalnum(arr[(*i)][k]) != 0 && arr[(*i)])
				k++;
			tmp = dollar(arr[(*i)], &k);
			if (tmp)
				printf("%s", tmp);
			free(tmp);
		}
	}
	(*i)++;
}

void	print_single_quote(char **arr, int *i)
{
	system("leaks minishell");
	int	len;
	char	*tmp;
	len = ft_strlen(arr[(*i)]);
	tmp = arr[(*i)];
	arr[(*i)] = ft_substr(tmp, 1, len - 2);
	if (arr[(*i)])
		printf("%s", arr[(*i)]);
	(*i)++;
	free(tmp);
	
}

void	print_mixed_quote(char **arr, int *i)
{
	int		k;
	char	*tmp;
	int		len;

	k = 0;
	if (arr[(*i)][k] == '\"')
	{
		k++;
		while (arr[(*i)][k])
		{
			if (arr[(*i)][k] != '$' && arr[(*i)][k] != '\"')
			{
				printf("%c", arr[(*i)][k]);
				k++;
			}
			else if (arr[(*i)][k] == '$')
			{
				while (ft_isalnum(arr[(*i)][k]) != 0 && arr[(*i)])
					k++;
				tmp = dollar(arr[(*i)], &k);
				if (tmp)
					printf("%s", tmp);
			}
			else
			{
				k++;
			}
		}
		(*i)++;
	}
	else if (arr[(*i)][k] == '\'')
	{
		len = ft_strlen(arr[(*i)]);
		arr[(*i)] = ft_substr(arr[(*i)], 1, len - 2);
		if (arr[(*i)])
			printf("%s", arr[(*i)]);
		(*i)++;
	}
}
