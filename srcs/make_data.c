/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:12:21 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/01/27 14:17:52 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	make_sprite_data(t_game *game)
{
	ft_printf("mallocing sprite data\n");
	game->sprite->bord = malloc(sizeof(t_data));
	game->sprite->bord_c = malloc(sizeof(t_data));
	game->sprite->bevel = malloc(sizeof(t_data));
	game->sprite->bevel_c = malloc(sizeof(t_data));
	game->sprite->speaker = malloc(sizeof(t_data));
	game->sprite->logo = malloc(sizeof(t_data));
	game->sprite->button = malloc(sizeof(t_data));
	game->sprite->arrow = malloc(sizeof(t_data));
	game->sprite->empty_1 = malloc(sizeof(t_data));
	game->sprite->empty_2 = malloc(sizeof(t_data));
	game->sprite->wall = malloc(sizeof(t_data));
	game->sprite->wall_m = malloc(sizeof(t_data));
	game->sprite->wall_c = malloc(sizeof(t_data));
	game->sprite->exit_c = malloc(sizeof(t_data));
	game->sprite->exit_o = malloc(sizeof(t_data));
	game->sprite->colt = malloc(sizeof(t_data));
	game->sprite->chara_1 = malloc(sizeof(t_data));
	game->sprite->chara_2 = malloc(sizeof(t_data));
	data_making_checker(game, 1);
}

// type 1: malloc
// type 2: image making
void	data_making_checker(t_game *game, int type)
{
	if (type == 1)
		if (!game->sprite->bord || !game->sprite->bord_c || !game->sprite->bevel
			|| !game->sprite->bevel_c || !game->sprite->speaker
			|| !game->sprite->logo || !game->sprite->button
			|| !game->sprite->arrow || !game->sprite->empty_1
			|| !game->sprite->empty_2 || !game->sprite->wall
			|| !game->sprite->wall_m || !game->sprite->wall_c
			|| !game->sprite->exit_c || !game->sprite->exit_o
			|| !game->sprite->colt || !game->sprite->chara_1
			|| !game->sprite->chara_2)
			game_destroyer_3000(game, game->map, 5);
	if (type == 2)
		if (!game->sprite->bord->img || !game->sprite->bord_c->img
			|| !game->sprite->bevel->img || !game->sprite->bevel_c->img
			|| !game->sprite->speaker->img || !game->sprite->logo->img
			|| !game->sprite->button->img || !game->sprite->arrow->img
			|| !game->sprite->empty_1->img || !game->sprite->empty_2->img
			|| !game->sprite->wall->img || !game->sprite->wall_m->img
			|| !game->sprite->wall_c->img || !game->sprite->exit_c->img
			|| !game->sprite->exit_o->img || !game->sprite->colt->img
			|| !game->sprite->chara_1->img || !game->sprite->chara_2->img)
		game_destroyer_3000(game, game->map, 6);
}

void	get_sprite_data_bg(t_game *game)
{
	ft_printf("getting bg sprite data\n");
	game->sprite->bord->addr = mlx_get_data_addr(game->sprite->bord->img,
			&game->sprite->bord->bpp, &game->sprite->bord->len,
			&game->sprite->bord->endian);
	game->sprite->bord_c->addr = mlx_get_data_addr(game->sprite->bord_c->img,
			&game->sprite->bord_c->bpp, &game->sprite->bord_c->len,
			&game->sprite->bord_c->endian);
	game->sprite->bevel->addr = mlx_get_data_addr(game->sprite->bevel->img,
			&game->sprite->bevel->bpp, &game->sprite->bevel->len,
			&game->sprite->bevel->endian);
	game->sprite->bevel_c->addr = mlx_get_data_addr(game->sprite->bevel_c->img,
			&game->sprite->bevel_c->bpp, &game->sprite->bevel_c->len,
			&game->sprite->bevel_c->endian);
	game->sprite->speaker->addr = mlx_get_data_addr(game->sprite->speaker->img,
			&game->sprite->speaker->bpp, &game->sprite->speaker->len,
			&game->sprite->speaker->endian);
	game->sprite->logo->addr = mlx_get_data_addr(game->sprite->logo->img,
			&game->sprite->logo->bpp, &game->sprite->logo->len,
			&game->sprite->logo->endian);
	game->sprite->button->addr = mlx_get_data_addr(game->sprite->button->img,
			&game->sprite->button->bpp, &game->sprite->button->len,
			&game->sprite->button->endian);
	game->sprite->arrow->addr = mlx_get_data_addr(game->sprite->arrow->img,
			&game->sprite->arrow->bpp, &game->sprite->arrow->len,
			&game->sprite->arrow->endian);
}

void	get_sprite_data_fg(t_game *game)
{
	ft_printf("getting fg sprite data\n");
	game->sprite->empty_1->addr = mlx_get_data_addr(game->sprite->empty_1->img,
			&game->sprite->empty_1->bpp, &game->sprite->empty_1->len,
			&game->sprite->empty_1->endian);
	game->sprite->empty_2->addr = mlx_get_data_addr(game->sprite->empty_2->img,
			&game->sprite->empty_2->bpp, &game->sprite->empty_2->len,
			&game->sprite->empty_2->endian);
	game->sprite->wall->addr = mlx_get_data_addr(game->sprite->wall->img,
			&game->sprite->wall->bpp, &game->sprite->wall->len,
			&game->sprite->wall->endian);
	game->sprite->wall_m->addr = mlx_get_data_addr(game->sprite->wall_m->img,
			&game->sprite->wall_m->bpp, &game->sprite->wall_m->len,
			&game->sprite->wall_m->endian);
	game->sprite->wall_c->addr = mlx_get_data_addr(game->sprite->wall_c->img,
			&game->sprite->wall_c->bpp, &game->sprite->wall_c->len,
			&game->sprite->wall_c->endian);
	game->sprite->exit_c->addr = mlx_get_data_addr(game->sprite->exit_c->img,
			&game->sprite->exit_c->bpp, &game->sprite->exit_c->len,
			&game->sprite->exit_c->endian);
	game->sprite->exit_o->addr = mlx_get_data_addr(game->sprite->exit_o->img,
			&game->sprite->exit_o->bpp, &game->sprite->exit_o->len,
			&game->sprite->exit_o->endian);
	game->sprite->colt->addr = mlx_get_data_addr(game->sprite->colt->img,
			&game->sprite->colt->bpp, &game->sprite->colt->len,
			&game->sprite->colt->endian);
}

void	get_sprite_data_extra(t_game *game)
{
	ft_printf("getting extra sprite data\n");
	game->sprite->chara_1->addr = mlx_get_data_addr(game->sprite->chara_1->img,
			&game->sprite->chara_1->bpp, &game->sprite->chara_1->len,
			&game->sprite->chara_1->endian);
	game->sprite->chara_2->addr = mlx_get_data_addr(game->sprite->chara_2->img,
			&game->sprite->chara_2->bpp, &game->sprite->chara_2->len,
			&game->sprite->chara_2->endian);
}
