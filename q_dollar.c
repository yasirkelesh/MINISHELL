#include "mini_shell.h"

char *q_dollar(char *tmp)
{
    char *rst;
    char *dlr;
    int k = 0;
    int j = 0;

    k++;
    while (dollar_query(tmp))
    {
        if (tmp[k] == '\'' || tmp[k] == '"')
        {
            k++;
        }
        while (tmp[k] != '\0' && tmp[k] != '"' && tmp[k] != '\'')
        {

            int t = 0;
            while (tmp[k] != '$' && tmp[k] != '\0')
                k++;
            //printf("dollar öncesi tmp: %s\n", tmp);
            if ((tmp[k + 1] == '"' && tmp[k - 1] == '"') || (tmp[k + 1] == '\'' && tmp[k - 1] == '\''))
                return tmp;

            if (tmp[k] == '$')
            {
                j = k;
                k++;
                while (tmp[k] != '$' && tmp[k] && tmp[k] != '"' && tmp[k] != ' ' && tmp[k] != '\'')
                    k++;
                rst = ft_substr(tmp, j, k - j);
                dlr = dollar(rst, &t);

                //printf("k: %d\n", k);
                //printf("j: %d\n", j);
                //printf("dlr: %s\n", dlr);

                if (dlr)
                    tmp = replaceWord(tmp, rst, dlr);
                else
                    tmp = replaceWord(tmp, rst, "");

                //printf("tmp2: %s\n", tmp);
            }
            // printf("test");
        }
    }
    // while bağla içinde dolar bitene kadar dön
    return tmp;
}