/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmoudni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 23:55:16 by abmoudni          #+#    #+#             */
/*   Updated: 2024/12/18 23:55:19 by abmoudni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	ft_indexchr(char *s, int c)
{
	ssize_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	if (s == NULL)
		return (NULL);
	str = (char *)s;
	while (*str)
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	new = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (new == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		new[i + j] = s2[j];
		j++;
	}
	new[i + j] = '\0';
	return (new);
}

char	*ft_strdup(const char *s)
{
	char	*v;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	v = malloc(len + 1);
	if (v == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		v[i] = s[i];
		i++;
	}
	v[len] = '\0';
	return (v);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	if (!s)
		return (ft_strdup(""));
	i = 0;
	if (len == 0)
		return (ft_strdup(""));
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	new = malloc(len + 1);
	if (!new)
		return (NULL);
	while (i < len)
	{
		new[i] = s[start];
		i++;
		start++;
	}
	new[i] = ('\0');
	return (new);
}
