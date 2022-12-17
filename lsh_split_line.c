#include "mini_shell.h"
// halloldu
char **lsh_split_line(char *line)
{
  int i;
  int j;
  int size;
  char **arr;

  size = get_cmd_num(line);
  arr = malloc(sizeof(char *) * (size + 1));


  if (!arr)
    return NULL;
  j = 0;
  i = 0;
 
  while (line[i])
  {
    while (line[i] == ' ' && line[i] != '\0')
      i++;
    arr[j] = command(line, &i);
    j++;
    
  }
  arr[j] = NULL;


  return (arr);
}