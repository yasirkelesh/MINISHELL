#include "mini_shell.h"
//halloldu
char *command(char *str, int *i)
{
	char *tmp;

	char c;
	int j;
	int k;

	k = 0;
	j = *i;
	while (str[*i] && str[*i] != ' ' && k == 0)
	{
		if (str[*i] == '"' || str[*i] == '\'')
		{

			c = str[(*i)++];

			while (str[*i] != c)
				(*i)++;
			// k++;
		}

		if (str[j] == '$') // dollar geldiği zaman nerede biteceğini belirler mesala $HOME* ise düzgün çalışır
		{
			(*i)++;

			while (ft_isalnum(str[*i]))
			{
				(*i)++;
			}
			break;
		}
		else if (str[*i] == '$') // ilk argumandan sonra dolar gelirse ayırsın
			break;
		(*i)++;
	}
	tmp = ft_substr(str, j, *i - j);
	//(*i)--;

	if (tmp[0] == '\'' || tmp[0] == '"')
	{
		tmp = q_dollar(tmp);
	}
	//printf("içerden gelen tmp : %s\n", tmp);
	return (tmp);
}