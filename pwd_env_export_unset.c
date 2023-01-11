/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_env_export_unset.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukeles <mukeles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 20:41:52 by mukeles           #+#    #+#             */
/*   Updated: 2023/01/11 19:37:42 by mukeles          ###   ########.fr       */
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
	int i;
	i = 1;
	tmp = malloc(sizeof(size_t));

	while (args[i])
	{
		if (exp_check(args[i]) == 0)
			i++;
		else if (exp_check(args[i]) == 1)
		{
					
			unset(ft_split(args[i], '='));
			ft_lstadd_back(&tmp,ft_lstnew(ft_strdup(args[i])));
			i++;
		}
		else if (exp_check(args[i]) == -1)
		{
			printf("export: `%s': not a valid identifier", args[i]);
			i++;
		}
	}
	tmp = tmp->next;
	return tmp;
}
void export(char **args) // bozukk
{
	int i;
	i = 1;
	t_list *tmp;
	if (args[1] == NULL)
	{
		export_env();
		return;
	}
/* 	system("leaks minishell");
	printf("*****------*****\n"); */
	tmp = new_lst_env(args);
	/* system("leaks minishell"); */
	
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

	/* ft_free_str(args); */
}
