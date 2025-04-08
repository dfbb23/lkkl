/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmoudni <abmoudni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:02:41 by abmoudni          #+#    #+#             */
/*   Updated: 2025/04/07 01:14:18 by abmoudni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	game;

	if (argc != 2)
		_error(3);
	check_errors(argv[1]);
	game = convert(argv[1]);
	check_map(&game);
	check_map_elements(&game);
	check_acces(&game);
	game.mlx = mlx_init();
	if (!game.mlx)
		return (write(2, "Error\nMLX connection\n", 21), free_map(&game), 1);
	game.window = mlx_new_window(game.mlx, game.x * 64, game.y * 64, "so long");
	if (!game.window)
		return (write(2, "Error\nCreate window\n", 20), free_map(&game), 1);
	setup_game(&game);
	render_map(&game);
	game.contmove = -1;
	mlx_key_hook(game.window, handle_input, &game);
	mlx_hook(game.window, 17, 0, close_game, &game);
	mlx_loop(game.mlx);
	free_game(&game);
	return (0);
}
