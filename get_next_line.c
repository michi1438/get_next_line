/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 09:37:24 by xbeheydt          #+#    #+#             */
/*   Updated: 2023/01/11 12:30:57 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int				i;
	int				red;
	char			*buf;
	char			*line;
	static char		*statline;

	buf = ft_calloc(1, sizeof(char) * (BUFFER_SIZE) + 1);
	line = ft_calloc(1, sizeof(char) * (BUFFER_SIZE) + 1);
	i = 0;
	red = 0;
	if (statline != NULL)
	{
		if (readforterm(statline) >= 0)
			return (ifstathasreturn(line, &statline, readforterm(statline), buf));
		red = read(fd, buf, BUFFER_SIZE);
		i = readstat(statline);
		if (statline[i] == '\0' && red == 0)
		{	
			line = fandrline(line, statline);
			statline = nullify(statline);
			free (buf);
			return (line);
		}
		else if (i == -1 || red != 0)
		{
			line = fandrline(line, statline);
			statline = nullify(statline);
		}
	}
	if (red == 0)
		red = read(fd, buf, BUFFER_SIZE);
	while (red > 0)
	{	
		buf[red] = '\0';
		if (readforterm(buf) >= 0)
			return (ifbufhasreturn(buf, &statline, line, red));
		else
			line = fandrline(line, buf);
		red = read(fd, buf, BUFFER_SIZE);
		if (red == 0)
		{
			free(buf);
			statline = nullify(statline);
			return (line);
		}
	}
	free(buf);
	free(statline);
	free(line);
	return (NULL);
}


char *ifbufhasreturn(char *buf, char **statline, char *line, int red)
{
	int	 i;

	i = readforterm(buf);
	if (buf[i] == '\n' && buf[i + 1] != '\0')
	{
		*statline = freeandreplace(*statline, buf, i);
		if (red < BUFFER_SIZE)
			(*statline)[red - (i + 1)] = '\0';
	}
	buf[i + 1] = '\0';
	line = fandrline(line, buf);
	free (buf);
	return (line);
}

char	*ifstathasreturn(char *line, char **statline, int i, char *buf)
{
	line = fandrline(line, *statline);
	if (line[i + 1] != '\0')
		*statline = freeandreplace(*statline, line, i);
	else
		*statline = nullify(*statline);
	line[i + 1] = '\0';
	free(buf);
	return (line);
}

char *nullify(char *stat)
{
	free(stat);
	return (NULL);
}

int	readforterm(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == '\n')
			return (i);
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
			return (i);
		i++;
	}
	return (-1);
}
