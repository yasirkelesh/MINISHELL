/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shmain.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukeles <mukeles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 12:19:51 by mukeles           #+#    #+#             */
/*   Updated: 2022/10/11 22:31:53 by mukeles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

char *builtin_str2[] = {
    "cd",
    "exit",
    "echo",
    "pwd",
    "export",
    "unset",
    "-n",
    "env"};

int lsh_launch(char **args)
{
  pid_t pid;
  int status;
  int i = 0;
  int k = 0;
  char str1[100] = "/bin/";
  strcat(str1, args[0]);

  if (strcmp(args[0], "echo") == 0 && strcmp(args[1], "-n") == 0)
    k++;
  while (i < lsh_num_builtins() && k == 0)
  {
    if (strcmp(args[0], builtin_str2[i]) == 0)
      k++;
    i++;
  }

  pid = fork();
  if (pid == 0)
  {
    wait(NULL);
    /* printf(" benim pid %d\ngetpid() %d\n", pid, getpid()); */
    if (k == 0)
    {

      if (execve(str1, args, environ) == -1)
      {
        perror("error");
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
  int bufsize = LSH_TOK_BUFSIZE, position = 0;
  char **tokens = malloc(bufsize * sizeof(char *));
  char *token, **tokens_backup;

  if (!tokens)
  {
    exit(EXIT_FAILURE);
  }

  token = my_strtok(line, LSH_TOK_DELIM);
  while (token != NULL)
  {
    tokens[position] = token;
    position++;

    if (position >= bufsize)
    {
      bufsize += LSH_TOK_BUFSIZE;
      tokens_backup = tokens;
      tokens = ft_realloc(tokens, bufsize * sizeof(char *));
      if (!tokens)
      {
        free(tokens_backup);
        exit(EXIT_FAILURE);
      }
    }

    token = my_strtok(NULL, LSH_TOK_DELIM);
  }
  tokens[position] = NULL;
  return tokens;
}

void lsh_loop(void)
{
  char *line;
  char **args;
  int status;
  usleep(5000);
  line = readline("> ");
  args = lsh_split_line(line);
  status = lsh_execute(args);

  free(line);
  free(args);

  while (status)
  {
    usleep(5000);
    line = readline("> ");
    args = lsh_split_line(line);
    status = lsh_execute(args);
    if (!line)
      free(line);
    int i = 0;
    if (!args[i])
    {
      while (args[i])
        free(args[i++]);
    }
  }
}
int main(int argc, char **argv)
{
  lsh_loop();
  return EXIT_SUCCESS;
}
