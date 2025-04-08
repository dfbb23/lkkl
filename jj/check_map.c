/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmoudni <abmoudni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 09:33:01 by abmoudni          #+#    #+#             */
/*   Updated: 2025/04/06 12:55:32 by abmoudni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_map_elements2(t_map *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] != 'C' && game->map[i][j] != 'E'
				&& game->map[i][j] != 'P' && game->map[i][j] != '0'
				&& game->map[i][j] != '1')
				error(3, game);
			if (game->map[i][j] == 'E')
			{
				game->e_pos_x = j;
				game->e_pos_y = i;
			}
			j++;
		}
		i++;
	}
}

void	check_map_elements(t_map *game)
{
	int	i;
	int	j;

	check_map_elements2(game);
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				game->c++;
			else if (game->map[i][j] == 'E')
				game->e++;
			else if (game->map[i][j] == 'P')
				game->p++;
			if (game->p > 1 || game->e > 1)
				error(2, game);
			j++;
		}
		i++;
	}
	if (game->c == 0 || game->e != 1 || game->p != 1)
		error(2, game);
}

static void	flood_fill(t_map *game, char **map, t_point start)
{
	if (map[start.y][start.x] == '1' || map[start.y][start.x] == 'x')
		return ;
	if (map[start.y][start.x] == 'P')
		game->c_p++;
	else if (map[start.y][start.x] == 'E')
		game->c_e++;
	else if (map[start.y][start.x] == 'C')
		game->c_c++;
	map[start.y][start.x] = 'x';
	flood_fill(game, map, (t_point){start.x + 1, start.y});
	flood_fill(game, map, (t_point){start.x - 1, start.y});
	flood_fill(game, map, (t_point){start.x, start.y + 1});
	flood_fill(game, map, (t_point){start.x, start.y - 1});
}

static char	**copy_map(t_map *game)
{
	char	**map_copy;
	int		i;
	int		j;

	map_copy = malloc((game->y + 1) * sizeof(char *));
	if (!map_copy)
		error(5, game);
	i = 0;
	while (i < game->y)
	{
		map_copy[i] = malloc(game->x + 1);
		if (!map_copy[i])
			error(5, game);
		j = 0;
		while (j < game->x + 1)
		{
			map_copy[i][j] = game->map[i][j];
			j++;
		}
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

void	check_acces(t_map *game)
{
	t_point	player_pos;
	int		i;
	int		j;
	char	**map_copy;

	player_pos = (t_point){-1, -1};
	i = 0;
	while (i < game->y && player_pos.x == -1)
	{
		j = 0;
		while (j < game->x)
		{
			if (game->map[i][j] == 'P')
				player_pos = (t_point){j, i};
			j++;
		}
		i++;
	}
	map_copy = copy_map(game);
	flood_fill(game, map_copy, player_pos);
	if (game->c_p != game->p || game->c_e != game->e || game->c_c != game->c)
		flood_error(3, game, map_copy);
	free_array(map_copy);
}
