/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkalyonc <nkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:59:46 by mukeles           #+#    #+#             */
/*   Updated: 2023/01/09 18:06:33 by nkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

char	*find_value(char *key)
{
	t_list	*envp;

	envp = g_list.g_env;
	envp = envp->next;
	while (envp->next)
	{
		if (!ft_strncmp(envp->content, key, ft_strlen(key)))
			return (envp->content + ft_strlen(key) + 1);
		envp = envp->next;
	}
	return ("");
}

char	*find_path(char *cmdline)
{
	int			i;
	char		*temp;
	char		*new_path;
	char		**paths;
	struct stat	s;

	temp = find_value("PATH");
	paths = ft_split(temp, ':');
	i = -1;
	while (paths[++i])
	{
		temp = ft_strjoin("/", cmdline);
		new_path = ft_strjoin(paths[i], temp);
		free(temp);
		if (stat(new_path, &s) == 0)
		{
			ft_free_str(paths);
			return (new_path);
		}
		free(new_path);
	}
	ft_free_str(paths);
	return (ft_strdup(cmdline));
}
