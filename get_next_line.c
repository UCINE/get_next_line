/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahamoun <lahamoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 02:09:29 by lahamoun          #+#    #+#             */
/*   Updated: 2022/11/23 06:20:17 by lahamoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
#endif

char	*buffer_stock(int fd, char *str)
{
	char	*buff;
	int		reader;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	reader = 1;
	while (!search(str, '\n') && reader != 0)
	{
		reader = read(fd, buff, BUFFER_SIZE);
		if (reader == -1)
		{
			free (buff);
			if (str)
				free (str);
			return (NULL);
		}
		buff[reader] = '\0';
		str = ft_strjoin(str, buff);
	}
	free (buff);
	return (str);
}

char	*get_the_return(char *str)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str[i])
		return (NULL);
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		line[j++] = str[i++];
	if (str[i] == '\n')
		line[j++] = str[i++];
	line[j] = '\0';
	return (line);
}

char	*get_what_left(char *str)
{
	char	*backup;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
	{
		free (str);
		return (NULL);
	}
	backup = malloc(ft_strlen(str) - i);
	if (!backup)
		return (NULL);
	i += 1;
	while (str[i])
		backup[j++] = str[i++];
	free (str);
	backup[j] = '\0';
	return (backup);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = buffer_stock(fd, str);
	if (!str)
		return (NULL);
	line = get_the_return(str);
	str = get_what_left(str);
	return (line);
}

int main()
{
	int fd = open("g.txt", O_RDONLY);
	int fd1 = open("v.txt",O_RDONLY);
	char *line;

		line = get_next_line(3);
		printf("%s",line);
		free(line);
		line = get_next_line(4);
		printf("%s",line);
}