/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmoudni <abmoudni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 22:30:16 by abmoudni          #+#    #+#             */
/*   Updated: 2025/04/08 21:51:57 by abmoudni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	setup_game1(t_map *game)
{
	int	img_size;

	img_size = 64;
	game->img_emptyback = mlx_xpm_file_to_image(game->mlx,
			"textures/emptyback.xpm", &img_size, &img_size);
	if (!game->img_emptyback)
		error(6, game);
	game->img_pwithe = mlx_xpm_file_to_image(game->mlx,
			"textures/door1.xpm", &img_size, &img_size);
	if (!game->img_pwithe)
		error(6, game);
}

void	setup_game(t_map *game)
{
	int	img_size;

	img_size = 64;
	game->wall_img = mlx_xpm_file_to_image(game->mlx, "textures/1.xpm",
			&img_size, &img_size);
	if (!game->wall_img)
		error(6, game);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx, "textures/10.xpm",
			&img_size, &img_size);
	if (!game->img_collectible)
		error(6, game);
	game->img_player = mlx_xpm_file_to_image(game->mlx, "textures/3.xpm",
			&img_size, &img_size);
	if (!game->img_player)
		error(6, game);
	game->img_door = mlx_xpm_file_to_image(game->mlx, "textures/door.xpm",
			&img_size, &img_size);
	if (!game->img_door)
		error(6, game);
	game->img_odoor = mlx_xpm_file_to_image(game->mlx, "textures/odoor.xpm",
			&img_size, &img_size);
	if (!game->img_odoor)
		error(6, game);
	setup_game1(game);
}
