/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:34:36 by mguerga           #+#    #+#             */
/*   Updated: 2022/12/30 18:09:11 by xbeheydt         ###   ########.fr       */
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
	line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	i = 0;
	if (nline != NULL && (i = readbuf((char *)nline)) >= 0)
	{
		line = ft_strjoin("\0", nline);
		nline = freeandreplace(nline, i);
		return (line);
	}
	while (read(fd, buf, BUFFER_SIZE) > 0)
	{	
		if (readforend(buf) == 1)
		{
			line = ft_strjoin(line, buf);
			free (nline);
			return (line);
		}
		else if ((i = readbuf(buf)) >= 0)
		{
			nline = freeandreplace(nline, i);
			line = ft_strjoin("", line);
			return (line);
		}
		else
		{
			line = ft_strjoin(line, buf);
		}
	}
	free(buf);
	free(line);
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
	if (buf == NULL)
		return (-1);
	while (buf[i] != '\0')
	{
		if (buf[i] == '\n')
			return(i);
		i++;
	}
	return (-1);
}
