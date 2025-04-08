/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmoudni <abmoudni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 09:26:37 by abmoudni          #+#    #+#             */
/*   Updated: 2025/04/08 22:08:42 by abmoudni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map *game)
{
	int	i;

	i = 0;
	if (game->map)
	{
		while (game->map[i])
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
	}
}

void	free_game(t_map *game)
{
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	if (game->mlx)
	{
		if (game->wall_img)
			mlx_destroy_image(game->mlx, game->wall_img);
		if (game->img_collectible)
			mlx_destroy_image(game->mlx, game->img_collectible);
		if (game->img_player)
			mlx_destroy_image(game->mlx, game->img_player);
		if (game->img_door)
			mlx_destroy_image(game->mlx, game->img_door);
		if (game->img_odoor)
			mlx_destroy_image(game->mlx, game->img_odoor);
		if (game->img_odoor)
			mlx_destroy_image(game->mlx, game->img_emptyback);
		if (game->img_pwithe)
			mlx_destroy_image(game->mlx, game->img_pwithe);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free_map(game);
}

void	free_array(char **map_copy)
{
	int	i;

	i = 0;
	while (map_copy[i])
	{
		free(map_copy[i]);
		i++;
	}
	free(map_copy);
}
