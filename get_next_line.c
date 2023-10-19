/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjorge-m <bjorge-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:29:54 by bjorge-m          #+#    #+#             */
/*   Updated: 2023/10/19 19:25:40 by bjorge-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/*
* concatena a string ate a newline
*/
char	*ft_strlcat(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	d_len;
	size_t	s_len;

	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	i = d_len;
	j = 0;
	if (i >= size || size == 0)
		return (src);
	while (src[j] && j < size - i)
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (dst);
}
/*
* cria uma nova string com o conteudo do buffer ate a newline
*/
char	*ft_strlcpy(char *dst, const char *src, int size)
{
	int	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < size)
		{
			dst[i] = src[i];
			i++;
		}
		if (src[i] == '\n')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (dst);
}

/*
* procura a new line e devolve a posicao da new line 
*/
char	*ft_findnl(char *s, char *buffer)
{
	int i;
	i = 0;
	if(!s[i])
		return (NULL);
	while(s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
	{
		buffer = ft_strlcpy(buffer, s, i);
		//printf("%s\n", buffer);
	}
	else 
	{		i++;
		buffer = ft_strlcpy(buffer, s, i);
		//buffer = ft_strlcat(buffer, s, i);
	}
	return (buffer);
}

char	*add_to_buff(int fd, char *buffer)
{
	char *buff;
	int bytes;

	buff = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buff)
		return (NULL);
	//bytes = 1;
	bytes = read(fd, buff, BUFFER_SIZE);
	//printf("%s\n", buff);
 	while (bytes != 0)
	{
		if (bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		else 
		{
			ft_findnl(buff, buffer);
			break ;
		}
	}
	free(buff);
	return (buffer);
}
//else ft_strchr(buffer, '\n');

char	*get_next_line(int fd)
{
	// a variavel que vai guardar tudo
	char	*line;
	static char buffer[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0) // buffer_size n pode ser negativo nem igual a 0 senao n vai ler nada 
		return (NULL);
	line = add_to_buff(fd, buffer);
	if (!line)
		return (NULL);
		//printf("%s\n", line);
	return (line);
}
// uma funcao para encontrar a new line e devolver a uma string com s caracters encontrados ate agora

int	main(void)
{
	int		fd;
	char	*line;
	int i = 0;
	fd = open("test.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		else
		{
		printf("%s", line);
		break ;	
		}
	}
	return (0);
}
	