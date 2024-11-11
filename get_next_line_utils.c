/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:40:35 by jsousa-d          #+#    #+#             */
/*   Updated: 2024/11/11 16:34:56 by jsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*d;
	size_t	i;
	size_t	len_s;

	i = 0;
	len_s = ft_strlen(s);
	if (len_s - start < len)
		len = len_s - start;
	if (start >= len_s)
	{
		d = malloc(1);
		d[0] = '\0';
		return (d);
	}
	d = malloc(((unsigned int) len + 1) * sizeof(char));
	if (d == NULL)
		return (NULL);
	while (i < len && s[start + i] && len_s > start)
	{
		d[i] = s[start + i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char) c)
			return ((char *)&s[i]);
		i++;
	}
	if ((unsigned char) c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*d;
	int		i1;
	int		i2;

	i1 = 0;
	i2 = 0;
	d = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (d == NULL)
		return (NULL);
	while (s1[i1])
	{
		d[i1] = s1[i1];
		i1++;
	}
	while (s2[i2])
	{
		d[i1 + i2] = s2[i2];
		i2++;
	}
	d[i1 + i2] = '\0';
	return (d);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		len;
	int		i;
	char	*p;

	i = 0;
	len = ft_strlen(src);
	p = malloc((len + 1) * sizeof(char));
	if (!p)
		return (NULL);
	while (src[i])
	{
		p[i] = src[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
