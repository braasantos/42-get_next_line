/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjorge-m <bjorge-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:46:27 by bjorge-m          #+#    #+#             */
/*   Updated: 2023/10/20 18:51:09 by bjorge-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;
	if(!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}
/*
* concatena a string ate a newline
*/
char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	size_t	s1_len;
	size_t	s2_len;
	char *mlc;

	s2_len = ft_strlen(s2);
	s1_len = ft_strlen(s1);
	mlc = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!mlc)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		mlc[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
		mlc[i++] = s2[j++];
	mlc[i] = '\0';
	return (mlc);
}
/*
* cria uma nova string com o conteudo do buffer ate a newline
*/
char	*ft_strdup(const char *s)
{
	int		len;
	int		i;
	char	*mlc;

	len = ft_strlen(s);
	mlc = (char *)malloc ((len + 1) * sizeof(char));
	if (!mlc)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		mlc[i] = s[i];
		i++;
	}
	mlc[i] = '\0';
	return (mlc);
}
/*
* serve com flag para saber se tem uma new line na string 
*/
int ft_findnl(char *s)
{
	int i;

	i = 0;
	if(!s)
		return (0);
	while(s[i] && s[i] != '\n')
	{
		i++;	
	}
		if(s[i] == '\n')
			return (1);
	return (0);
}
/*
* adiciona o conteudo do ficheiro ao buff e verifica se tem uma new line 
*/
char	*add_to_buff(int fd, char *buffer)
{
	char *buff;
	char *new_str;
	int bytes;

	buff = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buff)
		return (NULL);
	bytes = 1;
 	while (bytes != 0 && !ft_findnl(buffer))
	{	
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(buff);
			if (buffer)
				free(buffer);
			return (NULL);
		}
		buffer = ft_strjoin(buffer, buff);
	}
	//new_str = ft_strdup(buffer);
	free(buff);
	return (buffer);
}
/*
* funcao principal
*/
char	*get_next_line(int fd)
{
	char	*line;
	static char *buffer;

	if (fd < 0 || BUFFER_SIZE <= 0) // buffer_size n pode ser negativo nem igual a 0 senao n vai ler nada 
		return (NULL);
	buffer = add_to_buff(fd, buffer);
	line = ft_strdup(buffer);
	//free(buffer);
	return (line);
}

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

/*int	main(void)
{
	int		fd;
	char	*line;
	fd = open("test.txt", O_RDONLY);	
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line );
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}*/
	