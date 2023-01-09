/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkalyonc <nkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:59:46 by mukeles           #+#    #+#             */
/*   Updated: 2023/01/09 18:09:08 by nkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref)
{
	t_list	*current;
	t_list	*last;
	t_list	*next;
	char	**eq_env;
	char	eq;

	eq = '=';
	current = *begin_list;
	current = current->next;
	last = NULL;
	eq_env = NULL;
	while (current)
	{
		eq_env = ft_split(current->content, eq);
		next = current->next;
		if (ft_strcmp(eq_env[0], data_ref) == 0)
		{
			if (last)
				last->next = current->next;
			else
				current = current->next;
			free(current->content);
			free(current);
			current = NULL;
		}
		else
		{
			last = current;
		}
		current = next;
		ft_free_str(eq_env);
	}
}
