/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: screight <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 17:40:23 by screight          #+#    #+#             */
/*   Updated: 2019/03/15 14:16:16 by screight         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free(char **split, int i)
{
	while (i-- >= 0)
		free(split[i]);
	free(split);
	return (NULL);
}

static char	*ft_inscribe(char *s, int a, int wlen)
{
	int		j;
	char	*str;

	j = 0;
	if (!(str = (char *)malloc(sizeof(s) * (wlen + 1))))
		return (NULL);
	while (wlen--)
		str[j++] = s[a++];
	str[j] = '\0';
	return (str);
}

static int	ft_wordlen(char *s, char c, int i)
{
	int	wlen;

	wlen = 0;
	while (s[i] != c && s[i])
	{
		wlen++;
		i++;
	}
	return (wlen);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**split;
	int		wlen;
	int		wcount;
	int		i;
	int		wstart_i;

	wstart_i = 0;
	i = 0;
	wcount = ft_wordcount((char *)s, c);
	if (!(split = (char **)malloc(sizeof(*split) * (wcount + 1))))
		return (NULL);
	while (wcount--)
	{
		while (s[wstart_i] == c)
			wstart_i++;
		wlen = ft_wordlen((char *)s, c, wstart_i);
		if (!(split[i++] = ft_inscribe((char *)s, wstart_i, wlen)))
			return (ft_free(split, i));
		wstart_i = wstart_i + wlen;
	}
	split[i] = NULL;
	return (split);
}
