/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shmain.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukeles <mukeles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 02:01:50 by mukeles           #+#    #+#             */
/*   Updated: 2022/10/29 11:53:13 by mukeles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"
extern char **environ;

int lsh_launch(char **args, t_builtin_str *str)
{
  pid_t pid;
  int status;
  int i = 0;
  int k = 0;
  char str1[100] = "/bin/";

  strcat(str1, args[0]);
  if ((lsh_num_builtins(str, args[0]) != -1) && k == 0)
  {
    k++;
  }
  // printf("str1 : %s",str1);
  pid = fork();
  if (pid == 0)
  {
    wait(NULL);
    usleep(1000);
    if (k == 0)
    {
      // printf(" benim pid %d\ngetpid() %d\n", pid, getpid());
      if (execve(str1, args, environ) == -1)
      {
        perror("");
      }
    }
    else
      return 1;

    exit(EXIT_FAILURE);
  }
  else if (pid < 0)
  {
    // Error forking
    perror("lsh");
  }
  else
  {
    wait(NULL);
    /* printf(" benim pid %d\ngetpid() %d\n", pid, getpid()); */
    waitpid(pid, &status, WUNTRACED);
    while (!WIFEXITED(status) && !WIFSIGNALED(status))
    {
      waitpid(pid, &status, WUNTRACED);
    }
  }

  return 1;
}

char **lsh_split_line(char *line)
{
  int i;
  int j;
  int k;
  int size;
  char **arr;

  size = get_cmd_num(line);
  arr = malloc(sizeof(char *) * (size + 1));

  if (!arr)
    return NULL;
  j = 0;
  i = 0;
  k = 0;
  printf("line : %s\n", line);
  while (line[i])
  {
    if(line[i] == ' ' && line[i] != '\0')//(echo  $HOME          $HOME)
    //("echo") (" ")("$HOME")(" ")("$HOME")
    {
      while (line[i] == ' ' && line[i] != '\0')
        i++;
      arr[j++] = " ";
      printf("arr1 : *%s*\n", arr[j - 1]);
    }
    arr[j++] = command(line, &i);
    printf("arr2 : *%s*\n", arr[j - 1]);
  }

  arr[j] = NULL;

  return (arr);
}

int main(int argc, char **argv, char **env)
{
  t_builtin_str *str;

  str = malloc(sizeof(t_builtin_str));
  str->builtin_str = malloc(sizeof(char) * 999);
  if (!str)
    return (0);
  init(str);

  g_env = get_new_env(env);

  lsh_loop(str);
  return EXIT_SUCCESS;
}
