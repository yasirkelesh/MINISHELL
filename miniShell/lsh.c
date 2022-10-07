#include "mini_shell.h"

char *builtin_str[] = {
  "cd",
  "help",
  "exit"
};
int (*builtin_func[]) (char **) = {
  &lsh_cd,
};
int lsh_cd(char **args)
{
  if (args[1] == NULL) {
    fprintf(stderr, "lsh: expected argument to \"cd\"\n");
  } else {
    if (chdir(args[1]) != 0) {
      perror("lsh");
    }
  }
  return 1;
}


int lsh_execute(char **args)
{
  int i;

  if (args[0] == NULL) {
    // An empty command was entered.
    return 1;
  }

  for (i = 0; i < lsh_num_builtins(); i++) {
    if (strcmp(args[0], builtin_str[i]) == 0) {
      return (*builtin_func[i])(args);
    }
  }

  return lsh_launch(args);
}
void sh_loop(void)
{
    char *line;
    char **args;
    int status;

    printf("> ");
    line = readline("> ");
    args = ft_split(line, ' ');
    status = sh_execute(args);

    free(line);
    free(args);

    while(status)
    {
        printf("> ");
        line = readline("> ");
        args = ft_split(line, ' ');
        status = sh_execute(args);

        free(line);
        free(args);
    }

}
