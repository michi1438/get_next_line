/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:28:44 by mguerga           #+#    #+#             */
/*   Updated: 2023/01/11 12:14:48 by xbeheydt         ###   ########.fr       */
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
char	*fandrline(char *str, char *stradd);
char	*rline(char *str, char *stradd);
void	*ft_calloc(size_t nmemb, size_t size);
int		readforterm(char *buf);
int		readstat(char *buf);
char	*replace_nline(int fd, char *nline);
char *nullify(char *stat);
char	*ifstathasreturn(char *line, char **statline, int i, char *buf);
char *mainwhile(int fd, int *red, char **buf, char **statline, char **line);
char *ifbufhasreturn(char *buf, char **statline, char *line, int red);

#endif
