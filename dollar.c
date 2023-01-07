#include "mini_shell.h"
//halloldu
char *get_value(char *key)
{
    char *value;
    size_t key_len;
    t_list *tmp;

    tmp = g_list.g_env;
    tmp = tmp->next;
    key_len = ft_strlen(key);
    while (tmp)
    {

        if (!ft_strncmp(key, (char *)tmp->content, key_len) &&
            ((char *)(tmp->content))[key_len] == '=')
        {
            value = ft_strdup((char *)tmp->content + key_len + 1);
            return (value);
        }
        tmp = tmp->next;
    }
    return (NULL);
}
char *dollar(char *str, int *i)
{
    int j;
    //char *tmp;
    char *key;
    char *value;
    //printf("str dolar == %s\n", str);
    j = *i;

   /*  tmp = ft_substr(str, j + 1, *i - j - 1); */
    //printf("tmp == %s\n", tmp);
    while (str[++(*i)] && str[*i] != ' ' && ft_isalnum(str[*i]))
        ;

    key = ft_substr(str, j + 1, *i - j - 1);

    value = get_value(key);

    if (!value)
        return NULL;
/*     tmp = ft_strjoin(tmp, value);
    tmp = ft_strjoin(tmp, str + *i); */
    return (value);
}