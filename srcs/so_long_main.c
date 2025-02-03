/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:15:33 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/02/03 14:06:27 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
		return (2);
	map_parsing(argv[1], &map);
	sprite_checker(map);
	game_start(map);
	return (0);
}

void	game_start(t_map *map)
{
	t_game	*game;

	set_game(&game, map);
	put_border(game, map);
	fill_gap(game);
	put_bevel(game);
	put_corner(game, game->size);
	add_decor(game);
	put_map(game, map);
	mlx_loop_hook(game->mlx, render_game, game);
	mlx_hook(game->win, 17, 0, close_x, game);
	mlx_hook(game->win, 2, (1L << 0), player_move, game);
	mlx_loop(game->mlx);
}

void	sprite_checker(t_map *map)
{
	int			fd;
	int			i;
	const char	*paths[28] = {BORD, BORDC, BVL, BVLC, SPKR, LOGO, BTN, ARRW,
			EMPTY1, EMPTY2, WALL, WALLM, WALLC, EXITC, EXITO, COLT, CHARA1,
			CHARA2, SEMPTY1, SEMPTY2, SWALL, SWALLM, SWALLC, SEXITC, SEXITO,
			SCOLT, SCHARA1, SCHARA2};

	i = -1;
	while (++i < 28)
	{
		fd = open(paths[i], O_RDONLY);
		if (fd > 2)
			close(fd);
		else
		{
			map->error = 8;
			error_exit(map->error, map);
		}
	}
}
