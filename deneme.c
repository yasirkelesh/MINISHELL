#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

#include <stdio.h>
#include <string.h>
int main(int ac ,char **argv) {
   char str1[100] = "/bin/";
   strcat(str1, argv[1]);

   puts(str1);

   return 0;
}
