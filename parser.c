#include "mini_shell.h"
//halloldu
char *parser(char *str)
{
    int i;
    char *tmp;


    tmp = str;
    if(!tmp)
        return str;   
    i = 0;
    while (tmp[i])
    {

        if (tmp[i] == '\"')
        {
            if (tmp[i + 2] == '"')
                return (double_quotes(tmp, &i));
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
            printf("tırnaklı tmp %s\n", tmp);
            if (tmp[i + 2] == '\'')
            {
                printf("test parser\n");
                return(quotes(tmp, &i));
            }
        }

        i++;
    }
/*     i = 1;
        if (tmp[i] == '$')
        {
            // printf("dolardan önce : %s\n", str);
            tmp = dollar(tmp, &i);
            i = 0;
            // printf("dolardan sonra : %c\n", str[i]);
            if (tmp == NULL)
                return 0;
        }  */
    // printf("tmp : %s\n", tmp);

    return tmp;
}