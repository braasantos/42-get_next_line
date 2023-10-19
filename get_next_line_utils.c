/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjorge-m <bjorge-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:30:04 by bjorge-m          #+#    #+#             */
/*   Updated: 2023/10/19 16:54:41 by bjorge-m         ###   ########.fr       */
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
int	ft_findnl(char *s)
{
	char *new_str;
	
	if(!s)
		return (0);
	while(*s && *s != '\n')
		s++;
	if (*s == '\n')
		ft_strcpy(new_str, s);
	return (0);
}

int	main(void)
{
	char	src[25] = "Tenho fome"; 
	char	dest[25];

	ft_strcpy(dest, src);
	printf("%s", dest);
}