/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 16:09:24 by nicolas           #+#    #+#             */
/*   Updated: 2026/05/24 13:07:09 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*rstr;
	size_t	i;
	size_t	cpy_i;

	rstr = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!rstr)
		return (NULL);
	cpy_i = 0;
	i = 0;
	while (s1[cpy_i])
	{
		rstr[i] = s1[cpy_i];
		cpy_i++;
		i++;
	}
	cpy_i = 0;
	while (s2[cpy_i])
	{
		rstr[i] = s2[cpy_i];
		cpy_i++;
		i++;
	}
	rstr[i] = '\0';
	return (rstr);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

static char	*create_substr(const char *str, char *sub, size_t start, size_t len)
{
	size_t	i;

	i = 0;
	while (str[start] && i < len)
	{
		sub[i] = str[start];
		start++;
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*rstr;
	size_t	str_len;

	str_len = ft_strlen(s);
	if (len == 0 || start >= str_len)
	{
		rstr = malloc(1);
		if (!rstr)
			return (NULL);
		rstr[0] = '\0';
		return (rstr);
	}
	if (len > str_len - start)
		len = str_len - start;
	rstr = malloc((len + 1) * sizeof(char));
	if (!rstr)
		return (NULL);
	return (create_substr(s, rstr, (size_t)start, len));
}
