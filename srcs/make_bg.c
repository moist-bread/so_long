/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_bg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:31:05 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/01/26 23:50:18 by rduro-pe         ###   ########.fr       */
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
		sprite_to_bg_rotl(game, game->sprite->bord, (x * game->spr_size), 0);
		sprite_to_bg_rotr(game, game->sprite->bord, (x * game->spr_size), (y
				- 1) * game->spr_size);
	}
	while (--y >= 0)
	{
		new_sprite_to_bg(game, game->sprite->bord, (t_cord){game->spr_size,
			game->spr_size}, (t_cord){0, y * game->spr_size});
		new_sprite_to_bg_hflip(game, game->sprite->bord,
			(t_cord){game->spr_size, game->spr_size}, (t_cord){((x - 1)
				* game->spr_size) + 2 * game->offset, y * game->spr_size});
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
		new_sprite_to_bg(game, game->sprite->bevel, (t_cord){15,
			game->spr_size}, (t_cord){game->spr_size - 15 + game->offset, (y
				+ 1) * game->spr_size});
		new_sprite_to_bg_hflip(game, game->sprite->bevel, (t_cord){15,
			game->spr_size}, (t_cord){(game->map->width + 1) * game->spr_size
			+ game->offset, (y + 1) * game->spr_size});
	}
	while (++x < game->map->width)
	{
		gap_to_bg_h(game, game->sprite->bevel, (x + 1) * game->spr_size
			+ game->offset, (y + 1) * game->spr_size);
		gap_to_bg_h_vflip(game, game->sprite->bevel, (x + 1) * game->spr_size
			+ game->offset, game->spr_size - 15);
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
	new_sprite_to_bg(game, game->sprite->bord_c, (t_cord){game->spr_size,
		game->spr_size}, (t_cord){0, 0});
	new_sprite_to_bg_vflip(game, game->sprite->bord_c, (t_cord){game->spr_size,
		game->spr_size}, (t_cord){0, y});
	new_sprite_to_bg_hflip(game, game->sprite->bord_c, (t_cord){game->spr_size,
		game->spr_size}, (t_cord){x, 0});
	new_sprite_to_bg_mirr(game, game->sprite->bord_c, (t_cord){game->spr_size,
		game->spr_size}, (t_cord){x, y});
	new_sprite_to_bg(game, game->sprite->bevel_c, (t_cord){15, 15},
		(t_cord){size - 15 + game->offset, size - 15});
	new_sprite_to_bg_vflip(game, game->sprite->bevel_c, (t_cord){15, 15},
		(t_cord){size - 15 + game->offset, (game->map->heigth + 1) * size});
	new_sprite_to_bg_hflip(game, game->sprite->bevel_c, (t_cord){15, 15},
		(t_cord){(game->map->width + 1) * size + game->offset, size - 15});
	new_sprite_to_bg_mirr(game, game->sprite->bevel_c, (t_cord){15, 15},
		(t_cord){(game->map->width + 1) * size + game->offset,
		(game->map->heigth + 1) * size});
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

void	add_decor(t_game *game)
{
	if (game->map->heigth <= 10 && game->map->width <= 19)
		return ;
	if (game->map->width <= 36)
	{
		square_to_bg(game, 0xFF0F0F0F, (38 * game->spr_size) + game->offset, 1
			* game->spr_size);
		square_to_bg(game, 0xFF0F0F0F, (38 * game->spr_size) + game->offset, 18
			* game->spr_size);
	}
	if (game->map->heigth <= 15)
	{
		square_to_bg(game, 0xFF0F0F0F, game->spr_size + game->offset, 18
			* game->spr_size);
	}
	// 15 x 36
}
