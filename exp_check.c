#include "mini_shell.h"

int exp_check(char *str)
{
	int i = 0;
	while(str[i])
	{
		if(str[i] == '=')
		{
			//printf("export str : %s\ni: %d\n", str,i);

 			if(i == 0)//
				return -1; 
			return 1;
		}
		i++;
	}
	return 0;
}
