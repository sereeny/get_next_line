/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandova <ssandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:35:33 by ssandova          #+#    #+#             */
/*   Updated: 2023/12/11 18:04:09 by ssandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "get_next_line_bonus.h"

/*---------------------------------------------------------------------------
The strdup() function allocates sufficient memory for a copy of the string s1,
does the copy, and returns a pointer to it. The pointer may subsequently be 
used as an argument to the function free(3). If insufficient memory is 
available, NULL is returned.
----------------------------------------------------------------------------*/
char	*ft_strdup_gnl(char *s1)
{
	char			*pointer;
	unsigned int	i;

	if (!s1)
		return (NULL);
	i = -1;
	pointer = (char *)ft_calloc_gnl((ft_strlen_gnl(s1) + 1), sizeof(char));
	if (!pointer)
		return (NULL);
	while (s1[++i])
		pointer[i] = s1[i];
	return (pointer);
}

/*---------------------------------------------------------------------------
Main GNL function. 
Variables declared.
----------------------------------------------------------------------------*/
char	*get_next_line(int fd)
{
	static char	*static_buffer;
	char		*line;
	int			i;

	if (fd < 0 || read(fd, NULL, 0) < 0 || BUFFER_SIZE < 0)
		return (NULL);
	static_buffer = read_from_file(static_buffer, fd);
	if (static_buffer == NULL)
		return (free(static_buffer), NULL);
	i = 0;
	while (static_buffer[i] != '\0')
		i++;
	line = ft_substr_gnl(static_buffer, 0, i + 1);
	static_buffer = remaining(static_buffer);
	return (line);
}

char	*read_from_file(char *static_buffer, int fd)
{
	int			bytes_read;
	char		*buffer;

	buffer = ft_calloc_gnl(BUFFER_SIZE + 1, sizeof(char));
	if (buffer == NULL)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buffer), NULL);
		buffer[bytes_read] = '\0';
		if (static_buffer == NULL)
			static_buffer = ft_calloc_gnl(1, 1);
		static_buffer = ft_strjoin_gnl(static_buffer, buffer);
		if (!*static_buffer)
			return (free (static_buffer), free (buffer), buffer = NULL, NULL);
	}
	return (free (buffer), static_buffer);
}

char	*remaining(char *static_buffer)
{
	char	*temporal;

	temporal = ft_strdup_gnl(ft_strchr_gnl(static_buffer, '\n'));
	free (static_buffer);
	if (temporal != NULL)
		static_buffer = ft_strdup_gnl(temporal + 1);
	else
		static_buffer = NULL;
	return (free (temporal), static_buffer);
}
