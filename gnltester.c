/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnltester.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:55:25 by mguerga           #+#    #+#             */
/*   Updated: 2022/12/30 20:03:09 by xbeheydt         ###   ########.fr       */
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
		write(1, "P", 1);
		ft_putstr_fd(nline, 1);
		nline = get_next_line(fd);
	}
	return(fd);
}

void ft_putstr_fd(char *str, int fd)
{
	int i;
	
	i = 0;
	while (str[i] != '\0')
		write(1, &str[i++], fd);
}
