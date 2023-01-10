/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnltester.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:55:25 by mguerga           #+#    #+#             */
/*   Updated: 2023/01/10 20:14:41 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main()
{
	int	fd;
	char	*nline;
	
	fd = open("test.txt", O_RDONLY); 
	nline = get_next_line(fd);
	while (nline != NULL)
	{
		write(1, "i", 1);
		ft_putstr_fd(nline, 1);
		nline = replace_nline(fd, nline);
	}
	printf("%s\n", nline);
	free (nline);
	return(fd);
}

char *replace_nline(int fd, char *nline)
{
	char *nptr;

	nptr = get_next_line(fd);
	free(nline);
	return(nptr);
}

void ft_putstr_fd(char *str, int fd)
{
	int i;
	
	i = 0;
	while (str[i] != '\0')
		write(1, &str[i++], fd);
}
