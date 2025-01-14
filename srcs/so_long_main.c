/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:15:33 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/01/14 18:06:31 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
		return (2);
	map_parsing(argv[1], &map);
	// game_stort_test(map);
	// game_stort_test2(map);
	game_start(map);
	free_map(map, map->heigth);
	return (0);
}

void	game_start(t_map *map)
{
	t_game	*game;

	set_game(&game, map);
	sprite_to_bg_img(game, game->sprite->bord, 90, 90);
	// mlx_put_image_to_window(game->mlx, game->win, game->bg->img, 0, 0);
	// put_border(game, map);
	// put_map(game, map);
	mlx_loop(game->mlx);
}
