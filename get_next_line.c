/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 16:09:18 by nicolas           #+#    #+#             */
/*   Updated: 2026/05/25 12:06:11 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line(char *str, int fd)
{
	char	*buf;
	char	*temp;
	ssize_t	read_bytes;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	while (!ft_strchr(str, '\n') && (read_bytes = read(fd, buf, BUFFER_SIZE)))
	{
		if (read_bytes < 0)
		{
			free(buf);
			free(str);
			return (NULL);
		}
		buf[read_bytes] = '\0';
		temp = str;
		str = ft_strjoin(str, buf);
		free(temp);
	}
	free(buf);
	return (str);
}

static void	*free_static(char	**str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*create_line(char **str)
{
	char			*temp;
	char			*line;
	unsigned int	i;

	i = 0;
	while ((*str)[i] != '\n' && (*str)[i] != '\0')
		i++;
	if ((*str)[i] == '\n')
		i++;
	line = ft_substr(*str, 0, i);
	if (!line)
		return (free_static(str));
	temp = *str;
	*str = ft_substr(*str, i, ft_strlen(*str) - i);
	free(temp);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!str)
	{
		str = malloc(1);
		if (!str)
			return (NULL);
		*str = '\0';
	}
	str = get_line(str, fd);
	if (!str || str[0] == '\0')
		return (free_static(&str));
	return (create_line(&str));
}
