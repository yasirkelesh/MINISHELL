/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_help_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukeles <mukeles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 12:19:48 by mukeles           #+#    #+#             */
/*   Updated: 2022/10/08 13:26:39 by mukeles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

char *builtin_str[] = {
  "cd",
  "help",
  "exit"
};

int lsh_num_builtins() {
  return sizeof(builtin_str) / sizeof(char *);
}

int lsh_cd(char **args)
{
  if (args[1] == NULL) {
    fprintf(stderr, "lsh: expected argument to \"cd\"\n");
  } else {
    if (chdir(args[1]) != 0) {
      perror("lsh");
    }
  }
  return 1;
}

int lsh_help(char **args)
{
  int i = 0;
  printf("YASİR KELES's LSH\n");
  printf("Type program names and arguments, and hit enter.\n");
  printf("The following are built in:\n");

    while(i < lsh_num_builtins())
        printf("  %s\n", builtin_str[i++]);


  printf("Use the man command for information on other programs.\n");
  return 1;
}

int lsh_exit(char **args)
{
  return 0;
}

int lsh_execute(char **args)
{
  int i = 0;

  if (args[0] == NULL) {
    return 1;
  }
  while(i < lsh_num_builtins())
  {
    if (strcmp(args[0], builtin_str[i]) == 0) {
        if(i == 0)
            lsh_cd(args);
        else if(i == 1)
            lsh_help(args);
        else if(i == 2)
            lsh_exit(args);
    }
    i++;
  }

  return lsh_launch(args);
}