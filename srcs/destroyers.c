/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroyers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:55:59 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/01/23 15:56:12 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// 1 game didnt malloc
// 2 mlx didnt create
// 3 win didnt create
// 4 game sprite didnt malloc
// 5 sprites didnt malloc
// 6 sprite imgs didnt create
// 7 game bg didnt malloc
// 8 game fg didnt malloc
// 9 bg fg img didnt create
// 10 end of program

void	game_destroyer_3000(t_game *game, t_map *map, int status)
{
	free_map(map, map->heigth);
	if (status >= 9)
	{
		if (game->bg->img)
			mlx_destroy_image(game->mlx, game->bg->img);
		if (game->fg->img)
			mlx_destroy_image(game->mlx, game->fg->img);
	}
	if (status >= 8)
		free(game->fg);
	if (status >= 7)
		free(game->bg);
	if (status >= 6)
		img_destroyer(game);
	if (status >= 5)
		sprite_destroyer(game);
	if (status >= 4)
		mlx_destroy_window(game->mlx, game->win);
	if (status >= 3)
		mlx_destroy_display(game->mlx);
	if (status >= 2)
		free(game);
	if (status >= 1)
		exit(status);
}

void	img_destroyer(t_game *game)
{
	ft_printf("img destroyer 3000\n");
	if (game->sprite->empty->img)
		mlx_destroy_image(game->mlx, game->sprite->empty->img);
	if (game->sprite->wall_v->img)
		mlx_destroy_image(game->mlx, game->sprite->wall_v->img);
	if (game->sprite->wall_h->img)
		mlx_destroy_image(game->mlx, game->sprite->wall_h->img);
	if (game->sprite->colt->img)
		mlx_destroy_image(game->mlx, game->sprite->colt->img);
	if (game->sprite->exit_c->img)
		mlx_destroy_image(game->mlx, game->sprite->exit_c->img);
	if (game->sprite->exit_o->img)
		mlx_destroy_image(game->mlx, game->sprite->exit_o->img);
	if (game->sprite->chara->img)
		mlx_destroy_image(game->mlx, game->sprite->chara->img);
	if (game->sprite->bord->img)
		mlx_destroy_image(game->mlx, game->sprite->bord->img);
	if (game->sprite->bord_v->img)
		mlx_destroy_image(game->mlx, game->sprite->bord_v->img);
	if (game->sprite->bord_h->img)
		mlx_destroy_image(game->mlx, game->sprite->bord_h->img);
	if (game->sprite->bord_c->img)
		mlx_destroy_image(game->mlx, game->sprite->bord_c->img);
}

void	sprite_destroyer(t_game *game)
{
	ft_printf("sprite destroyer 3000\n");
	if (game->sprite->empty)
		free(game->sprite->empty);
	if (game->sprite->wall_v)
		free(game->sprite->wall_v);
	if (game->sprite->wall_h)
		free(game->sprite->wall_h);
	if (game->sprite->colt)
		free(game->sprite->colt);
	if (game->sprite->exit_c)
		free(game->sprite->exit_c);
	if (game->sprite->exit_o)
		free(game->sprite->exit_o);
	if (game->sprite->chara)
		free(game->sprite->chara);
	if (game->sprite->bord)
		free(game->sprite->bord);
	if (game->sprite->bord_v)
		free(game->sprite->bord_v);
	if (game->sprite->bord_h)
		free(game->sprite->bord_h);
	if (game->sprite->bord_c)
		free(game->sprite->bord_c);
	free(game->sprite);
}
