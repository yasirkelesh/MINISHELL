/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_mix2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukeles <mukeles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:13:44 by mukeles           #+#    #+#             */
/*   Updated: 2023/01/14 18:15:03 by mukeles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void	mixed_redir2(char *str, char *temp, int fd)
{
	int	fdd;
	int	stdout_copy;

	stdout_copy = dup(1);
	fdd = open(str, O_WRONLY | O_CREAT | O_APPEND, 0777);
	dup2(fdd, 1);
	close(fdd);
	execute_dir(temp, fd, 0);
	dup2(stdout_copy, 1);
	close(stdout_copy);
}

void	mixed_redir(char *str, char *temp, int fd)
{
	int	fdd;
	int	stdout_copy;

	stdout_copy = dup(1);
	fdd = open(str, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	dup2(fdd, 1);
	close(fdd);
	execute_dir(temp, fd, 0);
	dup2(stdout_copy, 1);
	close(stdout_copy);
}
