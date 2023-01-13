/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_env_export_unset.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukeles <mukeles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 20:41:52 by mukeles           #+#    #+#             */
/*   Updated: 2023/01/13 16:35:33 by mukeles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void pwd(void)
{
	char *str;

	str = malloc(1000);
	if (!str)
		exit(0);
	str = getcwd(str, 1000);
	if (!str)
		exit(0);
	printf("%s\n", str);
	free(str);
}
static void lstadd_lst(t_list **lst, t_list **new)
{
	t_list *tmp;
	tmp = *lst;

	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *new;
}
t_list *new_lst_env(char **args)
{
	t_list *tmp;
	t_list *p;
	char **tmp1;
	
	int i;
	i = 1;

	while (args[i])
	{
		if (exp_check(args[i]) == 0)
			i++;
		else if (exp_check(args[i]) == 1)
		{
			if (i == 1)
			{
				tmp1 = ft_split(args[i], '=');
				unset_exp(tmp1);
				tmp = ft_lstnew(ft_strdup(args[i]));
			}
			else
			{
				p = tmp;
				tmp1 = ft_split(args[i], '=');				
				unset_exp(tmp1);
				ft_lstadd_back(&tmp, ft_lstnew(ft_strdup(args[i])));
			}
			i++;
		}
		else if (exp_check(args[i]) == -1)
		{
			printf("export: `%s': not a valid identifier", args[i]);
			i++;
		}
	}
	return tmp;
}

void export(char **args) // 
{
	int i;
	i = 1;
	t_list *tmp;
	if (args[1] == NULL)
	{
		export_env();
		return;
	}
	tmp = new_lst_env(args);
	lstadd_lst(&g_list.g_env, &tmp);
}

void unset(char **args)
{
	int i;

	i = 0;
	while (args[i])
	{
		
		if (exp_check(args[i]) == 0)
		{
			ft_list_remove_if(&g_list.g_env, args[i]);
		}
		else
			printf("unset: `%s': not a valid identifier\n", args[i]);
		i++;
	}
}
void unset_exp(char **args)
{
	int i;

	i = 0;

	if (exp_check(args[i]) == 0)
	{
		ft_list_remove_if(&g_list.g_env, args[i]);
	}
	ft_free_str(args);
}
