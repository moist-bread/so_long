/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:12:21 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/01/14 17:11:06 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	make_sprite_data(t_game *game, t_map *map)
{
	ft_printf("mallocing sprite data\n");
	game->sprite->empty = malloc(sizeof(t_data));
	game->sprite->wall_v = malloc(sizeof(t_data));
	game->sprite->wall_h = malloc(sizeof(t_data));
	game->sprite->colt = malloc(sizeof(t_data));
	game->sprite->exit_c = malloc(sizeof(t_data));
	game->sprite->exit_o = malloc(sizeof(t_data));
	game->sprite->chara = malloc(sizeof(t_data));
	game->sprite->bord = malloc(sizeof(t_data));
	game->sprite->bord_v = malloc(sizeof(t_data));
	game->sprite->bord_h = malloc(sizeof(t_data));
	game->sprite->bord_c = malloc(sizeof(t_data));
	if (!game->sprite->empty || !game->sprite->wall_v || !game->sprite->wall_h
		|| !game->sprite->colt || !game->sprite->exit_c || !game->sprite->exit_o
		|| !game->sprite->chara || !game->sprite->bord || !game->sprite->bord_v
		|| !game->sprite->bord_h || !game->sprite->bord_c)
		img_destroyer(game, map); // -make it game_destroyer
}

void	get_sprite_data_bg(t_game *game)
{
	ft_printf("getting sprite data\n");
	game->sprite->empty->addr = mlx_get_data_addr(game->sprite->empty->img,
			&game->sprite->empty->bpp, &game->sprite->empty->len,
			&game->sprite->empty->endian);
	game->sprite->wall_v->addr = mlx_get_data_addr(game->sprite->wall_v->img,
			&game->sprite->wall_v->bpp, &game->sprite->wall_v->len,
			&game->sprite->wall_v->endian);
	game->sprite->wall_h->addr = mlx_get_data_addr(game->sprite->wall_h->img,
			&game->sprite->wall_h->bpp, &game->sprite->wall_h->len,
			&game->sprite->wall_h->endian);
	game->sprite->colt->addr = mlx_get_data_addr(game->sprite->colt->img,
			&game->sprite->colt->bpp, &game->sprite->colt->len,
			&game->sprite->colt->endian);
	game->sprite->exit_c->addr = mlx_get_data_addr(game->sprite->exit_c->img,
			&game->sprite->exit_c->bpp, &game->sprite->exit_c->len,
			&game->sprite->exit_c->endian);
	game->sprite->exit_o->addr = mlx_get_data_addr(game->sprite->exit_o->img,
			&game->sprite->exit_o->bpp, &game->sprite->exit_o->len,
			&game->sprite->exit_o->endian);
	game->sprite->chara->addr = mlx_get_data_addr(game->sprite->chara->img,
			&game->sprite->chara->bpp, &game->sprite->chara->len,
			&game->sprite->chara->endian);
	game->sprite->bord->addr = mlx_get_data_addr(game->sprite->bord->img,
			&game->sprite->bord->bpp, &game->sprite->bord->len,
			&game->sprite->bord->endian);
	game->sprite->bord_v->addr = mlx_get_data_addr(game->sprite->bord_v->img,
			&game->sprite->bord_v->bpp, &game->sprite->bord_v->len,
			&game->sprite->bord_v->endian);
	game->sprite->bord_h->addr = mlx_get_data_addr(game->sprite->bord_h->img,
			&game->sprite->bord_h->bpp, &game->sprite->bord_h->len,
			&game->sprite->bord_h->endian);
	game->sprite->bord_c->addr = mlx_get_data_addr(game->sprite->bord_c->img,
			&game->sprite->bord_c->bpp, &game->sprite->bord_c->len,
			&game->sprite->bord_c->endian);
}

void	get_sprite_data_fg(t_game *game)
{
	(void)game;
}
