/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_new_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkalyonc <nkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:59:46 by mukeles           #+#    #+#             */
/*   Updated: 2023/01/09 18:06:00 by nkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

t_list	*get_new_env(char **env)
{
	t_list	*new_env;
	int		i;

	new_env = malloc(sizeof(t_list));
	if (!new_env)
		return (new_env);
	i = 0;
	while (env[i])
	{
		ft_lstadd_back(&new_env, ft_lstnew(env[i]));
		i++;
	}
	return (new_env);
}
