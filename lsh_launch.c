#include "mini_shell.h"
// halloldu
extern char **environ;
int lsh_launch(char **args, t_builtin_str *str)
{
  pid_t pid;
  int status;
  int k = 0;
  char *str1 = find_path(args[0]);

  if ((lsh_num_builtins(str, args[0]) != -1) && k == 0)
  {
    k++;
  }
  // printf("str1 : %s",str1);
  pid = fork();
 if (pid == 0)
{
    if (k == 0)
    {
        if (execve(str1, args, environ) == -1)
        {
            perror("");
        }
    }
    else
    {
        return 1;
    }

    exit(EXIT_FAILURE);
}

 waitpid(pid, &status, WUNTRACED);

  return 1;
}