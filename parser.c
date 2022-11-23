#include "mini_shell.h"
char *parser(char *str)
{
    int i;
    char *tmp;

    while (str[i])
    {
        i++;
    }
    tmp = malloc(sizeof(char *) * (i + 1));
    tmp = str;
    i = 0;
    // printf("fonk başı : %s\n", str);
    while (tmp[i])
    {

        if (tmp[i] == '\"')
        {
            tmp = double_quotes(tmp, &i);
        }
        else if (tmp[i] == '$')
        {
            tmp = dollar(tmp, &i);
            i = 0;
            if (tmp == NULL)
                return 0;
        }
        else if (tmp[i] == '\\')
        {
            tmp = slash(tmp, &i);
        }
        else if (tmp[i] == '\'')
        {
            tmp = quotes(tmp, &i);
        }

        i++;
    }

    /*     if (tmp[i] == '$')
        {
            // printf("dolardan önce : %s\n", str);
            tmp = dollar(tmp, &i);
            i = 0;
            // printf("dolardan sonra : %c\n", str[i]);
            if (tmp == NULL)
                return 0;
        } */
    printf("tmp : %s\n", tmp);
    return tmp;
}