/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 08:57:12 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/02/03 14:16:16 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	render_game(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	if (game->map->map[game->map->ps_cord.y][game->map->ps_cord.x] == 'c')
	{
		game->collected++;
		put_sprite(game, game->map->ps_cord.y, game->map->ps_cord.x, 'O');
		game->map->map[game->map->ps_cord.y][game->map->ps_cord.x] = 'C';
	}
	if (game->collected == game->map->colt)
	{
		put_sprite(game, game->map->exit_cord.y, game->map->exit_cord.x, 'e');
		game->collected++;
	}
	if (game->collected > game->map->colt
		&& game->map->ps_cord.y == game->map->exit_cord.y
		&& game->map->ps_cord.x == game->map->exit_cord.x)
	{
		game_destroyer_3000(game, game->map, 10);
	}
	mlx_put_image_to_window(game->mlx, game->win, game->bg->img, 0, 0);
	player_sprite_selector(game);
	return (0);
}

void	player_sprite_selector(t_game *game)
{
	if (game->chara_dir == 'R')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->sprite->chara_1->img, ((game->map->ps_cord.x + 1)
				* game->size) + game->gap + game->offset, (game->map->ps_cord.y
				+ 1) * game->size);
	}
	else if (game->chara_dir == 'L')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->sprite->chara_2->img, ((game->map->ps_cord.x + 1)
				* game->size) + game->gap + game->offset, (game->map->ps_cord.y
				+ 1) * game->size);
	}
}

int	player_move(int key, t_game *game)
{
	ft_printf("%d (key)\n", key);
	if (key == 65307)
		game_destroyer_3000(game, game->map, 10);
	else if (key == 'w' || key == 65362)
		move_check(game, 'y', -1, 'U');
	else if (key == 'a' || key == 65361)
		move_check(game, 'x', -1, 'L');
	else if (key == 's' || key == 65364)
		move_check(game, 'y', 1, 'D');
	else if (key == 'd' || key == 65363)
		move_check(game, 'x', 1, 'R');
	ft_printf("%d(ps y) %d (ps x)\n", game->map->ps_cord.y,
		game->map->ps_cord.x);
	return (0);
}

void	move_check(t_game *game, int axis, int dir, int key)
{
	if (key == 'L' || key == 'R')
		game->chara_dir = key;
	if (axis == 'y' && game->map->map[game->map->ps_cord.y
		+ dir][game->map->ps_cord.x] != '1')
	{
		game->map->ps_cord.y += dir;
	}
	else if (axis == 'x'
		&& game->map->map[game->map->ps_cord.y][game->map->ps_cord.x
		+ dir] != '1')
	{
		game->map->ps_cord.x += dir;
	}
}

int	close_x(t_game *game)
{
	game_destroyer_3000(game, game->map, 10);
	return (0);
}
