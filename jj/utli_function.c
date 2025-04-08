/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utli_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmoudni <abmoudni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 09:25:55 by abmoudni          #+#    #+#             */
/*   Updated: 2025/04/05 20:13:41 by abmoudni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_strrchrindex(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	if (s[i] == (char)c)
		return (i);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return (i);
		i--;
	}
	return (0);
}

static int	ft_strchrmap(const char *s, int c)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)s;
	if (str[ft_strrchrindex(str, '\n') + 1] == '1')
		i++;
	while (*str)
	{
		if (*str == (char)c)
			i++;
		str++;
	}
	return (i);
}

static char	*read_map(int fd, char *lines)
{
	char	*line;
	char	*temp;

	line = get_next_line(fd);
	while (line)
	{
		if (!lines)
		{
			lines = ft_strdup(line);
			if (!lines)
				error_line(1, line);
		}
		else
		{
			temp = ft_strjoin(lines, line);
			free(lines);
			if (!temp)
				error_line(2, temp);
			lines = temp;
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (lines);
}

static void	extract_map(char *lines_copy, t_map *game)
{
	int		i;
	int		nbr;
	char	*line;

	i = 0;
	line = lines_copy;
	while (*lines_copy && i < game->y)
	{
		nbr = ft_indexchr(lines_copy, '\n');
		if (nbr == -1)
			nbr = ft_strlen(lines_copy);
		game->map[i] = ft_substr(lines_copy, 0, nbr);
		if (!game->map[i])
		{
			free_map(game);
			error_line(5, line);
		}
		lines_copy += nbr;
		if (*lines_copy == '\n')
			lines_copy++;
		i++;
	}
	game->map[i] = NULL;
}

t_map	convert(char *filename)
{
	int		fd;
	char	*lines;
	t_map	game;

	lines = NULL;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		_error(2);
	lines = read_map(fd, lines);
	if (!lines)
		error_line(3, lines);
	game = (t_map){0};
	game.y = ft_strchrmap(lines, '\n');
	game.map = malloc((game.y + 1) * sizeof(char *));
	if (!game.map)
		error_line(4, lines);
	extract_map(lines, &game);
	free(lines);
	return (game);
}
