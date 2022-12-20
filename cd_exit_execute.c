/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_exit_execute.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkalyonc <nkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 12:19:48 by mukeles           #+#    #+#             */
/*   Updated: 2022/12/08 23:01:55 by nkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

// halloldu
int lsh_num_builtins(t_builtin_str *str, char *args)
{
  int i = 0;

  while (i <= 6)
  {
    // printf("args : %s\n, str : %s\n",args, str->builtin_str[i]);
    // printf("strcmp test %d \n ",strcmp(args, str->builtin_str[i]));
    if (!ft_strcmp(args, str->builtin_str[i]))
      return i;
    i++;
  }
  return -1;
}

void lsh_cd(char **arr)
{
  int size;
  size = 0;
  while (arr[size])
    size++;
  if (size > 2)
    printf("arguments\n");
  else if (size == 1)
  {
    char *str;
    int i =0;
    str = getenv("HOME");
    chdir(str);
  }

  else
  {
    if (chdir(arr[1]))
      printf("error\n");
  }
}

int lsh_exit(char **args)
{
  (void)args;
  return 0;
}

int lsh_execute(char **args, t_builtin_str *str)
{
  int i = 8;

  if (!ft_strcmp(args[0], "echo") && args[1] == NULL) // sadece ilk argüman varsa
    return 1;
  i = lsh_num_builtins(str, args[0]);

  if (i == 0)
    lsh_cd(args);
  else if (i == 1)
  {
    lsh_exit(args);
    return 0;
  }
  else if (i == 2)
  {
    echo(args);
  }
  else if (i == 3)
    pwd();
  else if (i == 4)
    env();
  else if (i == 5)
    export(args);
  else if (i == 6)
    unset(args);

  return lsh_launch(args, str);
}
