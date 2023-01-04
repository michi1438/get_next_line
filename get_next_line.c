/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:34:36 by mguerga           #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buf;
	char	*line;
	static char		*statline;
	int				i;
	int				red;

	buf = ft_calloc(1, sizeof(char) * (BUFFER_SIZE));
	line = ft_calloc(1,sizeof(char) * (BUFFER_SIZE));
	i = 0;
	if (statline != NULL)
	{
		i = readbuf(statline);
		if (i == -1)
			line = fandrline(line, statline);
		else if (i >= 0)
		{
			line = fandrline(line, statline);
			free(buf);
			statline = freeandreplace(line, i);
			line[i + 1] = '\0';
			return (line);
		}
	}
	red = read(fd, buf, BUFFER_SIZE);
	while (red > 0)
	{
		i = readbuf(buf);
		if (i >= 0)
		{
			if (BUFFER_SIZE > 1)
				statline = freeandreplace(buf, i);
			buf[i + 1] = '\0';
			line = fandrline(line, buf);
			free (buf);
			return (line);
		}
		else
		{
			line = fandrline(line, buf);
		}
		red = read(fd, buf, BUFFER_SIZE);
		if (red == 0)
		{
			free(buf);
			return (line);
		}
	}
	if (buf != NULL)
		free(buf);
	if (statline != NULL)
		free(statline);
	free(line);
	return (NULL);		
}

int	readbuf(char *buf)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (buf[i] == '\n')
			return(i);
		i++;
	}
	return (-1);
}
