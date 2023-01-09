/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkalyonc <nkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:59:46 by mukeles           #+#    #+#             */
/*   Updated: 2023/01/09 18:06:48 by nkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void	env(void)
{
	t_list	*tmp;

	tmp = g_list.g_env;
	tmp = tmp->next;
	while (tmp)
	{
		printf("%s\n", (char *)tmp->content);
		tmp = tmp->next;
	}
}

void	export_env(void)
{
	t_list	*tmp;

	tmp = g_list.g_env;
	tmp = tmp->next;
	while (tmp)
	{
		printf("declare -x %s\n", (char *)tmp->content);
		tmp = tmp->next;
	}
}
