/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoares- <psoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:04:01 by psoares-          #+#    #+#             */
/*   Updated: 2022/11/15 15:37:21 by psoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buff[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			i;

	i = 0;
	if (BUFFER_SIZE < 1 || read(fd, 0, 0) < 0 || fd >= FOPEN_MAX)
	{
		while (fd >= 0 && fd <= FOPEN_MAX && buff[fd][i])
			buff[fd][i++] = 0;
		return (NULL);
	}
	line = NULL;
	while ((buff[fd][0] || read(fd, buff[fd], BUFFER_SIZE) > 0))
	{
		line = ft_strjoin(line, buff[fd]);
		if (ft_limpamemo(buff[fd]))
			break ;
	}
	return (line);
}
