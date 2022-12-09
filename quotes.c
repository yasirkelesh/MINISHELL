#include "mini_shell.h"
//halloldu
char *quotes(char *str, int *i)
{
    int j;
    char *tmp;
    char *tmp1;
    char *tmp2;

    j = *i;
    while (str[++(*i)] != '\'')
        ;
    /*     {
            printf("str quotes : %c\n", str[*i]);
           if (str[*i] == '$')
            {
                printf("str quotes dollar : %s\n", str);
                str = dollar(str, i);
            }
        }  */
    tmp = ft_substr(str, 0, j);
    tmp1 = ft_substr(str, j + 1, *i - j - 1);
    tmp2 = ft_strdup(str + *i + 1);
    tmp = ft_strjoin(tmp, tmp1);
    tmp = ft_strjoin(tmp, tmp2);
    //free(str);
    return (tmp);
}