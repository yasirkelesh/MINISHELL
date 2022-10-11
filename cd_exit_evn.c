/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_exit_evn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukeles <mukeles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 12:19:48 by mukeles           #+#    #+#             */
/*   Updated: 2022/10/11 23:25:36 by mukeles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

t_list *g_env;

char *builtin_str[] = {
  "cd",
  "exit",
  "echo",
  "pwd",
  "env",
  "export",
  "unset"
  
};


int lsh_num_builtins() {
  return sizeof(builtin_str) / sizeof(char *);
}

void env()
{
	t_list *tmp;

	tmp = g_env;
	while(tmp)
	{
		printf("%s\n", (char*)tmp->content);
		tmp = tmp->next;
	}
}

void lsh_cd(char **arr)
{
	int size;

	size = 0;
	while(arr[size])
		size++;
	if (size > 2)
		printf("arguments\n");
	else
	{
		if (chdir(arr[1]))
			printf("error\n");
	}
}

int lsh_exit(char **args)
{
  return 0;
}



int lsh_execute(char **args)
{
  int i = 0;

  if (args[0] == NULL) 
        return 1;
  while(i < lsh_num_builtins())
  {
    printf("argv : %s\n", args[0]);
    if (strcmp(args[0], builtin_str[i]) == 0) 
    {
        if(i == 0)
            lsh_cd(args);
        else if(i == 1)
        {
            lsh_exit(args);
            return 0;
        }
        else if(i == 2)
        {  
           echo(args);
        }
        else if (i == 3)
            pwd();
        else if (i == 4)
            env();
    }
    i++;
  }

  return lsh_launch(args);

}