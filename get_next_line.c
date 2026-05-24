/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 16:09:18 by nicolas           #+#    #+#             */
/*   Updated: 2026/05/24 13:17:39 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *str, int fd)
{
	char	buf[BUFFER_SIZE + 1];
	char	*temp;
	ssize_t read_bytes;

	read_bytes = 1;
	while (!ft_strchr(str, '\n') && read_bytes > 0)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes < 0)
		{
			return (NULL);
		}
		buf[BUFFER_SIZE] = '\0';
		temp = str;
		str = ft_strjoin(str, buf);
		free(temp);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char		*str;
	char			*line;
	unsigned int	i;

	if (!str)
	{
		str = malloc(1);
		if (!str)
			return (NULL);
		*str = '\0';
	}
	str = get_line(str, fd);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		i++;
	line = ft_substr(str, 0, i);
	return (line);
}
