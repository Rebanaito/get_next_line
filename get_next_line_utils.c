/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revanite <revanite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 05:12:58 by revanite          #+#    #+#             */
/*   Updated: 2023/05/25 07:55:57 by revanite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

char	*ft_recalloc(char *line, size_t size)
{
	char	*new;
	size_t	i;

	new = (char *)malloc(size);
	if (new == NULL)
	{
		free(line);
		return (NULL);
	}
	i = 0;
	while (i < size)
		new[i++] = 0;
	i = 0;
	if (line)
	{
		while (line[i])
		{
			new[i] = line[i];
			i++;
		}
		free(line);
	}
	return (new);
}

char	*ft_strncat(char *dest, char *src, size_t n)
{
	size_t	i;
	size_t	j;

	if (!dest || !src)
		return (NULL);
	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (src[j] && j < n)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = 0;
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

signed long long	find_nl(const char buffer[])
{
	signed long long	len;

	if (buffer == NULL)
		return (0);
	len = -1;
	while (buffer[++len])
	{
		if (buffer[len] == '\n')
		{
			len++;
			return (len);
		}
	}
	return (-1);
}

int	buffer_empty(char *buffer)
{
	unsigned long long	i;

	i = 0;
	while (i < BUFFER_SIZE)
		if (buffer[i++])
			return (0);
	return (1);
}
