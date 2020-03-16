#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	l;
	size_t	sz;

	i = 0;
	l = 0;
	while (dst[i] && i < size)
		i++;
	while (src[l])
		l++;
	sz = i + l;
	if (size == 0)
		return (sz);
	l = 0;
	while (src[l] && i < size - 1)
	{
		dst[i] = src[l];
		i++;
		l++;
	}
	if (i < size)
		dst[i] = '\0';
	return (sz);
}
