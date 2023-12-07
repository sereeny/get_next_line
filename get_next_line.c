/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandova <ssandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:35:33 by ssandova          #+#    #+#             */
/*   Updated: 2023/12/07 19:01:22 by ssandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "get_next_line_bonus.h"

/*------------------------------------------------------------------------ 
 The main function to get the next line from the file descriptor. 
 get_next_line reads lines from the input file using the buffer.
 Aims to find and return each line one at a time without disturbing            
 the rest of the file and avoiding reading the entire file at once. 
 It also handles edge cases and errors elegantly.     
 ----------------------------------------------------------------------- */

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	char	*ptr2;

	ptr = (char *)s1;
	ptr2 = (char *)malloc(ft_strlen(s1) + 1);
	if (ptr == 0)
		return (0);
	ft_strlcpy(ptr2, ptr, ft_strlen(s1) + 1);
	return (ptr2);
}

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
	while (static_buffer[i] != '\0' && static_buffer[i] != '\0')
		i++;
	line = ft_substr(static_buffer, 0, i + 1);
	static_buffer = remaining(static_buffer);
	return (line);
}

static char	*read_from_file(char *static_buffer, int fd)
{
	int			bytes_read;
	char		*buffer;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (buffer == NULL)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buffer), NULL);
		buffer[bytes_read] = '\0';
		static_buffer = append_buffer(static_buffer, buffer);
		if (ft_strchr(static_buffer, '\n'))
			break ;
	}
	return (free (buffer), NULL);
}

static char	*remaining(char *static_buffer)
{
	char	*temporal;

	temporal = ft_strdup(ft_strchr(static_buffer, '\n'));
	free(static_buffer);
	if (temporal != NULL)
		static_buffer = ft_strdup(temporal + 1);
	else
		static_buffer = NULL;
	return (free (temporal), static_buffer);
}