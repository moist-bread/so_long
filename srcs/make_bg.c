/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_bg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:31:05 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/02/03 13:52:14 by rduro-pe         ###   ########.fr       */
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
	while ((!game->gap && ++x < map->width + 2) || (game->gap
			&& ((game->size == 90 && ++x < 21) || (game->size == 45
					&& ++x < 42))))
	{
		new_sprite_to_bg_rotl(game, game->sprite->bord, (t_cord){90, game->size}, (t_cord){x * game->size, 0});
		new_sprite_to_bg_rotr(game, game->sprite->bord, (t_cord){90,
			game->size}, (t_cord){(x * game->size), (y - 1) * game->size});
	}
	while (--y >= 0)
	{
		new_sprite_to_bg(game, game->sprite->bord, (t_cord){90,
			game->size}, (t_cord){0, y * game->size});
		new_sprite_to_bg_hflip(game, game->sprite->bord, (t_cord){game->size,
			game->size}, (t_cord){((x - 1) * game->size) + 2 * game->gap, y
			* game->size});
	}
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
		colorblock_to_bg(game, 0xC7C7C7, (t_cord){15, game->size}, (t_cord){(41
				* game->size) + game->gap, (y + 1) * game->size});
		x = game->map->width - 1;
		while (++x < 40)
			put_sprite(game, y, x, 'F');
	}
	while (--y >= game->map->heigth)
	{
		colorblock_to_bg(game, 0xC7C7C7, (t_cord){15, game->size},
			(t_cord){game->size + game->offset, (y + 1) * game->size});
		x = -1;
		while (++x <= game->map->width)
			put_sprite(game, y, x, 'F');
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
		new_sprite_to_bg(game, game->sprite->bevel, (t_cord){15, game->size},
			(t_cord){game->size - 15 + game->gap + game->offset, (y + 1) * game->size});
		new_sprite_to_bg_hflip(game, game->sprite->bevel, (t_cord){15,
			game->size}, (t_cord){(game->map->width + 1) * game->size
			+ game->gap + game->offset, (y + 1) * game->size});
	}
	while (++x < game->map->width)
	{
		new_sprite_to_bg_rotr(game, game->sprite->bevel, (t_cord){game->size,
			15}, (t_cord){(x + 1) * game->size + game->gap + game->offset, (y + 1)
			* game->size});
		new_sprite_to_bg_rotl(game, game->sprite->bevel, (t_cord){game->size,
			15}, (t_cord){(x + 1) * game->size + game->gap + game->offset, game->size
			- 15});
	}
}

void	put_corner(t_game *game, int size)
{
	int	y;
	int	x;

	assign_xy(game, &x, &y, 2);
	new_sprite_to_bg(game, game->sprite->bord_c, (t_cord){90, size},
		(t_cord){0, 0});
	new_sprite_to_bg_vflip(game, game->sprite->bord_c, (t_cord){size, size},
		(t_cord){0, y});
	new_sprite_to_bg_hflip(game, game->sprite->bord_c, (t_cord){size, size},
		(t_cord){x, 0});
	new_sprite_to_bg_mirr(game, game->sprite->bord_c, (t_cord){size, size},
		(t_cord){x, y});
	new_sprite_to_bg(game, game->sprite->bevel_c, (t_cord){15, 15},
		(t_cord){size - 15 + game->gap + game->offset, size - 15});
	new_sprite_to_bg_vflip(game, game->sprite->bevel_c, (t_cord){15, 15},
		(t_cord){size - 15 + game->gap + game->offset, (game->map->heigth + 1) * size});
	new_sprite_to_bg_hflip(game, game->sprite->bevel_c, (t_cord){15, 15},
		(t_cord){(game->map->width + 1) * size + game->gap + game->offset, size - 15});
	new_sprite_to_bg_mirr(game, game->sprite->bevel_c, (t_cord){15, 15},
		(t_cord){(game->map->width + 1) * size + game->gap + game->offset,
		(game->map->heigth + 1) * size});
}

void	assign_xy(t_game *game, int *x, int *y, int zone)
{
	if (zone == 1)
	{
		if (game->map->heigth > 10 || game->map->width > 19)
			*y = 24;
		else
			*y = game->map->heigth + 2;
		*x = 0;
	}
	else if (zone == 2)
	{
		if (game->map->heigth > 10 || game->map->width > 19)
		{
			*y = 23 * game->size;
			*x = 42 * game->size - game->gap;
		}
		else
		{
			*y = (game->map->heigth + 1) * game->size;
			*x = (game->map->width + 1) * game->size + 2 * game->gap;
		}
	}
}
