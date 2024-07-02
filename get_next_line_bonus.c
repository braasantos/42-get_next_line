/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjorge-m <bjorge-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:46:27 by bjorge-m          #+#    #+#             */
/*   Updated: 2024/07/02 15:50:47 by bjorge-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/// @brief          Allocate memory dinamicaly
/// @param nmemb    The number of bytes to allocate
/// @param size     The size of the variable
/// @return         A pointer to the memory
void	*safe_calloc(size_t nmemb, size_t size)
{
    void    *ptr;

    ptr = ft_calloc(nmemb, size);
    if (!ptr)
        return (NULL);
    return (ptr);
}

/// @brief			Function to check for the next line
/// @param s		The string to check
/// @return			the string 
char	*ft_nextline(char *s)
{
	char	*mlc;
	int		i;
	int		j;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\0')
		return (free(s), NULL);
	mlc = safe_calloc((ft_strlen(s) + 1 - i), sizeof(char));
	if (!mlc)
		return (NULL);
	i++;
	j = 0;
	while (s[i])
		mlc[j++] = s[i++];
	mlc[j] = '\0';
	if (s)
		free(s);
	return (mlc);
}

/// @brief			Function to free the variables passed
/// @param buff		
/// @param buffer 
/// @return			NULL
char	*ft_clean(char *buff, char *buffer)
{
	if (buff)
		free(buff);
	if (buffer)
		free(buffer);
	return (NULL);
}

/// @brief			Add the content to the buffer and 
///					check if theres a new line
/// @param fd		The file destriptor recieved
/// @param buffer	The Static variable to hold the values
/// @return			the buffer
char	*add_to_buff(int fd, char *buffer)
{
	char	*buff;
	int		bytes;

	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buff)
		return (NULL);
	bytes = 1;
	while (bytes != 0 && !ft_findnl(buffer))
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == 0)
		{
			free(buff);
			buff = NULL;
			if (buffer)
				return (buffer);
			return (NULL);
		}
		if (bytes == -1)
			return (ft_clean(buff, buffer));
		buff[bytes] = '\0';
		buffer = ft_strjoin(buffer, buff);
	}
	ft_clean(buff, NULL);
	return (buffer);
}

/// @brief			Function to read form a file descriptor and return a line
/// @param fd		The file descriptor to read from
/// @return			The line from the filde descriptor
char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer[MAX_FD];

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= MAX_FD)
		return (NULL);
	buffer[fd] = add_to_buff(fd, buffer[fd]);
	if (!buffer[fd] || buffer[fd][0] == '\0')
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	line = ft_strdup(buffer[fd]);
	buffer[fd] = ft_nextline(buffer[fd]);
	return (line);
}

// int main(int ac, char **av)
// {
//     int fd[ac - 1];
//     int i;
//     char *line;
//     i = 1;
//     while (i < ac)
//     {
//         fd[i - 1] = open(av[i], O_RDONLY);
//         if (fd[i - 1] == -1) {
//             perror("Error opening file");
//             return 1;
//         }
//         line = get_next_line(fd[i - 1]);
//         while (line)
//         {
//             printf("%s", line);
//             free(line);
//             line = get_next_line(fd[i - 1]);
//         }
//         close(fd[i - 1]);
//         i++;
//     }
//     return (0);
// }
