/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandova <ssandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:22:32 by ssandova          #+#    #+#             */
/*   Updated: 2023/12/13 20:28:02 by ssandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*read_from_file(char *static_buffer, int fd);
char	*remaining(char *static_buffer);
char	*ft_strdup_gnl(char *s1);
void	*ft_calloc_gnl(size_t count, size_t size);
char	*ft_strchr_gnl(const char *s, int c);
char	*ft_substr_gnl(char const *s, int start, int len);
int		ft_strlen_gnl(const char *s);
char	*ft_strjoin_gnl(char *s1, char *s2);

#endif
