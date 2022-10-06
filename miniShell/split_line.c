#include "mini_shell.h"

char **lsh_split_line(char *line)
{
  int bufsize = LSH_TOK_BUFSIZE, position = 0;
  char **tokens = malloc(bufsize * sizeof(char*));
  char *token;

  if (!tokens) {
    exit(EXIT_FAILURE);
  }

  token = strtok(line, LSH_TOK_DELIM);
  while (token != NULL) 
  {
    tokens[position] = token;
    position++;
    token = strtok(NULL, LSH_TOK_DELIM);
  }
  
  tokens[position] = NULL;
  return tokens;
}