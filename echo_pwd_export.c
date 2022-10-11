/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_pwd_export.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukeles <mukeles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 20:41:52 by mukeles           #+#    #+#             */
/*   Updated: 2022/10/11 20:56:41 by mukeles          ###   ########.fr       */
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
	  int	i;
	  int	n;

	  size = 0;
	  n = 0;
	  while(arr[size])
	  {
		  size++;
	  }
	  i = 1;
	  while (!strncmp(arr[i], "-n", 3))
	  {
		  n = 1;
		  i++;
	  }
	  while (arr[i])
	  {
		  printf("%s", arr[i]);
		  if (i != size - 1)
			printf(" ");
		  i++;
	  }
	  if (!n)
		  printf("\n");
}