/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:34:36 by mguerga           #+#    #+#             */
/*   Updated: 2023/01/03 14:23:31 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buf;
	char	*line;
	char *retline;
	static char		*nline;
	int				i;

	buf = malloc(sizeof(char) * (BUFFER_SIZE));
	line = malloc(sizeof(char) * (BUFFER_SIZE));
	i = 0;
	if (nline != NULL && (i = readbuf((char *)nline)) >= 0)
	{
		free(buf);
		retline = rline("\0", nline);
		printf("Z%sZ\n", line);
		nline = freeandreplace(nline, i);
		retline[i + 1] = '\0';
		//free(line);
		return (retline);
	}
	if (nline != NULL)
	{
		line = rline("\0", nline);
		free (nline);
	}
	while (read(fd, buf, BUFFER_SIZE) > 0)
	{	
		if ((i = readbuf(buf)) >= 0)
		{
			
			nline = freeandreplace(buf, i);
			buf[i + 1] = '\0'; 
			line = fandrline(line, buf);
			free(buf);
			return (line);
		}
		else if (line != NULL)
		{
			line = fandrline(line, buf);
		}
	}
	return (NULL);
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
