/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:34:36 by mguerga           #+#    #+#             */
/*   Updated: 2022/12/30 19:58:18 by xbeheydt         ###   ########.fr       */
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
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	i = 0;
	if (nline != NULL && (i = readbuf((char *)nline)) >= 0)
	{
		line = ft_strjoin("", nline);
		nline = freeandreplace(nline, i);
		return (line);
	}
	while (read(fd, buf, BUFFER_SIZE) > 0)
	{	
		if (readforend(buf) == 1)
		{
			line = ft_strjoin("", buf);
			if (nline != NULL)
				free(nline);
			return (line);
		}
		if ((i = readbuf(buf)) >= 0)
		{
			buf[i + 1] = '\0'; 
			if (nline != NULL)
				nline = freeandreplace(nline, i);
			line = ft_strjoin("", buf);
			return (line);
		}
		else
		{
			if (line != NULL)
				line = fandrline(line, buf);
		}
	}
	free(buf);
	//free(line);
	if (nline != NULL)
		free(nline);
	return (NULL);
}

int readforend(char	*buf)
{
	int	i;

	i = 0;
	while(buf[i] != '\0')
		++i;
	if (buf[i] == '\0')
		return (1);
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
