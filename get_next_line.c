/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:34:36 by mguerga           #+#    #+#             */
/*   Updated: 2022/12/29 18:41:20 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buf;
	char	*line;
	static char		*nline = "\0";
	int				i;

	line = calloc(sizeof(char), BUFFER_SIZE + 1);
	buf = calloc(sizeof(char), BUFFER_SIZE + 1);
	i = 0;
	if (nline[0] != '\0' && (i = readbuf((char *)nline)) >= 0)
	{
		line = ft_strjoin(line, nline);
		nline = ft_strjoin("", &line[i + 1]);
		return (linemaker (line, buf, i));
	}
	while (read(fd, buf, BUFFER_SIZE) != 0)
	{	
		if ((i = readbuf(buf)) >= 0)
		{
			nline = ft_strjoin("", &buf[i + 1]);
			return (linemaker (buf, line, i));
		}
		else
			line = ft_strjoin(line, buf);
	}
	return (NULL);
}

char	*linemaker(char *retline, char *buf, int i) 
{
	retline[i + 1] = '\0';
	retline = ft_strjoin(retline, buf);
	return (retline);
}

int	readbuf(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == '\n')
			return(i);
		i++;
	}
	return (-1);
}
