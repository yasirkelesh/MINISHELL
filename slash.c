#include "mini_shell.h"
//halloldu
char *slash(char *str, int *i)
{
    char *tmp;

    tmp = ft_substr(str, 0, *i);
    ft_strjoin(tmp, str + *i + 1);
    //free(str);
    ++(*i);
    return (tmp);
}

