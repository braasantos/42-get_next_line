/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjorge-m <bjorge-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:30:04 by bjorge-m          #+#    #+#             */
/*   Updated: 2024/07/02 15:39:15 by bjorge-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/// @brief			Counts the size of a strig
/// @param s		The string to be counted
/// @return			The size of the string
size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

/// @brief			Works as a flag to check for a new line on the string
/// @param s		The string to check the new line
/// @return			1 if find a new line and 0 if not
int	ft_findnl(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
	{
		i++;
	}
	if (s[i] == '\n')
		return (1);
	return (0);
}

/// @brief			Allocate memory dinamically
/// @param nmemb	The number os bytes to allocate
/// @param size		The size of the variable
/// @return			A pointer to the memory allocated
void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*b;
	char	c;
	size_t	i;

	c = 0;
	i = 0;
	b = malloc(nmemb * size);
	if (!b) 
		return (NULL);
	else
	{
		while (i < (nmemb * size))
		{
			b[i] = c;
			i++;
		}
	}
	return (b);
}

/// @brief			Join two strings
/// @param s1		The first string to join
/// @param s2		The second string to join to the first
/// @return			The new string created with the first + the second
char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*mlc;

	mlc = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!mlc)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		mlc[i] = s1[i];
		i++;
	}
	j = 0;
	if (s1)
	{
		free(s1);
		s1 = NULL;
	}
	while (s2 && s2[j])
		mlc[i++] = s2[j++];
	mlc[i] = '\0';
	return (mlc);
}

/// @brief			Create a copy of the string passed
/// @param s		The string to be copied
/// @return			The new string created
char	*ft_strdup( char *s)
{
	int		i;
	char	*mlc;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	mlc = ft_calloc(i + 2, sizeof(char));
	if (!mlc)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		mlc[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		mlc[i] = s[i];
		i++;
	}
	mlc[i] = '\0';
	return (mlc);
}
