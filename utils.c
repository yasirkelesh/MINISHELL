/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukeles <mukeles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:59:46 by mukeles           #+#    #+#             */
/*   Updated: 2023/01/10 17:53:52 by mukeles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int	count(char *str, char c)
{
	int	i;
	int	count;

	count = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == c)
			count++;
	}
	return (count);
}

void	ft_putnstr(char *str, int n)
{
	int		i;

	i = -1;
	if (n < 0)
	{
		while (str[++i] && i < (int)ft_strlen(str) + n)
			ft_putchar_fd(str[i], 1);
	}
	else
	{
		while (str[++i] && i < n)
			ft_putchar_fd(str[i], 1);
	}
}

char *line_edit(char *line)
{
	int i;
	char *tmp;
	i = 0;
	while(line[i] <= 32 && line[i])
		i++;
	tmp = ft_substr(line,i,ft_strlen(line));
	system("leaks minishell > leaks5.txt");
	return tmp;
	
}

t_list	**add_list(char **str, t_list **mini)
{
	int		i;
	t_list	*new;

	i = 0;
	while (str[i])
	{
		new = ft_lstnew(str[i]);
		ft_lstadd_back(mini, new);
		i++;
	}
	return (mini);
}
