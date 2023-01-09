#include "mini_shell.h"
// halloldu
char *command(char *str, int *i, char *args, int k)
{
    int j = *i;
    char *tmp = 0;

    if (ft_isspace(str[*i - 1]) && strcmp(" ", args) && k != 1) // boşluk koyuyor
    {
        return add_space();
    }
    if (str[*i] == '\0')
    {
        tmp = ft_substr(str, j, *i - j);
        return tmp;
    }
    if (str[*i] == '$')
    {
        return handle_dollar_sign(str, j, i);
    }
    if (str[*i] == '\"')
    {
        handle_double_quotes(str, j, i, tmp);
    }
    if (str[*i] == '\'' && str[*i])
    {
        handle_single_quotes(str, j, i, tmp);
    }
    handle_other_cases(str,j,i);
    tmp = ft_substr(str, j, *i - (j));
    return tmp;
}