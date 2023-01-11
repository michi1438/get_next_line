/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:03:23 by xbeheydt          #+#    #+#             */
/*   Updated: 2023/01/11 19:53:17 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42 
# endif

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct sct {
	char	*buf;
	char	*line;
}	t_strs;

char	*get_next_line(int fd);
char	*freeandget_next_line(int fd, char *nline);
void	ft_putstr_fd(char *str, int fd);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *s);
char	*freeandreplace(char *oldstr, char *stradd, int ind);
char	*rline(char *str, char *stradd);
void	*ft_calloc(size_t nmemb, size_t size);
int		readforterm(char *buf, int toggle);
char	*replace_nline(int fd, char *nline);
char	*ifbufhasreturn(t_strs *strings, char **statline, int i, int *red);
char	*mainwhile(int fd, t_strs *strings, char **statline, int *red);
char	*ifstatret(t_strs *strings, char **statline, int i);
char	*stat_after_read(char **statline, t_strs *strings, int red, int i);

#endif
