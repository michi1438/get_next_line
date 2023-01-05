/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 11:52:48 by mguerga           #+#    #+#             */
/*   Updated: 2023/01/05 20:14:57 by xbeheydt         ###   ########.fr       */
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
	ptr = ft_calloc(sizeof(char),  (ft_strlen(s1) + ft_strlen(s2) + 1));
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

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char *rline(char *str,char *stradd)
{
	char	*nptr;
	
	nptr = ft_strjoin(str, stradd);
	return (nptr);
}

char *fandrline(char *str,char *stradd)
{
	char	*nptr;
	
	nptr = ft_strjoin(str, stradd);
	if (str != NULL)
		free (str);
	return (nptr);
}

char	*freeandreplace(char *oldstr, char *str, int ind)
{
	char	*nptr;

	if (str == NULL)
		return (NULL);
	nptr = ft_strjoin("", &str[ind + 1]); 
	if (oldstr != NULL && str != NULL)
		free(oldstr);
	return (nptr);
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
