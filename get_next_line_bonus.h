/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revanite <revanite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 03:45:56 by revanite          #+#    #+#             */
/*   Updated: 2023/05/29 07:00:34 by revanite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include	<stdlib.h>
# include	<unistd.h>
# include	<fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	(42)
# endif

# define EOF     (-1)

char				*get_next_line(int fd);
char				*ft_recalloc(char **line, size_t size);
char				*ft_strncat(char *dest, char *src, size_t n);
signed long long	find_nl(const char *buffer, int opt);
int					ft_memset(char **s, int c, size_t n, int opt);
void				leftovers(char **buffer, char **line, int opt, size_t len);
void				shift_buffer(char **buffer);

#endif  //      GET_NEXT_LINE_BONUS_H