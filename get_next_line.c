/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:34:36 by mguerga           #+#    #+#             */
/*   Updated: 2022/12/24 15:39:17 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char *buf;
	char *line = "\0";
	int	i;
	static char *nline = "\0";

	i = 0;
	buf = malloc(BUFFER_SIZE + 1);
	buf[BUFFER_SIZE] = '\0';
	if (nline[0] != '\0')
		line = ft_strjoin(line, nline);
	while (read(fd, buf, BUFFER_SIZE) != 0)
	{	
		if (readbuf(buf) == 1)
		{
			while (buf[i] != '\n')
				i++;
			nline = ft_strjoin("\0", &buf[i + 1]);
			buf[i + 1] = '\0';
			line = ft_strjoin(line, buf);
			return (line);
		}
		else
			line = ft_strjoin(line, buf);
	}
	return (NULL);
}

int	readbuf(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] != 0)
	{
		if (buf[i] == '\n')
			return(1);
		i++;
	}
	return (0);
}




				
