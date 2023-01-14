/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukeles <mukeles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 21:26:08 by mukeles           #+#    #+#             */
/*   Updated: 2023/01/14 21:26:18 by mukeles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void	execve_error(void)
{
	g_list.exit_status = 127;
	ft_putstr_fd("Could not execute command", 1);
	exit(g_list.exit_status);
}
