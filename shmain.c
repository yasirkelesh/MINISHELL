/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shmain.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkalyonc <nkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 02:01:50 by mukeles           #+#    #+#             */
/*   Updated: 2023/01/09 18:04:33 by nkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int	main(int argc, char **argv, char **env)
{
	t_builtin_str	*str;

	(void)argc;
	(void)argv;
	str = malloc(sizeof(t_builtin_str));
	if (!str)
		return (-1);
	str->builtin_str = malloc(sizeof(char) * 999);
	if (!str->builtin_str)
		return (-1);
	if (!str)
		return (0);
	init(str);
	g_list.g_env = get_new_env(env);
	lsh_loop(str);
	free(str->builtin_str);
	free(str);
	free(g_list.g_env);
	return (EXIT_SUCCESS);
}
