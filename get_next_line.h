/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:28:44 by mguerga           #+#    #+#             */
/*   Updated: 2023/01/09 09:58:14 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*freeandget_next_line(int fd, char *nline);
void	ft_putstr_fd(char *str, int fd);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *s);
char	*freeandreplace(char *oldstr, char *str, int ind);
char *fandrline(char *str,char *stradd);
char *rline(char *str,char *stradd);
void	*ft_calloc(size_t nmemb, size_t size);
int		readforterm(char *buf);
int	readstat(char *buf);

#endif
