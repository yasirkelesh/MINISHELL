/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukeles <mukeles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:59:46 by mukeles           #+#    #+#             */
/*   Updated: 2023/01/14 23:27:06 by mukeles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void	redir_out_handle(char **str, int i)
{
	t_redir_var	variables;

	variables.j = 0;
	variables.m = 0;
	variables.k = 0;
	variables.temp = (char *)malloc(sizeof(char) * 100);
	variables.flags = O_WRONLY | O_CREAT;
	if (str[i + 2])
		i = check_another_redir(str, i);
	variables.file = ft_strdup(str[i + 1]);
	while (ft_strncmp(str[variables.k], ">", 1))
	{
		variables.m = 0;
		while (str[variables.k][variables.m])
			variables.temp[variables.j++] = str[variables.k][variables.m++];
		variables.temp[variables.j] = ' ';
		variables.j++;
		variables.k++;
	}
	variables.temp[variables.j - 1] = '\0';
	variables.fd = open(variables.file, variables.flags | O_TRUNC, 0777);
	execute_dir(variables.temp, variables.fd, 1);
	free(variables.file);
	free(variables.temp);
}

void	redir2_out_handle(char **str, int i)
{
	char	*temp;
	int		fd;
	int		flags;
	char	*file;

	flags = O_WRONLY | O_CREAT;
	temp = sub_redir(str, i);
	if (str[i + 2])
		i = check_another_redir(str, i);
	file = ft_strdup(str[i + 1]);
	fd = open(file, flags | O_APPEND, 0777);
	execute_dir(temp, fd, 1);
	if (temp[0] != '\0')
		free(temp);
	if (file[0] != '\0')
		free(file);
}

int	redirect_out(char **str, int i)
{
	if (str[i + 1] == NULL || str[i + 1][0] == '>'
			|| str[i + 1][0] == '<' || str[i + 1][0] == '\0')
		return (0);
	if (!ft_strcmp(str[i], ">>"))
	{
		redir2_out_handle(str, i);
		return (0);
	}
	else if (!ft_strcmp(str[i], ">"))
	{
		redir_out_handle(str, i);
		return (0);
	}
	return (1);
}
