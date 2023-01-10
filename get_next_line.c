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
	red = 0;
	if (statline != NULL)
	{
		i = readforterm(statline);
		if (i >= 0)
		{
			line = fandrline(line, statline);
			if (line[i + 1] != '\0')
			{
				statline = freeandreplace(statline, line, i);
			}
			else
			{
				free(statline);
				statline = NULL;
			}
			line[i + 1] = '\0';
			free(buf);
			buf = NULL;
			return (line);
		}
		red = read(fd, buf, BUFFER_SIZE);
		i = readstat(statline);
		if (statline[i] == '\0' && red == 0)
		{	
			line = fandrline(line, statline);
			free (statline);
			statline = NULL;
			free (buf);
			return (line);
		}
		else if (i == -1 || red != 0)
		{
			line = fandrline(line, statline);
			if (statline[i + 1] == '\0')
			{
				statline = NULL;
				free(statline);
			}
		}
	}
	if (red == 0)
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
		free(buf);
	if (statline != NULL)
		free(statline);
	free(line);
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
