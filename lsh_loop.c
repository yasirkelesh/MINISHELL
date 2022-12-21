#include "mini_shell.h"
// hallloldu
void lsh_loop(t_builtin_str *str)
{
  char *line;
  char **args;
  int i = 0;
  int status = 1;

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
    if (ft_line_check(line) == 0)
    {
      free(line);
      lsh_loop(str);
    }
    add_history(line);
    
    args = lsh_split_line(line);
    i = 0;

    if (check_valid(line) && line)
    {
      i = 0;
      if (ft_strncmp(args[0], "export", 7))
      {
        while (args[i])
        {
          args[i] = parser(args[i]);
          if (!args[i])
            perror("");
          i++;
        }
      }
      i = 0;
      if (check_dir(args))
        status = lsh_execute(args, str);
      ft_free_str(args);
      free(line);
    }
  }
  i = 0;
}