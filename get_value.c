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
