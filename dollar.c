#include "mini_shell.h"

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
    //printf("str dolar == %s\n", str);
    j = *i;

    tmp = ft_substr(str, j + 1, *i - j - 1);
    //printf("tmp == %s\n", tmp);
    while (str[++(*i)] && str[*i] != ' ')
        ;

    key = ft_substr(str, j + 1, *i - j - 1);

    value = get_value(key);

    if (!value)
        return NULL;
    //printf("value == %s\n", value);
    //tmp = ft_strjoin(tmp, value);
    //printf("tmp == %s\n", tmp);
    //tmp = ft_strjoin(tmp, str + *i);
    //printf("tmp == %s\n", tmp);
    return (value);
}