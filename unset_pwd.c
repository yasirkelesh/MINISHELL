/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_pwd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukeles <mukeles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:11:07 by mukeles           #+#    #+#             */
/*   Updated: 2023/01/14 18:11:47 by mukeles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void	pwd(void)
{
	char	*str;

	str = malloc(1000);
	if (!str)
		exit(0);
	str = getcwd(str, 1000);
	if (!str)
		exit(0);
	printf("%s\n", str);
	free(str);
}

void	unset(char **args)
{
	int	i;

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
