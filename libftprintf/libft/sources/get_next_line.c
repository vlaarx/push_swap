/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: screight <screight@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 19:36:19 by screight          #+#    #+#             */
/*   Updated: 2019/08/28 19:36:21 by screight         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list		*ft_find_list(t_list **file, const int fd)
{
	t_list			*ptr;

	ptr = *file;
	while (ptr)
	{
		if ((int)ptr->content_size == fd)
			return (ptr);
		ptr = ptr->next;
	}
	if (!(ptr = ft_lstnew("\0", fd)))
		return (NULL);
	ft_lstadd(file, ptr);
	ptr = *file;
	return (ptr);
}

int					ft_copy_line(char **line, t_list *temp)
{
	int				i;
	char			*str;

	i = 0;
	while (((char*)(temp->content))[i] != '\n'
		&& ((char*)(temp->content))[i] != '\0')
		i++;
	if (!(*line = ft_strnew(i)))
		return (0);
	ft_strncpy((*line), temp->content, i);
	if (i != (int)ft_strlen(temp->content))
	{
		if (!(str = ft_strdup(temp->content + i + 1)))
			return (0);
		free(temp->content);
		temp->content = str;
	}
	else
		ft_strclr(temp->content);
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	static	t_list	*file;
	t_list			*temp;
	int				count;
	void			*tlen;

	if (fd < 0 || read(fd, buff, 0) < 0 || !(temp = ft_find_list(&file, fd)))
		return (-1);
	while ((count = read(fd, buff, BUFF_SIZE)))
	{
		buff[count] = '\0';
		tlen = temp->content;
		if (!(temp->content = ft_strjoin(temp->content, buff)))
			return (-1);
		free(tlen);
		if (ft_strchr(temp->content, '\n'))
			break ;
	}
	if (!count && ft_strlen(temp->content) == 0)
	{
		free(file->content);
		free(file);
		return (0);
	}
	return (ft_copy_line(line, temp)) ? 1 : -1;
}
