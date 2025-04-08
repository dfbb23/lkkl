/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmoudni <abmoudni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 09:25:23 by abmoudni          #+#    #+#             */
/*   Updated: 2025/04/07 01:13:26 by abmoudni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(int code, t_map *game)
{
	if (code == 1)
		write(2, "Error\n Incomplete wall\n", 23);
	else if (code == 2)
		write(2, "Error\n Incorrect amount of P, C or E\n", 37);
	else if (code == 3)
		write(2, "Error\n Invalid character\n", 25);
	else if (code == 5)
		write(2, "Error\n Error malloc \n", 21);
	else if (code == 6)
		write(2, "Error\n Images not load\n", 23);
	free_game(game);
	exit(1);
}

void	_error(int code)
{
	if (code == 1)
		write(2, "Error\n Invalid file extension\n", 30);
	else if (code == 2)
		write(2, "Error\n Error fd or file not find\n", 33);
	else if (code == 3)
		write(2, "Error\n Invalid arguments\n", 25);
	exit(1);
}

int	close_game(t_map *game)
{
	free_game(game);
	exit(0);
	return (0);
}

void	error_line(int code, char *line)
{
	if (code == 1)
		write(2, "Error\n Error malloc ft_strdup\n", 30);
	else if (code == 2)
		write(2, "Error\n Error malloc ft_strjoin\n", 31);
	else if (code == 3)
		write(2, "Error\n Error malloc read_map\n", 29);
	else if (code == 4)
		write(2, "Error\n Error malloc convert\n", 28);
	else if (code == 5)
		write(2, "Error\n Error malloc ft_substr\n", 30);
	free(line);
	exit(1);
}

void	flood_error(int code, t_map *game, char **cpy_map)
{
	free_array(cpy_map);
	error(code, game);
}
