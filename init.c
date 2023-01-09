/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkalyonc <nkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 00:21:03 by mukeles           #+#    #+#             */
/*   Updated: 2023/01/09 18:05:50 by nkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void	init(t_builtin_str *str)
{
	str->builtin_str[0] = "cd";
	str->builtin_str[1] = "exit";
	str->builtin_str[2] = "echo";
	str->builtin_str[3] = "pwd";
	str->builtin_str[4] = "env";
	str->builtin_str[5] = "export";
	str->builtin_str[6] = "unset";
}
