/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjorge-m <bjorge-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:30:04 by bjorge-m          #+#    #+#             */
/*   Updated: 2023/10/18 18:10:51 by bjorge-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int ft_strchr(const char *s, int c)
{
	if (s == NULL)
		return (0);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *) s);
		s++;
	}
	if ((char)c == *s)
		return ((char *) s);
	return (NULL);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
char	*ft_strdup(const char *s)
{
	int		len;
	char	*mlc;

	len = ft_strlen(s);
	mlc = (char *)malloc ((len + 1) * sizeof(char));
	if (!mlc)
		return (NULL);
	return (ft_strcpy(mlc, s));
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*mal;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	mal = (char *)malloc((len + 1) * sizeof(char));
	if (!mal)
		return (NULL);
	else 
	{
		return (mal);
	}
}