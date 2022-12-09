#include "libft.h"

size_t	ft_strcat(char *dest, const char *src)
{
	size_t	i;
	size_t	dsize;

	dsize = 0;
	while (dest[dsize] != '\0')
		dsize ++;
	i = dsize;
	while (src[dsize - i])
	{
		dest[dsize] = src[dsize - i];
		dsize++;
	}
	return (i + ft_strlen(src));
}
