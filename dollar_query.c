#include "mini_shell.h"

int dollar_query(char *tmp)
{
    int i = 0;
    int dollar = 0;
    while (tmp[i])
    {
        if (tmp[i] == '$')
        {
            if (tmp[i + 1] != '$' && tmp[i - 1] != '$' || 
                tmp[i + 1] != '\'' && tmp[i - 1] != '\''||
                tmp[i + 1] != '"' && tmp[i - 1] != '"')
                dollar++;
        }
        i++;
    }
    if(dollar == 0)
        return 0;
    else
        return 1;
}