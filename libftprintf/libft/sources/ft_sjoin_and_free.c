#include "libft.h"

char		*ft_sjoin_and_free(char *str1, char *str2)
{
	char	*rez_str;

	if (!str1 || !str2)
		return (NULL);
	rez_str = ft_strjoin(str1, str2);
	ft_strdel(&str1);
	ft_strdel(&str2);
	return (rez_str);
}
