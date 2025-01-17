/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 08:57:12 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/01/17 17:37:36 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	put_player(t_game *game) // change name to something else pls
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
		put_sprite(game, game->map->exit_cord.y, game->map->exit_cord.x, 'B');
		game->collected++;
	}
	if (game->collected > game->map->colt
		&& game->map->ps_cord.y == game->map->exit_cord.y
		&& game->map->ps_cord.x == game->map->exit_cord.x)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	// mlx_put_image_to_window(game->mlx, game->win, game->fg->img, 0, 0);
	// sprite_to_fg_img(game, game->sprite->bord, ((game->map->ps_cord.x + 1)
	// 		* game->spr_size) + game->offset, (game->map->ps_cord.y + 1)
	// 	* game->spr_size);
	mlx_put_image_to_window(game->mlx, game->win, game->bg->img, 0, 0);
	mlx_put_image_to_window(game->mlx, game->win, game->sprite->chara->img,
		((game->map->ps_cord.x + 1) * game->spr_size) + game->offset,
		(game->map->ps_cord.y + 1) * game->spr_size);
	return (0);
}

int	player_move(int key, t_game *game)
{
	ft_printf("%d (key)\n", key);
	if (key == 65307)
	{
		ft_printf("shut down\n");
		// mlx_destroy_window(game->mlx, game->win);
		// exit (0);
		game_destroyer(game, game->map);
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
