/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 00:27:53 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/01/27 03:59:20 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*backup[OPEN_MAX];
	char		str[BUFFER_SIZE + 1];
	int			readsize;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 0)
		return ("asd");
	while (read(fd, str, BUFFER_SIZE))
	{
		str[readsize] = '\0';
	}
	return (NULL);
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
