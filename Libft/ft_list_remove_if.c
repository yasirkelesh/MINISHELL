/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukeles <mukeles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:59:46 by mukeles           #+#    #+#             */
/*   Updated: 2023/01/16 22:48:45 by mukeles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

void	ft_list_remove_if2(t_list *last, t_list *current)
{
	if (last)
		last->next = current->next;
	else
		current = current->next;
	free(current);
	current = NULL;
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref)
{
	t_list	*current;
	t_list	*last;
	t_list	*next;
	char	**eq_env;
	char	eq;

	eq = '=';
	current = *begin_list;
	if (!current->content)
		current = current->next;
	last = NULL;
	eq_env = NULL;
	while (current)
	{
		eq_env = ft_split(current->content, eq);
		next = current->next;
		if (ft_strcmp(eq_env[0], data_ref) == 0)
			ft_list_remove_if2(last, current);
		else
			last = current;
		current = next;
		ft_free_str(eq_env);
	}
}
