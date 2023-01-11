/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 09:37:24 by xbeheydt          #+#    #+#             */
/*   Updated: 2023/01/11 19:31:03 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	t_strs			strings;
	int				i;
	int				red;
	static char		*statline;

	strings.buf = ft_calloc(1, sizeof(char) * (BUFFER_SIZE) + 1);
	strings.line = ft_calloc(1, sizeof(char) * (BUFFER_SIZE) + 1);
	i = 0;
	red = 0;
	if (statline != NULL)
	{
		if (readforterm(statline, 1) >= 0)
			return (ifstatret(&strings, &statline, i));
		red = read(fd, strings.buf, BUFFER_SIZE);
		i = readforterm(statline, 0);
		strings.line = stat_after_read(&statline, &strings, red, i);
		if (strings.line != NULL && red == 0)
			return (strings.line);
	}
	else
		red = read(fd, strings.buf, BUFFER_SIZE);
	return (mainwhile(fd, &strings, &statline, &red));
}

char	*stat_after_read(char **statline, t_strs *strings, int red, int i)
{
	if ((*statline)[i] == '\0' && red == 0)
	{	
		strings->line = freeandreplace(strings->line, *statline, -1);
		free(*statline);
		*statline = NULL;
		free (strings->buf);
		return (strings->line);
	}
	else if (i == -1 || red != 0)
	{
		strings->line = freeandreplace(strings->line, *statline, -1);
		free (*statline);
		*statline = NULL;
		return (strings->line);
	}
	return (NULL);
}

char	*ifstatret(t_strs *strings, char **statline, int i)
{
	i = readforterm(*statline, 1);
	strings->line = freeandreplace(strings->line, *statline, -1);
	if (strings->line[i + 1] != '\0')
		*statline = freeandreplace(*statline, strings->line, i);
	else
	{
		free (*statline);
		*statline = NULL;
	}
	(strings->line)[i + 1] = '\0';
	free(strings->buf);
	return (strings->line);
}

char	*mainwhile(int fd, t_strs *strings, char **statline, int *red)
{
	int	i;

	while (*red > 0)
	{	
		i = readforterm(strings->buf, 1);
		(strings->buf)[*red] = '\0';
		if (readforterm(strings->buf, 1) >= 0)
			return (ifbufhasreturn(strings, statline, i, red));
		else
			strings->line = freeandreplace(strings->line, strings->buf, -1);
		*red = read(fd, strings->buf, BUFFER_SIZE);
		if (*red == 0)
		{
			free(strings->buf);
			free(*statline);
			*statline = NULL;
			return (strings->line);
		}
	}
	free(strings->buf);
	free(*statline);
	free(strings->line);
	return (NULL);
}

char	*ifbufhasreturn(t_strs *strings, char **statline, int i, int *red)
{
	if ((strings->buf)[i] == '\n' && (strings->buf)[i + 1] != '\0')
	{
		*statline = freeandreplace(*statline, strings->buf, i);
		if (*red < BUFFER_SIZE)
			(*statline)[*red - (i + 1)] = '\0';
	}
	(strings->buf)[i + 1] = '\0';
	strings->line = freeandreplace(strings->line, strings->buf, -1);
	free (strings->buf);
	return (strings->line);
}
