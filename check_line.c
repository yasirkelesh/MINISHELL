#include "mini_shell.h"

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
			//printf("c : %c\n", c);
			//printf("str[i] %c\ni : %d\n", str[*i], *i);
			while (str[*i] != c)
				(*i)++;
			k++;
			//printf("str2[i] %c\ni : %d\n", str[*i], *i);
		}
		
		if (str[*i] == '$')//dollar geldiği zaman nerede biteceğini belirler mesala $HOME* ize düzgün çaşlışır
		{
			(*i)++;

			while (ft_isalnum(str[*i]))
			{
				(*i)++;
			} 
			break;
		}
		(*i)++;
	}
	tmp = ft_substr(str, j, *i - j);
	//(*i)--;
	//printf("tmp : %s\n", tmp);
	return (tmp);
}

int get_cmd_num(const char *str)
{
	int i;
	int count;
	char c;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i])
			count++;
		if (str[i] == '"' || str[i] == '\'' || str[i] == '$')
		{
			if (str[i] == '$')
			{
				while (ft_isalnum(str[++i]))
					; //$ bitii mi
			}
			else
			{
				c = str[i];
				while (str[i] != c)
					i++;
				i++;
			}
		}
		else
			while (str[i] != ' ' && str[i] != '\0' && str[i] != '"' && str[i] != '\'')
				i++;
	}

	return count;
}
int check_valid(char *line)
{
	int i = 0;
	int q = 0;
	int q2 = 0;

	while (line[i])
	{
		if (line[i] == '\"' && q2 == 0)
		{
			if (q == 0)
				q++;
			else
				q--;
		}
		if (line[i] == '\'' && q == 0)
		{
			if (q2 == 0)
				q2++;
			else
				q2--;
		}
		i++;
	}
	if (q != 0 || q2 != 0)
		return 0;
	else
		return 1;
}
