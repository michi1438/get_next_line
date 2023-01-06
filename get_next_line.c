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

	buf = ft_calloc(1, sizeof(char) * (BUFFER_SIZE) + 1);
	line = ft_calloc(1,sizeof(char) * (BUFFER_SIZE) + 1);
	i = 0;
	if (statline != NULL)
	{
		i = readstat(statline);
		if (i == -1)
		{
			line = fandrline(line, statline);
		}
		else if (i >= 0)
		{
			line = fandrline(line, statline);
			if (statline[i] == '\0')
			{	
				statline = NULL;
				free (statline);
				statline = NULL;
				free (buf);
				buf = NULL;
				return (line);
			}
			statline = freeandreplace(statline, line, i);
			line[i + 1] = '\0';
			free(buf);
			buf = NULL;
			return (line);
		}
	}
	red = read(fd, buf, BUFFER_SIZE);
	while (red > 0)
	{	
		i = readforterm(buf);
		if (red < BUFFER_SIZE)
		{
			buf[red] = '\0';
		}
		if (i >= 0)
		{
			if (buf[i] == '\n' && buf[i + 1] != '\0')
			{
				statline = freeandreplace(statline, buf, i);
				if (red < BUFFER_SIZE)
				{
					statline[red - (i + 1)] = '\0';
				}
			}
			buf[i + 1] = '\0';
			line = fandrline(line, buf);
			free (buf);
			buf = NULL;
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
			buf = NULL;
			free(statline);
			statline = NULL;
			return (line);
		}
	}
	if (buf != NULL)
	{
		free(buf);
		buf = NULL;
	}	
	if (statline != NULL)
	{
		free(statline);
		statline = NULL;
	}
	free(line);
	line = NULL;
	write(1, "i", 1);
	return (NULL);		
}

int	readforterm(char *buf)
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

int	readstat(char *buf)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (buf[i] == '\n' || buf[i] == '\0')
			return(i);
		i++;
	}
	return (-1);
}
