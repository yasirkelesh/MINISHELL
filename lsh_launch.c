#include "mini_shell.h"

extern char **environ;
int lsh_launch(char **args, t_builtin_str *str)
{
  pid_t pid;
  int status;
  int i = 0;
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
    wait(NULL);
    usleep(1000);
    if (k == 0)
    {
      // printf(" benim pid %d\ngetpid() %d\n", pid, getpid());
      if (execve(str1, args, environ) == -1)
      {
        perror("");
      }
    }
    else
      return 1;

    exit(EXIT_FAILURE);
  }
  else if (pid < 0)
  {
    // Error forking
    perror("lsh");
  }
  else
  {
    wait(NULL);
    /* printf(" benim pid %d\ngetpid() %d\n", pid, getpid());  */
    waitpid(pid, &status, WUNTRACED);
    /*     while (!WIFEXITED(status) && !WIFSIGNALED(status))
        {
          printf("test");
          waitpid(pid, &status, WUNTRACED);
        }  */
  }

  return 1;
}