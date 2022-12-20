#include "mini_shell.h"
// hallloldu
void lsh_loop(t_builtin_str *str)
{
  char *line;
  char **args;
  int i = 0;
  int len = -1;
  int status = 1;

  while (status)
  {
    signal(SIGQUIT, SIG_IGN);
    signal(SIGINT, &ctrl_c);
    line = readline("> ");
    if (!line)
    {
      ("exit\n");
      exit(1);
    }
    add_history(line);

    // args = ft_split(line, ' ');
    args = lsh_split_line(line);
    len = ft_argslen(args);

    i = 0;
    int j = 0;

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
          printf("pars args [%d]: %s\n", i, args[i]);
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