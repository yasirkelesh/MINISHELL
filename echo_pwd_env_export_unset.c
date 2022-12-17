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
		unset(ft_split(args[i], '=')); // güncellemek için unsete yolla
		//printf("%d\n", exp_env_check(args[i + 1]));
		if (exp_check(args[i]) == 1)
		{
			printf("testenv \n");
			new = ft_lstnew(args[i]);
			printf("test new %s\n", (char *)new->content);
			ft_lstadd_back(&g_env, new);
		}
/* 		if (exp_env_check(args[i + 1]) == 0)
		{
			// free(args[i]);
			args[i] = ft_strcat(args[i], args[i + 1]);
			printf("export args: %s\n", args[i]);

		} */

		else if (exp_check(args[i]) == -1)
			printf("export: `%s': not a valid identifier", args[i]);
		i++;
	}
	// printf("exportaki : %s\n", args[1]);

	// uygun formatta olanları listeye ekle
}
void unset(char **args)
{
	int i = 0;
	
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