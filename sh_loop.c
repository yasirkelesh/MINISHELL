/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukeles <mukeles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:29:30 by mukeles           #+#    #+#             */
/*   Updated: 2023/01/14 21:53:02 by mukeles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void	sh_run(char **args, char *line, t_builtin_str *str)
{
	int	i;

	i = 0;
	if (ft_strncmp(args[0], "export", 7))
	{
		while (args[i])
		{
			args[i] = parser(args[i]);
			if (!args[i])
				perror("");
			i++;
		}
	}
	if ((count(line, '>') == 0 && count(line, '<') == 0)
		&& count(line, '|') == 0 && (args[0] != NULL))
		g_list.exit_status = lsh_execute(args, str);
}

void	executive_sh(char **args, char *line, t_builtin_str *str)
{
	if (count(line, '>') > 0 || count(line, '<') > 0)
		check_dir(line);
	else if (count(line, '|') > 0)
		pipe_handle(line, count(line, '|'));
	else if (check_valid(line) && line)
		sh_run(args, line, str);
	else if (!(check_valid(line)) || line)
		printf("quote error\n");
}

void	lsh_loop(t_builtin_str *str)
{
	char	*line;
	char	**args;
	char	*tmp;

	while (1)
	{
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, &ctrl_c);
		line = readline("> ");
		tmp = line;
		if (!line)
		{
			printf("exit\n");
			exit(1);
		}
		add_history(line);
		line = line_edit(tmp);
		if (ft_line_check(line) == 0 || ft_strlen(line) == 0)
			lsh_loop(str);
		args = lsh_split_line(line);
		executive_sh(args, line, str);
		ft_free_str(args);
		free(line);
	}
}
