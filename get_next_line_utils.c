/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 11:52:48 by mguerga           #+#    #+#             */
/*   Updated: 2023/01/11 18:41:12 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ptr = ft_calloc(sizeof(char), (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (ptr == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		ptr[i] = s2[j];
		i++;
		j++;
	}
	ptr[i] = '\0';
	return (ptr);
}

size_t	ft_strlen(char *s)
{
	int	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*freeandreplace(char *oldstr, char *stradd, int ind)
{
	char	*nptr;

	if (ind >= 0)
	{
		nptr = ft_strjoin("", &stradd[ind + 1]);
		if (oldstr != NULL)
		{
			free(oldstr);
			oldstr = NULL;
		}
		return (nptr);
	}
	else
	{
		nptr = ft_strjoin(oldstr, stradd);
		free (oldstr);
		return (nptr);
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	i;

	i = 0;
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	while (i < (nmemb * size))
	{
		((char *)(ptr))[i] = '\0';
		i++;
	}
	return (ptr);
}

int	readforterm(char *buf, int toggle)
{
	int	i;

	i = 0;
	if (toggle == 1)
	{
		while (buf[i] != '\0')
		{
			if (buf[i] == '\n')
				return (i);
			i++;
		}
		return (-1);
	}
	else
	{
		i = 0;
		while (i < BUFFER_SIZE)
		{
			if (buf[i] == '\n' || buf[i] == '\0')
				return (i);
			i++;
		}
		return (-1);
	}
}
