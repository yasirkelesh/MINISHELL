/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkalyonc <nkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:59:46 by mukeles           #+#    #+#             */
/*   Updated: 2023/01/09 18:08:02 by nkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

char	*add_space(void)
{
	char	*tmp = malloc(2 * sizeof(char));

	tmp[0] = ' ';
	tmp[1] = '\0';
	return (tmp);
}

char	*handle_end_of_string(char *str, int j, int i)
{
	return (ft_substr(str, j, i - j));
}

char	*handle_double_quotes(char *str, int j, int *i, char *tmp)
{
	(*i)++;
	if (str[*i] != '\"')
	{
		while (str[*i] != '\"' && str[*i] != '\0')
		{
			(*i)++;
		}
		(*i)++;
		tmp = ft_substr(str, j, *i - (j));
	}
	else
	{
		tmp = ft_substr(str, j, *i - (j + 1));
	}
	return (tmp);
}

char	*handle_single_quotes(char *str, int j, int *i, char *tmp)
{
	(*i)++;
	if (str[*i] != '\'')
	{
		while (str[*i] != '\'' && str[*i] != '\0')
		{
			(*i)++;
		}
		(*i)++;
		tmp = ft_substr(str, j, *i - (j));
	}
	else
	{
		tmp = ft_substr(str, j, *i - (j + 1));
	}
	return (tmp);
}

char	*handle_dollar_sign(char *str, int j, int *i)
{
	(*i)++;
	while (ft_isalnum(str[*i]) && str[*i] != '\0')
	{
		(*i)++;
	}
	return (ft_substr(str, j, *i - j));
}

char	*handle_other_cases(char *str, int j, int *i)
{
	while (str[*i] != ' ' && str[*i] != '\''
		&& str[*i] != '\"' && str[*i] != '\0')
	{
		(*i)++;
	}
	return (ft_substr(str, j, *i - j));
}
