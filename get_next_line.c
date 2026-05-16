/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 16:09:18 by nicolas           #+#    #+#             */
/*   Updated: 2026/05/16 15:23:32 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*join;
	int		i;

	join = malloc((ft_strlen(str1) + ft_strlen(str2) + 1) * sizeof(char *));
	if (!join)
		return (NULL);
	i = 0;
	while(*str1)
	{
		join[i] = *str1;
		str1++;
		i++;
	}
	while (*str2)
	{
		join[i] = *str2;
		str2++;
		i++;
	}
	join[i] = '\0';
	return (join);
}

char	*get_next_line(int fd)
{
	static char	*text;
	char		*str;

	str = malloc(5 * sizeof(char));
	if (!str)
		return (NULL);
	if (!text)
	{
		text = malloc(1);
		if (!text)
			return (NULL);
		*text = '\0';
	}
	read(fd, str, 5);
	str[4] = '\0';
	text = ft_strjoin(text, str);
	free(str);
	return (text);
}
