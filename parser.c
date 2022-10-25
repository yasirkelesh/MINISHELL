#include "mini_shell.h"
char *parser(char *str)
{
    int i;

    i = 0;
    while(str[i])
    {
        //printf("%c", str[i]);
        if(str[i] == '$')
            str = dollar(str, &i); 
        else if(str[i] == '\"')
            str = double_quotes(str,&i);
        else if(str[i] == '\\')
            str = slash(str, &i);
        else if(str[i] == '\'')
            str = quotes(str, &i);
        
        i++;
        
    }
    return str;
}