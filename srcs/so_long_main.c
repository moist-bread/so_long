/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:15:33 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/01/24 13:56:20 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
		return (2);
	map_parsing(argv[1], &map);
	// - check if the sprite xpms exist
	// game_stort_test(map);
	// game_stort_test2(map);
	game_start(map);
	// free_map(map, map->heigth);
	return (0);
}

void	game_start(t_map *map)
{
	t_game	*game;

	set_game(&game, map);
	put_border(game, map);
	fill_gap(game);
	put_bevel(game);
	put_corner(game, game->spr_size);
	add_decor(game);
	put_map(game, map);
	// mlx_put_image_to_window(game->mlx, game->win, game->bg->img, 0, 0);
	// put_player(game);
	// mlx_put_image_to_window(game->mlx, game->win, game->fg->img, 0, 0);
	// mlx_clear_window(game->mlx, game->win);
	mlx_loop_hook(game->mlx, put_player, game);
	mlx_key_hook(game->win, player_move, game);
	mlx_loop(game->mlx);
}
