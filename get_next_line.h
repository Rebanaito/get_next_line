/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revanite <revanite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 03:45:56 by revanite          #+#    #+#             */
/*   Updated: 2023/05/25 08:56:24 by revanite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include	<stdlib.h>
# include	<unistd.h>
# include	<fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	(42)
# endif

# define EOF     (-1)

char				*get_next_line(int fd);
char				*ft_recalloc(char *line, size_t size);
char				*ft_strncat(char *dest, char *src, size_t n);
size_t				ft_strlen(const char *s);
signed long long	find_nl(const char buffer[]);
int					buffer_empty(char *buffer);

#endif  //      GET_NEXT_LINE_H