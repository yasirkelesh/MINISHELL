#include "mini_shell.h"

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