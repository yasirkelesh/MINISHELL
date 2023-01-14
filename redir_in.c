/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_exit_execute.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukeles <mukeles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 12:19:48 by mukeles           #+#    #+#             */
/*   Updated: 2023/01/13 16:43:52 by mukeles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void	redir_in_handle(char **str, int i)
{
	char	*file;
	int		fd;
	char	*temp;

	temp = sub_redir(str, i);
	file = ft_strdup(str[i + 1]);
	fd = open(file, O_RDONLY, 0777);
	if (str[i + 2] && str[i + 2][0] == '>')
	{
		if (str[i + 2][1] || str[i + 2][1] == '>')
			mixed_redir2(str[i + 3], temp, fd);
		else
			mixed_redir(str[i + 3], temp, fd);
	}	
	else
		execute_dir(temp, fd, 0);
	free (file);
	free (temp);
}

void	redir2_in_handle(char **str, int i)
{
	int		fd;
	char	*eof;
	char	*temp;

	temp = sub_redir(str, i);
	if (str[i + 2] && str[i + 2][0] == '>')
	{
		eof = ft_strdup(str[i + 1]);
		here_doc2("b.txt", eof);
		fd = open("b.txt", O_RDONLY, 0777);
		mixed_redir(str[i + 3], temp, fd);
	}	
	else
	{
		eof = ft_strdup(str[i + 1]);
		here_doc(TMP_FILE, eof);
		fd = open(TMP_FILE, O_RDONLY, 0777);
		execute_dir(temp, fd, 0);
	}
	if (eof[0] != '\0')
		free(eof);
	if (temp[0] != '\0')
		free(temp);
}

int	redirect_in(char **str, int i)
{
	if (str[i + 1] && !ft_strcmp(str[i], "<"))
	{
		redir_in_handle(str, i);
		return (0);
	}
	else if (str[i + 1] && !ft_strcmp(str[i], "<<"))
	{
		redir2_in_handle(str, i);
		return (0);
	}
	return (1);
}
