/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revanite <revanite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 03:42:56 by revanite          #+#    #+#             */
/*   Updated: 2023/05/25 08:25:51 by revanite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

char	*end_of_line(char **line, char buffer[]);
int		buffer_reset(char **line, char buffer[]);
int		reading(char **line, char buffer[], int fd, ssize_t *bytes_read);
void	shift_buffer(char buffer[]);

char	*get_next_line(int fd)
{
	static char			buffer[100][BUFFER_SIZE + 1];
	char				*line;
	ssize_t				bytes_read;

	line = NULL;
	bytes_read = 0;
	if (fd < 0 || fd > 99)
		return (NULL);
	if (!buffer_empty(buffer[fd]))
		if (end_of_line(&line, buffer[fd]) == NULL)
			return (NULL);
	if (find_nl(line) <= 0)
		if (!reading(&line, buffer[fd], fd, &bytes_read))
			return (NULL);
	if (bytes_read == -1)
	{
		if (line)
			free(line);
		return (NULL);
	}
	line = end_of_line(&line, buffer[fd]);
	return (line);
}

int	reading(char **line, char buffer[], int fd, ssize_t *bytes_read)
{
	*bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (*bytes_read > 0)
	{
		if (find_nl(buffer) > 0)
			break ;
		if (!buffer_reset(line, buffer))
			return (0);
		*bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	return (1);
}

char	*end_of_line(char **line, char buffer[])
{
	size_t				buffer_len;
	signed long long	line_len;

	if (*line != NULL)
	{
		line_len = find_nl(*line);
		if (line_len > 0)
		{
			ft_strncat(buffer, (*line + line_len), ft_strlen(*line) - line_len);
			*line = ft_recalloc(*line, line_len + 1);
			return (*line);
		}
	}
	if (buffer_empty(buffer))
		return (*line);
	if (find_nl(buffer) < 0)
		buffer_len = ft_strlen(buffer);
	else
		buffer_len = find_nl(buffer);
	*line = ft_recalloc(*line, ft_strlen(*line) + buffer_len + 1);
	if (!*line)
		return (NULL);
	ft_strncat(*line, buffer, buffer_len);
	shift_buffer(buffer);
	return (*line);
}

int	buffer_reset(char **line, char buffer[])
{
	signed long long	buff_len;
	size_t				i;

	buff_len = find_nl(buffer);
	if (buff_len > 0)
		*line = ft_recalloc(*line, ft_strlen(*line) + find_nl(buffer) + 1);
	else
		*line = ft_recalloc(*line, ft_strlen(*line) + ft_strlen(buffer) + 1);
	if (*line == NULL)
		return (0);
	ft_strncat(*line, buffer, find_nl(buffer));
	i = 0;
	while (i < BUFFER_SIZE)
		buffer[i++] = 0;
	return (1);
}

void	shift_buffer(char buffer[])
{
	size_t	len;
	size_t	i;

	len = find_nl(buffer);
	i = 0;
	while (buffer[len])
		buffer[i++] = buffer[len++];
	while (i < BUFFER_SIZE)
		buffer[i++] = 0;
}
