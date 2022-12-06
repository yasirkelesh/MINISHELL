/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_pwd_export.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukeles <mukeles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 20:41:52 by mukeles           #+#    #+#             */
/*   Updated: 2022/12/02 14:42:35 by mukeles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

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
void echo(char **arr)
{

	int size;
	int i;
	int n;
	usleep(1000);
	size = 0;
	n = 0;
	while (arr[size])
	{
		size++;
	}
	i = 1;
	while (strncmp(arr[i], "-n", 3) == 0)
	{
		n = 1;
		i++;
	}
 	while (arr[i])
	{
/* 		if(arr[i][0] != '$') *///dolar gelirse atlasın diye
		{
			printf("%s", arr[i]);
 			if (i != size - 1)
				printf(" ");
			i++;
		}
/* 		else
			i++; */
	} 
	if (!n)
		printf("\n");
}

void export(char **args)
{

	int i = 1;

	t_list *new;

/* 	printf("args[%d]: %s\n",0,args[0]);
	printf("args[%d]: %s\n",1,args[1]);
	printf("args[%d]: %s\n",2,args[2]); */
	while(args[i])
	{
		unset(ft_split(args[i], '='));//güncellemek için unsete yolla
		printf("%d\n",exp_env_check(args[i + 1]));
		if(exp_env_check(args[i + 1]))
		{
			//free(args[i]);
			args[i] = strcat(args[i],args[i + 1]);
			
			printf("export args: %s\n",args[i]);
		}
		 
		if(exp_check(args[i]) == 1)
		{
			new = ft_lstnew(args[i]);
			ft_lstadd_back(&g_env, new);
		}
		else if(exp_check(args[i]) == -1)
			printf("export: `%s': not a valid identifier", args[i]);
		i++;
	}
	//printf("exportaki : %s\n", args[1]);

	//uygun formatta olanları listeye ekle


}
void unset(char **args)
{
  int i = 0;
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