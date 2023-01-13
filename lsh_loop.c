/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsh_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukeles <mukeles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:59:46 by mukeles           #+#    #+#             */
/*   Updated: 2023/01/13 20:13:02 by mukeles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"
// hallloldu
void lsh_loop(t_builtin_str *str)
{
  char *line;
  char **args;
  char *tmp;
  int i = 0;
  int status = 1;

  while (status)
  {
    signal(SIGQUIT, SIG_IGN);
    signal(SIGINT, &ctrl_c);
    line = readline("> ");
    if (!line)
    {
      printf("exit\n");
      exit(1);
    }

    add_history(line);

    tmp = line;
    line = line_edit(tmp);
    free(tmp);
    if (ft_line_check(line) == 0 || ft_strlen(line) == 0)
    {
      free(line);
      lsh_loop(str);
    }
    args = lsh_split_line(line);

    if (count(line, '>') > 0 || count(line, '<') > 0)
    {
      check_dir(line);
    }
    else if (count(line, '|') > 0)
    {
      pipe_handle(line, count(line, '|'));
    }
    else if (check_valid(line) && line)
    {
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
/*       else
      {
        
      } */
      i = 0;

      if ((count(line, '>') == 0 && count(line, '<') == 0) && count(line, '|') == 0 && (args[0] != NULL))
        status = lsh_execute(args, str);
    }
    ft_free_str(args);
    free(line);
  }
  i = 0;
}
