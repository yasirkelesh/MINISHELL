#include "mini_shell.h"
// halloldu
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
  // printf("line : %s\n", line);
  while (line[i])
  {
    while (line[i] == ' ' && line[i] != '\0')
      i++;
    arr[j++] = command(line, &i);
   if (j >= size && size > 0)
    {
      printf("split test\n");
      arr = mem_wide(arr, size);
    } 
    printf("arr : %s\n", arr[j - 1]);
  }
  k = 0;


  return (arr);
}