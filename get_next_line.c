/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 00:27:53 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/03/25 17:35:38 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*make_line(char *backup)
{
	int		i;
	char	*str;

	i = 0;
	while (backup[i] != '\n' && backup[i] != '\0')
		i++;
	if (backup[i] == '\0')
		return (NULL);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (0);
	i = 0;
	while (backup[i] != '\n' && backup[i] != '\0')
	{
		str[i] = backup[i];
		i++;
	}
	if (backup[i] == '\n')
		str[i] = '\0';
	return (str);
}

char	*cut_line(char *backup)
{
	int		i;
	char	*str;

	i = 0;
	while (backup[i] != '\n' && backup[i] != '\0')
		i++;
	if (backup[i] == '\n')
		i++;
	str = ft_strdup(&backup[i]);
	free(backup);
	return (str);
}

char	*get_next_line(int fd)
{
	char		readstr[BUFFER_SIZE + 1];
	static char	*backup[OPEN_MAX];
	char		*str;
	int			readsize;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	while (1)
	{
		readsize = read(fd, readstr, BUFFER_SIZE);
		if (readsize <= 0)
			break ;
		readstr[readsize] = '\0';
		backup[fd] = ft_strjoin(backup[fd], readstr);
	}
	str = make_line(backup[fd]);
	backup[fd] = cut_line(backup[fd]);
	return (str);
}
