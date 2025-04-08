/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmoudni <abmoudni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 09:26:13 by abmoudni          #+#    #+#             */
/*   Updated: 2025/04/08 21:56:00 by abmoudni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put(t_map *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
				if(i == game->e_pos_y && j == game->e_pos_x)
					mlx_put_image_to_window(game->mlx, game->window,
						game->img_pwithe, j * 64, i * 64);
				else 
					mlx_put_image_to_window(game->mlx, game->window,
						game->img_player, j * 64, i * 64);
			}
			j++;
		}
		i++;
	}
}

static void	put_image(t_map *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '0')
				mlx_put_image_to_window(game->mlx, game->window,
					game->img_emptyback, j * 64, i * 64);
			else if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->window,
					game->img_collectible, j * 64, i * 64);
			j++;
		}
		i++;
	}
	put(game);
}

static void	putimage(t_map *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->window, game->wall_img,
					j * 64, i * 64);
			else if (game->map[i][j] == 'E')
			{
				if (game->c > 0)
					mlx_put_image_to_window(game->mlx, game->window,
						game->img_door, j * 64, i * 64);
				else if (game->c == 0)
					mlx_put_image_to_window(game->mlx, game->window,
						game->img_odoor, j * 64, i * 64);
			}
			j++;
		}
		i++;
	}
}

void	render_map(t_map *game)
{
	mlx_clear_window(game->mlx, game->window);
	putimage(game);
	put_image(game);
}
