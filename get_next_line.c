/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 00:27:53 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/03/23 15:22:03 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_str(int fd, char *str)
{
	size_t	readsize;
	char	*readbuf;

	readbuf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (readbuf == NULL)
		return (0);
	readsize = 1;
	while (readsize != 0 && !ft_strchr(str, '\n'))
	{
		readsize = read(fd, readbuf, BUFFER_SIZE);
		if (readsize == -1)
		{
			free(readbuf);
			return (0);
		}
		readbuf[readsize] = '\0';
		str = ft_strjoin(str, readbuf);
	}
	free(readbuf);
	return (str);
}

char	*give_line(char *backup)
{
	size_t	i;
	char	*str;

	i = 0;
	if (backup[i] == '\0')
		return (0);
	while (backup[i] != '\0' && backup[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (0);
	i = 0;
	while (backup[i] != '\n' && backup[i] != '\0')
	{
		str[i] = backup[i];
		i++;
	}
	if (backup[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

char	*cut_line(char *backup)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	while (backup[i] != '\0' && backup[i] != '\n')
		i++;
	if (backup[i] == '\0')
	{
		free(backup);
		return (0);
	}
	str = malloc(sizeof(char) * (sizeof(backup) - i + 1));
	if (str == NULL)
		return (0);
	i++;
	while (backup[i] != '\0')
		str[j++] = backup[i++];
	str[j] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*str;

	if (BUFFER_SIZE <= 0 && fd < 0)
		return (0);
	get_str(fd, backup);
	if (backup == NULL)
	{
		free(backup);
		return (0);
	}
	str = give_line(backup);
	backup = cut_line(backup);
	return (str);
}

#include <fcntl.h>
int main()
{
	int fd;
	fd = open("abc.txt", O_RDONLY);
	printf("%d\n%s\n", fd, get_next_line(fd));
	printf("%d\n%s\n", fd, get_next_line(fd));
	printf("%d\n%s\n", fd, get_next_line(fd));
}
