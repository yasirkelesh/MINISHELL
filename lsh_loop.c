#include "mini_shell.h"
 //hallloldu
void lsh_loop(t_builtin_str *str)
{
  char *line;
  char **args;
  int i;
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
    i = 0;
    if (check_valid(line) && line)
    {
      i = 0;
      while (args[i])
      {
        // args[i] = parser(args[i]);
        if (parser(args[i]))
        {
          printf("parser dan önce args[%d]: %s\n",i, args[i]);
          args[i] = parser(args[i]);
          printf("parser dan sonra args[%d]: %s\n",i, args[i]);
          i++;
        }

        else
        {
          i++;
        }
      }
      status = lsh_execute(args, str);
    }
  }
}