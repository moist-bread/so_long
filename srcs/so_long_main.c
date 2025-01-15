/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:15:33 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/01/15 18:52:51 by rduro-pe         ###   ########.fr       */
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
	put_border(game, map);
	put_map(game, map);
	// mlx_put_image_to_window(game->mlx, game->win, game->bg->img, 0, 0);
	// put_player(game);
	// mlx_put_image_to_window(game->mlx, game->win, game->fg->img, 0, 0);
	// mlx_clear_window(game->mlx, game->win);
	mlx_loop_hook(game->mlx, put_player, game);
	mlx_key_hook(game->win, player_move, game);
	mlx_loop(game->mlx);
}

int	player_move(int key, t_game *game)
{
	ft_printf("%d (key)\n", key);
	if (key == 65307)
	{
		ft_printf("shut down\n");
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	else if (key == 'w' || key == 65362)
	{
		ft_printf("we go up\n");
		move_check(game, 'y', -1);
	}
	else if (key == 'a' || key == 65361)
	{
		ft_printf("slide to the left\n");
		move_check(game, 'x', -1);
	}
	else if (key == 's' || key == 65364)
	{
		ft_printf("we going down down\n");
		move_check(game, 'y', 1);
	}
	else if (key == 'd' || key == 65363)
	{
		ft_printf("slide to the right\n");
		move_check(game, 'x', 1);
	}
	ft_printf("%d(ps y) %d (ps x)\n", game->map->ps_cord.y,
		game->map->ps_cord.x);
	return (0);
}

void	move_check(t_game *game, int axis, int dir)
{
	if (axis == 'y' && game->map->map[game->map->ps_cord.y
		+ dir][game->map->ps_cord.x] != '1')
		game->map->ps_cord.y += dir;
	else if (axis == 'x'
		&& game->map->map[game->map->ps_cord.y][game->map->ps_cord.x
		+ dir] != '1')
		game->map->ps_cord.x += dir;
}
