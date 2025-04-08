/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmoudni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 23:55:42 by abmoudni          #+#    #+#             */
/*   Updated: 2024/12/18 23:55:49 by abmoudni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// # include <fcntl.h>
// # include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
ssize_t	ft_indexchr(char *s, int c);
char	*ft_strchr(const char *s, int c);

#endif
