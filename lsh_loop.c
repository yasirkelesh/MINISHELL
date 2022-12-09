#include "mini_shell.h"
// hallloldu
void lsh_loop(t_builtin_str *str)
{
  char *line;
  char **args;
  int i;
  int len;
  int d;
  int status;

  while (status)
  {
    signal(SIGQUIT, SIG_IGN);
    signal(SIGINT, &ctrl_c);
    line = readline("> ");
    if (!line)
    {
      printf("exit\n");
      exit(1);
    }
    add_history(line);
    args = lsh_split_line(line);
    len = get_cmd_num(line);
    i = 0;
    if (check_valid(line) && line)
    {
      i = 0;
      while (args[i])
      {
        // args[i] = parser(args[i]);

        printf("parser dan önce args[%d]: %s\n", i, args[i]);
        args[i] = parser(args[i]);
        if (!args[i])
          perror("");
        printf("parser dan sonra args[%d]: %s\n", i, args[i]);
        i++;

        //i++;

        if (i > len)
        {
          printf("test mem\n");

          args = mem_wide(args, len);
        }
      }
      int i = 0;

      status = lsh_execute(args, str);
      while (args[i])
        free(args[i++]);
    }
  }
  i = 0;
  while (args[i])
  {
    free(args[i]);
    i++;
  }
}