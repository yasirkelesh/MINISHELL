/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shmain.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukeles <mukeles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 12:19:51 by mukeles           #+#    #+#             */
/*   Updated: 2022/10/11 16:58:38 by mukeles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int lsh_launch(char **args)
{
  pid_t pid;
  int status;
  
  char str1[100] = "/bin/";
  strcat(str1, args[0]);

  pid = fork();
  if (pid == 0) {
    
    wait(NULL);
    usleep(100);
    printf("baba pid %d\nbenim pid %d\n", pid, getpid());
    printf("str1 %s\n", str1);
    if (execve(str1, args,environ ) == -1) {
      perror("error");
    }
    exit(EXIT_FAILURE);
  } else if (pid < 0) {
    // Error forking
    perror("lsh");
  } else {
    //parent
    
    wait(NULL);
    printf("baba pid %d\nbenim pid %d\n", pid, getpid());
    waitpid(pid, &status, WUNTRACED);
    while (!WIFEXITED(status) && !WIFSIGNALED(status)){
      waitpid(pid, &status, WUNTRACED);
    } 
  }

  return 1;
}

char **lsh_split_line(char *line)
{
  int bufsize = LSH_TOK_BUFSIZE, position = 0;
  char **tokens = malloc(bufsize * sizeof(char*));
  char *token, **tokens_backup;

  if (!tokens) {
    exit(EXIT_FAILURE);
  }

  token = my_strtok(line, LSH_TOK_DELIM);
  while (token != NULL) {
    tokens[position] = token;
    position++;

    if (position >= bufsize) {
      bufsize += LSH_TOK_BUFSIZE;
      tokens_backup = tokens;
      tokens = ft_realloc(tokens, bufsize * sizeof(char*));
      if (!tokens) {
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

    line = readline("> ");
    args = lsh_split_line(line);
    status = lsh_execute(args);

    free(line);
    free(args);

  while (status){
    line = readline("> ");
    args = lsh_split_line(line);
    status = lsh_execute(args);

    free(line);
    free(args);
  } 
}
int main(int argc, char **argv)
{
  lsh_loop();
  return EXIT_SUCCESS;
}
