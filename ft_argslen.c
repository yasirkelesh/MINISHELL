#include "mini_shell.h"

int ft_argslen(char **args)
{
    int i;
    if(!args[i])
        return -1;
    while(args[i])
        i++;
    return i;

}