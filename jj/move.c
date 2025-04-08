/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmoudni <abmoudni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 09:27:15 by abmoudni          #+#    #+#             */
/*   Updated: 2025/04/06 13:09:49 by abmoudni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	handlekeycode(int keycode, t_map *game, int *new_x, int *new_y)
{
	if (keycode == 65307)
		close_game(game);
	else if (keycode == 65362)
		(*new_y)--;
	else if (keycode == 65364)
		(*new_y)++;
	else if (keycode == 65361)
		(*new_x)--;
	else if (keycode == 65363)
		(*new_x)++;
}

static void	contmove(t_map *game)
{
	game->contmove++;
	if (game->contmove > 0)
	{
		ft_putnbr_fd(game->contmove, 1);
		write(1, "\n", 1);
	}
}

int	handle_input(int keycode, t_map *game)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x;
	new_y = game->player_y;
	handlekeycode(keycode, game, &new_x, &new_y);
	if (game->map[new_y][new_x] != '1')
	{
		contmove(game);
		if (game->map[new_y][new_x] == 'C')
			game->c--;
		if (game->map[new_y][new_x] == 'E' && game->c == 0)
			close_game(game);
		game->map[game->player_y][game->player_x] = '0';
		game->map[game->e_pos_y][game->e_pos_x] = 'E';
		game->map[new_y][new_x] = 'P';
		game->player_x = new_x;
		game->player_y = new_y;
		render_map(game);
	}
	return (0);
}
