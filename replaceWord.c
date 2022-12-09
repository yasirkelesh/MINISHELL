#include "mini_shell.h"
// halloldu
char *replaceWord(char *s, char *oldW, char *newW)
{
	char *result;
	int i, cnt = 0;
	int k = 0;
	int newWlen = ft_strlen(newW);
	int oldWlen = ft_strlen(oldW);

	for (i = 0; s[i] != '\0'; i++)
	{
		if (strstr(&s[i], oldW) == &s[i])
		{
			cnt++;

			i += oldWlen - 1;
		}
	}

	result = (char *)malloc(i + cnt * (newWlen - oldWlen) + 1);
	if (!result)
		return (result);

	i = 0;
	while (*s)
	{
		if (strstr(s, oldW) == s)
		{
			strcpy(&result[i], newW);
			i += newWlen;
			s += oldWlen;
		}
		else
			result[i++] = *s++;
	}

	result[i] = '\0';

	// free(s);

	return result;
}