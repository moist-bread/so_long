/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_bg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:31:05 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/01/17 12:05:38 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	put_border(t_game *game, t_map *map)
{
	int	y;
	int	x;

	if (map->heigth > 10 || map->width > 19)
		y = 24;
	else
		y = map->heigth + 2;
	x = 0;
	while ((!game->offset && ++x < map->width + 2) || (game->offset
			&& ((game->spr_size == 90 && ++x < 21) || (game->spr_size == 45
					&& ++x < 42))))
	{
		sprite_to_bg_img_rotl(game, game->sprite->bord, (x * game->spr_size)
			+ game->offset, 0);
		sprite_to_bg_img_rotr(game, game->sprite->bord, (x * game->spr_size)
			+ game->offset, (y - 1) * game->spr_size);
	}
	while (--y >= 0)
	{
		sprite_to_bg_img(game, game->sprite->bord, game->offset, y
			* game->spr_size);
		sprite_to_bg_img_hflip(game, game->sprite->bord, ((x - 1)
				* game->spr_size) + game->offset, y * game->spr_size);
		if (game->offset)
		{
			gap_to_bg_img(game, game->sprite->bord_v, 0, y * game->spr_size);
			gap_to_bg_img(game, game->sprite->bord_v, (x * game->spr_size)
				+ game->offset, y * game->spr_size);
		}
	}
}

void	put_in_border(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	x = -1;
	while (++y < game->map->heigth)
	{
		gap_to_bg_img(game, game->sprite->bord_v, 1 * game->spr_size, (y + 1)
		* game->spr_size);
		// gap_to_bg_img(game, game->sprite->bord_h, game->map->width * game->spr_size, (y + 1)
		// * game->spr_size);
	}
	while (++x < game->map->width)
	{
		gap_to_bg_img_h(game, game->sprite->bord_h, 500, 500);
	}
	/* while ((!game->offset && ++x < game->map->width + 2) || (game->offset
			&& ((game->spr_size == 90 && ++x < 21) || (game->spr_size == 45
					&& ++x < 42))))
	{
		sprite_to_bg_img_rotl(game, game->sprite->bord, (x * game->spr_size)
			+ game->offset, 0);
		sprite_to_bg_img_rotr(game, game->sprite->bord, (x * game->spr_size)
			+ game->offset, (y - 1) * game->spr_size);
	}
	while (--y >= 0)
	{
		sprite_to_bg_img(game, game->sprite->bord, game->offset, y
			* game->spr_size);
		sprite_to_bg_img_hflip(game, game->sprite->bord, ((x - 1)
				* game->spr_size) + game->offset, y * game->spr_size);
		if (game->offset)
		{
			gap_to_bg_img(game, game->sprite->bord_v, 0, y * game->spr_size);
			gap_to_bg_img(game, game->sprite->bord_v, (x * game->spr_size)
				+ game->offset, y * game->spr_size);
		}
	} */
	(void)game;
}

void	put_corner(t_game *game)
{
	int	y;
	int	x;

	if (game->map->heigth > 10 || game->map->width > 19)
	{
		y = 23 * game->spr_size;
		x = 42 * game->spr_size - game->offset;
	}
	else
	{
		y = (game->map->heigth + 1) * game->spr_size;
		x = (game->map->width + 1) * game->spr_size + 2 * game->offset;
	}
	sprite_to_bg_img(game, game->sprite->empty, 0, 0);
	sprite_to_bg_img_rotl(game, game->sprite->empty, 0, y);
	sprite_to_bg_img_hflip(game, game->sprite->empty, x, 0);
	sprite_to_bg_img_rotr(game, game->sprite->empty, x, y);
}

void	put_map(t_game *game, t_map *map)
{
	int	y;
	int	x;

	y = -1;
	while (map->map[++y])
	{
		x = -1;
		while (map->map[y][++x])
		{
			put_sprite(game, y, x, map->map[y][x]);
			put_fg(game, y, x, map->map[y][x]);
		}
	}
}

void	put_sprite(t_game *game, int y, int x, int type)
{
	if (type == 'O' || type == 'c' || type == 'E' || type == 'P')
		sprite_to_bg_img(game, game->sprite->empty, ((x + 1) * game->spr_size)
			+ game->offset, (y + 1) * game->spr_size);
	else if (type == '1')
		sprite_to_bg_img(game, game->sprite->wall_h, ((x + 1) * game->spr_size)
			+ game->offset, (y + 1) * game->spr_size);
	else if (type == 'B')
		sprite_to_bg_img(game, game->sprite->bord, ((x + 1) * game->spr_size)
			+ game->offset, (y + 1) * game->spr_size);
	/* else if (type == 'c')
		sprite_to_bg_img(game, game->sprite->colt, ((x + 1) * game->spr_size)
			+ game->offset, (y + 1) * game->spr_size);
	else if (type == 'E')
		sprite_to_bg_img(game, game->sprite->exit_c, ((x + 1) * game->spr_size)
			+ game->offset, (y + 1) * game->spr_size);
	else if (type == 'P')
		sprite_to_bg_img(game, game->sprite->chara, ((x + 1) * game->spr_size)
			+ game->offset, (y + 1) * game->spr_size); */
}

void	put_fg(t_game *game, int y, int x, int type)
{
	// CHANGE BACK TO FG WHEN IT HAS TRANSPARENCY
	if (type == 'c')
		sprite_to_bg_img(game, game->sprite->colt, ((x + 1) * game->spr_size)
			+ game->offset, (y + 1) * game->spr_size);
	if (type == 'E')
		sprite_to_bg_img(game, game->sprite->exit_c, ((x + 1) * game->spr_size)
			+ game->offset, (y + 1) * game->spr_size);
	/* if (type == 'P')
		sprite_to_bg_img(game, game->sprite->chara, ((x + 1) * game->spr_size)
			+ game->offset, (y + 1) * game->spr_size); */
}
