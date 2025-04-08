/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmoudni <abmoudni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 09:25:03 by abmoudni          #+#    #+#             */
/*   Updated: 2025/04/05 20:28:32 by abmoudni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_errors(char *filename)
{
	int		len;
	int		i;
	char	*ext;

	len = ft_strlen(filename);
	if (len < 5)
		_error(3);
	ext = ft_strrchr(filename, '/');
	if (ext && ft_strlen(ext) < 6)
		_error(3);
	ext = ".ber";
	i = 0;
	while (i < 4)
	{
		if (filename[len - 4 + i] != ext[i])
			_error(1);
		i++;
	}
}

static void	checkmap2(t_map *game)
{
	int	len1;
	int	i;
	int	len;

	len1 = ft_strlen(game->map[0]);
	game->x = len1;
	i = 0;
	while (game->map[i])
	{
		len = ft_strlen(game->map[i]);
		if (len1 != len || game->map[i][0] != '1' || game->map[i][len
			- 1] != '1')
			error(1, game);
		i++;
	}
}

void	check_map(t_map *game)
{
	int	j;

	j = 0;
	checkmap2(game);
	while (game->map[0][j])
	{
		if (game->map[0][j] != '1' || game->map[game->y - 1][j] != '1')
			error(1, game);
		j++;
	}
}
