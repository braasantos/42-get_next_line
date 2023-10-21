/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: braasantos <braasantos@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:30:01 by bjorge-m          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/10/20 13:45:38 by bjorge-m         ###   ########.fr       */
=======
/*   Updated: 2023/10/21 11:40:09 by braasantos       ###   ########.fr       */
>>>>>>> ef1fb21 (files for testing)
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

#ifndef BUFFER_SIZE
<<<<<<< HEAD
#define BUFFER_SIZE 6
=======
#define BUFFER_SIZE 5
>>>>>>> ef1fb21 (files for testing)
#endif

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);

#endif