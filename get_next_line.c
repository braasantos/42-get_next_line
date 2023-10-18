/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjorge-m <bjorge-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:29:54 by bjorge-m          #+#    #+#             */
/*   Updated: 2023/10/18 18:54:32 by bjorge-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
/*
* procura a new line e devolve a posicao da new line 
*/
int	ft_findnl(char *s)
{
	if(!s)
		return (1);
	while(*s && *s != '\n')
		s++;
	if (*s == '\n')
		return (1);
	return (s);
}
char	*get_next_line(int fd)
{
	// a variavel que vai guardar tudo
	static char		*buffer; 
	char	*line;
	int	bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0) // buffer_size n pode ser negativo nem igual a 0 senao n vai ler nada 
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buffer)
		return (NULL);






		
	if (read() < 0)
		return (NULL);
		free(buffer);
		free(line);
	return (line);
}
// uma funcao para encontrar a new line e devolver a uma string com s caracters encontrados ate agora

/*int	main(void)
{
	int		fd;
	char	*line;
	fd = open("", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line = NULL)
			break;
		printf("%s\n", line);
		free(line);
	}
	return (0);
}*/
	