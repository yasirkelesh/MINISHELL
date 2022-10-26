#include "mini_shell.h"

char *quotes(char *str, int *i)
{
    int j;
    char *tmp;
    char *tmp1;
    char *tmp2;

    j = *i;
    (*i)++;
    while (str[(*i)] != '\'')
        ++(*i);
    tmp = ft_substr(str, 0, j);
    tmp1 = ft_substr(str, j + 1, *i - j - 1);
    tmp2 = strdup(str + *i + 1);
    tmp = ft_strjoin(tmp, tmp1);
    tmp = ft_strjoin(tmp, tmp2);
    free(str);
    return (tmp);
}

char *slash(char *str, int *i)
{
    char *tmp;

    tmp = ft_substr(str, 0, *i);
    ft_strjoin(tmp, str + *i + 1);
    free(str);
    ++(*i);
    return (tmp);
}

char *double_quotes(char *str, int *i)
{
    int j;
    char *tmp;
    char *tmp1;
    char *tmp2;

    j = *i;
    while (str[++(*i)] != '\"')
    {
        if (str[*i] == '$')
        {
            str = dollar(str, i); 
        }
    }
    tmp = ft_substr(str, 0, j);
    tmp1 = ft_substr(str, j + 1, *i - j - 1);
    tmp2 = strdup(str + *i + 1);
    tmp = ft_strjoin(tmp, tmp1);
    tmp = ft_strjoin(tmp, tmp2);
    free(str);
    return (tmp);
}
char *get_value(char *key)
{
    char *value;
    size_t key_len;
    t_list *tmp;

    tmp = g_env;
    tmp = tmp->next;
    key_len = ft_strlen(key);
    while (tmp)
    {

        if (!strncmp(key, (char *)tmp->content, key_len) &&
            ((char *)(tmp->content))[key_len] == '=')
        {
            value = strdup((char *)tmp->content + key_len + 1);
            return (value);
        }
        tmp = tmp->next;
    }
    return (NULL);
}
char *dollar(char *str, int *i)
{
    int j;
    char *tmp;
    char *key;
    char *value;

    j = *i;

    tmp = ft_substr(str, j + 1, *i - j - 1);

    while (str[++(*i)] && str[*i] != ' ')
        ;

    key = ft_substr(str, j + 1, *i - j - 1);

    value = get_value(key);

    if (!value)
        return NULL;
    tmp = ft_strjoin(tmp, value);
    tmp = ft_strjoin(tmp, str + *i);
    return (tmp);
}