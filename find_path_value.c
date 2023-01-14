/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukeles <mukeles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:59:46 by mukeles           #+#    #+#             */
/*   Updated: 2023/01/14 18:20:59 by mukeles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

static int	is_executable(char *cmd_path)
{
	if (access(cmd_path, 0) == 0)
		return (1);
	return (0);
}

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

int	find_path2(char *cmdline)
{
	t_temp_var	a;
	struct stat	s;

	if (cmdline == NULL)
		return (0);
	if (is_executable(cmdline) == 1)
		return (1);
	a.tmp = find_value("PATH");
	a.tmp_2ar = ft_split(a.tmp, ':');
	a.i = -1;
	while (a.tmp_2ar[++a.i])
	{
		a.tmp = ft_strjoin("/", cmdline);
		a.tmp2 = ft_strjoin(a.tmp_2ar[a.i], a.tmp);
		free(a.tmp);
		if (stat(a.tmp2, &s) == 0)
		{
			free(a.tmp2);
			ft_free_str(a.tmp_2ar);
			return (1);
		}
		free(a.tmp2);
	}
	ft_free_str(a.tmp_2ar);
	return (0);
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
