#include "mini_shell.h"

char *command(char *str, int *i)
{
	char *tmp;
	char c;
	int j;
	int k;

	j = *i;
	while (str[*i] && str[*i] != ' ')
	{

		if (str[*i] == '"' || str[*i] == '\'')
		{

			c = str[(*i)++];
			// printf("c : %c\n", c);
			while (str[*i] != c)
				(*i)++;
		}
		(*i)++;
		if (str[*i] == '"' || str[*i] == '$')
			break;
	}
	tmp = ft_substr(str, j, *i - j);
	//(*i)--;
	// printf("tmp : %s\n", tmp);
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
				while(ft_isalnum(str[++i]));//$ bitii mi 
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
