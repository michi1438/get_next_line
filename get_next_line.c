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
	static char		*nline;
	int				i;
	int				red;

	buf = ft_calloc(1, sizeof(char) * (BUFFER_SIZE));
	line = ft_calloc(1,sizeof(char) * (BUFFER_SIZE));
	i = -1;
	if (nline != NULL)
		i = readbuf((char *)nline);
	if (i >= 0)
	{
		line = fandrline(line, nline);
		nline = freeandreplace(nline, i);
		line[i + 1] = '\0';
		free(buf);
		return (line);
	}
	if (nline != NULL)
	{
		line = rline(line, nline);
		if (nline != NULL)
			nline = NULL;
	}
	if (nline == NULL)
		red = read(fd, buf, BUFFER_SIZE);
	while (red > 0)
	{
		i = 0;
		while (i < BUFFER_SIZE)
		{
			if (buf[i] == '\0')
			{
				line = fandrline(line, buf);
				free(buf);
				if (buf[0] == '\0')
				{
					write(1, "i", 1);
					return (NULL);
				}
				return (line);
			}
			i++;
		}
		i = readbuf(buf);
		if (i >= 0)
		{
			nline = freeandreplace(buf, i);
			buf[i + 1] = '\0'; 
			line = fandrline(line, buf);
			free(buf);
			if (nline[0] == '\0')
				free (nline);
			return (line);
		}
		else if (line != NULL)
		{
			line = fandrline(line, buf);
		}
	}
	free(buf);
	free(line);
	buf = NULL;
	line = NULL;
	if (nline != NULL)
	{
		free(nline);
		nline = NULL;
	}
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
