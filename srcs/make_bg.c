/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_bg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:31:05 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/01/24 13:45:28 by rduro-pe         ###   ########.fr       */
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
		sprite_to_bg_img_rotl(game, game->sprite->bord, (x * game->spr_size),
			0);
		sprite_to_bg_img_rotr(game, game->sprite->bord, (x * game->spr_size), (y
				- 1) * game->spr_size);
	}
	while (--y >= 0)
	{
		sprite_to_bg_img(game, game->sprite->bord, 0, y * game->spr_size);
		sprite_to_bg_img_hflip(game, game->sprite->bord, ((x - 1)
				* game->spr_size) + (2 * game->offset), y * game->spr_size);
	}
}

void	put_bevel(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	x = -1;
	while (++y < game->map->heigth)
	{
		gap_to_bg_img(game, game->sprite->bord_v, game->spr_size - 15
			+ game->offset, (y + 1) * game->spr_size);
		gap_to_bg_img_hflip(game, game->sprite->bord_v, (game->map->width + 1)
			* game->spr_size + game->offset, (y + 1) * game->spr_size);
	}
	while (++x < game->map->width)
	{
		gap_to_bg_img_h_vflip(game, game->sprite->bord_v, (x + 1)
			* game->spr_size + game->offset, game->spr_size - 15);
		gap_to_bg_img_h(game, game->sprite->bord_v, (x + 1) * game->spr_size
			+ game->offset, (y + 1) * game->spr_size);
	}
}

void	put_corner(t_game *game, int size)
{
	int	y;
	int	x;

	if (game->map->heigth > 10 || game->map->width > 19)
	{
		y = 23 * size;
		x = 42 * size - game->offset;
	}
	else
	{
		y = (game->map->heigth + 1) * size;
		x = (game->map->width + 1) * size + 2 * game->offset;
	}
	sprite_to_bg_img(game, game->sprite->bord_c, 0, 0);
	sprite_to_bg_img_vflip(game, game->sprite->bord_c, 0, y);
	sprite_to_bg_img_hflip(game, game->sprite->bord_c, x, 0);
	sprite_to_bg_img_mirr(game, game->sprite->bord_c, x, y);
	corn_to_bg_img(game, game->sprite->wall_v, size - 15 + game->offset, size
		- 15);
	corn_to_bg_img(game, game->sprite->wall_v, size - 15 + game->offset,
		(game->map->heigth + 1) * size);
	corn_to_bg_img(game, game->sprite->wall_v, (game->map->width + 1) * size
		+ game->offset, size - 15);
	corn_to_bg_img(game, game->sprite->wall_v, (game->map->width + 1) * size
		+ game->offset, (game->map->heigth + 1) * size);
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
			put_sprite(game, y, x, map->map[y][x]);
	}
}

void	put_sprite(t_game *game, int y, int x, int type)
{
	if (type == 'F')
		square_to_bg(game, 0xC7C7C7, ((x + 1) * game->spr_size) + game->offset,
			(y + 1) * game->spr_size);
	else if ((y == 0 || x == 0 || y == game->map->heigth - 1
			|| x == game->map->width - 1) && type == '1')
		square_to_bg(game, 0xFF0F0F0F, ((x + 1) * game->spr_size)
			+ game->offset, (y + 1) * game->spr_size);
	else if (type == 'O' || type == 'c' || type == 'E' || type == 'P')
		sprite_to_bg_img(game, game->sprite->empty, ((x + 1) * game->spr_size)
			+ game->offset, (y + 1) * game->spr_size);
	else if (type == '1')
		sprite_to_bg_img(game, game->sprite->wall_h, ((x + 1) * game->spr_size)
			+ game->offset, (y + 1) * game->spr_size);
	else if (type == 'B')
		sprite_to_bg_img(game, game->sprite->bord, ((x + 1) * game->spr_size)
			+ game->offset, (y + 1) * game->spr_size);
	if (type == 'c')
		sprite_to_bg_img(game, game->sprite->colt, ((x + 1) * game->spr_size)
			+ game->offset, (y + 1) * game->spr_size);
	else if (type == 'E')
		sprite_to_bg_img(game, game->sprite->exit_c, ((x + 1) * game->spr_size)
			+ game->offset, (y + 1) * game->spr_size);
}

void	fill_gap(t_game *game)
{
	int	y;
	int	x;

	if (game->map->heigth <= 10 && game->map->width <= 19)
		return ;
	y = -1;
	while (++y < 22)
	{
		rectangle_to_bg(game, 0xC7C7C7, (41 * game->spr_size) + game->offset, (y
				+ 1) * game->spr_size);
		x = game->map->width - 1;
		while (++x < 40)
			put_sprite(game, y, x, 'F');
	}
	while (--y >= game->map->heigth)
	{
		rectangle_to_bg(game, 0xC7C7C7, game->spr_size, (y + 1)
			* game->spr_size);
		x = -1;
		while (++x <= game->map->width)
			put_sprite(game, y, x, 'F');
	}
}
