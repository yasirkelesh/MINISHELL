#include "mini_shell.h"

char *q_dollar(char *tmp)
{
    char *rst;
    char *dlr;
    int k = 0;
    int j = 0;

    k++;
    while (tmp[k] != '\0' && tmp[k] != '"')
    {
        printf("tmp1: %s\n", tmp);
        int t = 0;
        while (tmp[k] != '$' && tmp[k] != '\0')
            k++;
        if (tmp[k] == '$')
        {
            j = k;
            k++;
            while (tmp[k] != '$' && tmp[k] && tmp[k] != '"' && tmp[k] != ' ')
                k++;
            rst = ft_substr(tmp, j, k - j);
            dlr = dollar(rst, &t);
            printf("k: %d\n", k);
            printf("j: %d\n", j);
            tmp = replaceWord(tmp, rst, dlr);
            printf("tmp2: %s\n", tmp);
        }
        // printf("test");
    }
    return tmp;
}