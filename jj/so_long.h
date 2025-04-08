/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmoudni <abmoudni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 09:25:39 by abmoudni          #+#    #+#             */
/*   Updated: 2025/04/08 21:58:53 by abmoudni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include "/usr/include/minilibx-linux/mlx.h"
# include <fcntl.h>
# include <unistd.h>

typedef struct s_map
{
	char	**map;
	int		c;
	int		e;
	int		p;
	int		player_x;
	int		player_y;
	int		x;
	int		y;
	int		c_p;
	int		c_c;
	int		c_e;
	void	*img;
	void	*mlx;
	void	*window;
	void	*wall_img;
	void	*img_collectible;
	void	*img_player;
	void	*img_door;
	void	*img_odoor;
	void	*img_emptyback;
	void 	*img_pwithe;
	int		contmove;
	int		e_pos_x;
	int		e_pos_y;

}			t_map;

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

t_map		convert(char *filename);
void		check_map_elements(t_map *map);
void		check_map(t_map *map);
void		free_game(t_map *game);
int			handle_input(int keycode, t_map *game);
void		render_map(t_map *game);
void		setup_game(t_map *game);
void		check_errors(char *filename);
int			close_game(t_map *game);
void		error(int code, t_map *game);
void		free_map(t_map *game);
void		check_acces(t_map *game);
void		_error(int code);
void		error_line(int code, char *line);
void		free_array(char **map_copy);
void		flood_error(int code, t_map *game, char **cpy_map);

#endif
