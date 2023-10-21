/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjorge-m <bjorge-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:30:01 by bjorge-m          #+#    #+#             */
/*   Updated: 2023/10/21 13:42:26 by bjorge-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);

#endif