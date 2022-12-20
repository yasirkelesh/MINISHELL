/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_pwd_env_export_unset.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkalyonc <nkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 20:41:52 by mukeles           #+#    #+#             */
/*   Updated: 2022/12/08 23:03:22 by nkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"
// halloldu
void pwd()
{
	char *str;

	str = malloc(1000);
	if (!str)
		exit(0);
	str = getcwd(str, 1000);
	if (!str)
		exit(0);
	printf("%s\n", str);
}

void export(char **args)
{

	int i = 1;

	t_list *new;

	printf("args[%d]: %s\n", 0, args[0]);
	printf("args[%d]: %s\n", 1, args[1]);
	printf("args[%d]: %s\n", 2, args[2]);
	while (args[i])
	{
		//unset(ft_split(args[i], '=')); // güncellemek için unsete yolla
		if (exp_check(args[i]) == 1)
		{
			ft_lstadd_back(&g_env, ft_lstnew(args[i]));
			env();
		}
		else if (exp_check(args[i]) == -1)
			printf("export: `%s': not a valid identifier", args[i]);
		i++;
	}
}
void unset(char **args)
{
	int i = 0;
	t_list *new;

	while (args[i])
	{
		if (exp_check(args[i]) == 0)
		{
			ft_list_remove_if(&g_env, args[i]);
		}
		else
			printf("unset: `%s': not a valid identifier\n", args[i]);
		i++;
	}
}