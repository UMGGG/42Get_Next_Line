/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 00:28:38 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/03/25 17:40:41 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);

#endif
