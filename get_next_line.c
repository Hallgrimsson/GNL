/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:21:33 by jsousa-d          #+#    #+#             */
/*   Updated: 2024/11/11 19:40:35 by jsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fill_container(int fd, char *buf, char *container)
{
	ssize_t	readcount;
	char	*tmp;

	readcount = 1;
	while (readcount > 0)
	{
		readcount = read(fd, buf, BUFFER_SIZE);
		if (readcount == -1)
			return (NULL);
		if (readcount == 0)
			break ;
		buf[readcount] = '\0';
		if (container == NULL)
			container = ft_strdup("");
		tmp = container;
		container = ft_strjoin(tmp, buf);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(container, '\n') != NULL)
			break ;
	}
	return (container);
}

char	*dismember_line(char *line)
{
	ssize_t	i;
	char	*remaining;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
		return (NULL);
	remaining = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*remaining == 0)
	{
		free(remaining);
		remaining = NULL;
	}
	line[i + 1] = '\0';
	return (remaining);
}

char	*get_next_line(int fd)
{
	static char	*container;
	char		*buf;
	char		*line;

	buf = malloc(BUFFER_SIZE + 1);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
    {
        free(container);
        free(buf);
        container = NULL;
        buf = NULL;
        return (NULL);
    }
	if (!buf)
		return (NULL);
	line = fill_container(fd, buf, container);
	free(buf);
	buf = NULL;
	if (!line)
		return (NULL);
	container = dismember_line(line);
	return (line);
}
