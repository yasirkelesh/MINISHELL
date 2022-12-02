#include "mini_shell.h"
char **lsh_split_line(char *line)
{
  int i;
  int j;
  int k;
  int size;
  char **arr;

  size = get_cmd_num(line);
  arr = malloc(sizeof(char *) * (size + 2));

  if (!arr)
    return NULL;
  j = 0;
  i = 0;
  k = 0;
  //printf("line : %s\n", line);
  while (line[i])
  {
    while (line[i] == ' ' && line[i] != '\0')
      i++;
    arr[j++] = command(line, &i);
    printf("arr : %s\n", arr[j - 1]);
  }
   k = 0;
  while(arr[k])
  {
    printf("arr de ki : *%s*\n", arr[k]);
    k++;
  }
  printf("test\n");

  return (arr);
}