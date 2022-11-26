/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_exit_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukeles <mukeles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 12:19:48 by mukeles           #+#    #+#             */
/*   Updated: 2022/10/21 11:09:44 by mukeles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"



int lsh_num_builtins(t_builtin_str *str, char *args)
{
  int i = 0;

  while (i <= 6)
  {
    //printf("args : %s\n, str : %s\n",args, str->builtin_str[i]);
    //printf("strcmp test %d \n ",strcmp(args, str->builtin_str[i]));
    if (!strcmp(args, str->builtin_str[i]))
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
  else
  {
    if (chdir(arr[1]))
      printf("error\n");
  }
}

int   lsh_exit(char **args)
{
  (void)args;
  return 0;
}

int lsh_execute(char **args, t_builtin_str *str)
{
  int i = 8;

  if (args[0] == NULL || args[1] == NULL)//sadece ilk argüman varsa
    return 1;
  i = lsh_num_builtins(str,args[0]);  
  
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
  else if(i == 5)
    export(args);
  else if(i == 6)
    unset(args);

  return lsh_launch(args, str);
}

void unset(char **args)
{
  int i = 1;
  t_list *new;

  while(args[i])
  {
      if(exp_check(args[i]) == 0)
      {
        ft_list_remove_if(&g_env,args[i]);
      }
      else
        printf("unset: `%s': not a valid identifier\n",args[i]);
      i++;
  } 
}