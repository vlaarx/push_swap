#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		k;
	char	*str;
	char	*new;

	if (!s)
		return (NULL);
	str = (char *)s;
	i = 0;
	k = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
		i++;
	j = ft_strlen(str) - 1;
	if (str[i] == '\0')
		i = 0;
	while (str[j] == ' ' || str[j] == '\n' || str[j] == '\t')
		j--;
	if (!(new = (char *)malloc(sizeof(*str) * (j - i + 2))))
		return (0);
	while (i <= j)
		new[k++] = str[i++];
	new[k] = '\0';
	return (new);
}
