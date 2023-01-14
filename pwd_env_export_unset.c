/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_env_export_unset.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukeles <mukeles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 20:41:52 by mukeles           #+#    #+#             */
/*   Updated: 2023/01/14 18:11:58 by mukeles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

static void	lstadd_lst(t_list **lst, t_list **new)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *new;
}

static t_list	*exp_new(char **args, int *i, t_list *tmp)
{
	char	**tmp1;

	if ((*i) == 1)
	{
		tmp1 = ft_split(args[(*i)], '=');
		unset_exp(tmp1);
		tmp = ft_lstnew(ft_strdup(args[(*i)]));
	}
	else
	{
		tmp1 = ft_split(args[(*i)], '=');
		unset_exp(tmp1);
		ft_lstadd_back(&tmp, ft_lstnew(ft_strdup(args[(*i)])));
	}
	(*i)++;
	return (tmp);
}

t_list	*new_lst_env(char **args)
{
	t_list	*tmp;
	int		i;

	i = 1;
	while (args[i])
	{
		if (exp_check(args[i]) == 0)
			i++;
		else if (exp_check(args[i]) == 1)
			tmp = exp_new(args, &i, tmp);
		else if (exp_check(args[i]) == -1)
			printf("export: `%s': not a valid identifier", args[i++]);
	}
	return (tmp);
}

void	export(char **args)
{
	t_list	*tmp;

	if (args[1] == NULL)
	{
		export_env();
		return ;
	}
	tmp = new_lst_env(args);
	lstadd_lst(&g_list.g_env, &tmp);
}

void	unset_exp(char **args)
{
	int	i;

	i = 0;
	if (exp_check(args[i]) == 0)
	{
		ft_list_remove_if(&g_list.g_env, args[i]);
	}
	ft_free_str(args);
}
