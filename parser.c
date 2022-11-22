#include "mini_shell.h"
char *parser(char *str)
{
    int i;

    i = 0;
    // printf("fonk başı : %s\n", str);
    while (str[i])
    {
        // printf("while içi : %c\n", str[i]);
        if (str[i] == '\"')
            str = double_quotes(str, &i);
        else if (str[i] == '$')
            break;
        else if (str[i] == '\\')
            str = slash(str, &i);
        else if (str[i] == '\'')
            str = quotes(str, &i);

        i++;
    }

    if (str[i] == '$')
    {
        //printf("dolardan önce : %s\n", str);
        str = dollar(str, &i);
        i = 0;
        // printf("dolardan sonra : %c\n", str[i]);
        if (str == NULL)
            return 0;
    }


    return str;
}