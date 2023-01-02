/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:34:36 by mguerga           #+#    #+#             */
/*   Updated: 2023/01/02 13:23:52 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buf;
	char	*line;
	static char		*nline;
	int				i;

	if (nline != NULL)
		;
	else
		nline = NULL;
	line = calloc(1, 1);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	i = 0;
	if (nline != NULL && (i = readbuf((char *)nline)) >= 0)
	{
		line = ft_strjoin("", nline);
		line[i + 1] = '\0';
		nline = freeandreplace(nline, i);
		return (line);
	}
	if (nline != NULL)
		line = ft_strjoin("", nline);
	while (read(fd, buf, BUFFER_SIZE) > 0)
	{	
		/*if (readforend(buf) == 1)
		{
			line = fandrline(line, buf);
			if (nline != NULL)
				free(nline);
			free(buf);
			return (line);
		}*/		
		if ((i = readbuf(buf)) >= 0)
		{
			
			nline = ft_strjoin("\0", &buf[i + 1]);
			buf[i + 1] = '\0'; 
			line = fandrline(line, buf);
			free(buf);
			return (line);
		}
		else
		{
			line = fandrline(line, buf);
		}
	}
	free(buf);
	//free(line);
	if (nline != NULL)
		free(nline);
	if (line != NULL)
		free(line);
	return (NULL);
}


int readforend(char	*buf)
{
	int	i;

	i = 0;
	while(i < BUFFER_SIZE - 1)
	{
		if (buf[i] == '\0')
			return (1);
		++i;
	}
	return (0);
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
