/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_fg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:02:16 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/01/26 22:16:27 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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
		new_sprite_to_bg(game, game->sprite->empty_1, (t_cord){game->spr_size,
			game->spr_size}, (t_cord){((x + 1) * game->spr_size) + game->offset,
			(y + 1) * game->spr_size});
	else if (type == '1')
		wall_selector(game, y, x);
	if (type == 'c')
		new_sprite_to_bg(game, game->sprite->colt, (t_cord){game->spr_size,
			game->spr_size}, (t_cord){((x + 1) * game->spr_size) + game->offset,
			(y + 1) * game->spr_size});
	else if (type == 'E')
		new_sprite_to_bg(game, game->sprite->exit_c, (t_cord){game->spr_size,
			game->spr_size}, (t_cord){((x + 1) * game->spr_size) + game->offset,
			(y + 1) * game->spr_size});
	else if (type == 'e')
		new_sprite_to_bg(game, game->sprite->exit_o, (t_cord){game->spr_size,
			game->spr_size}, (t_cord){((x + 1) * game->spr_size) + game->offset,
			(y + 1) * game->spr_size});
}

void	wall_selector(t_game *game, int y, int x)
{
	if (game->map->map[y][x - 1] != '1' && game->map->map[y][x + 1] != '1')
		new_sprite_to_bg(game, game->sprite->wall, (t_cord){game->spr_size,
			game->spr_size}, (t_cord){((x + 1) * game->spr_size) + game->offset,
			(y + 1) * game->spr_size});
	if (game->map->map[y][x - 1] == '1' && game->map->map[y][x + 1] == '1')
		new_sprite_to_bg(game, game->sprite->wall_m, (t_cord){game->spr_size,
			game->spr_size}, (t_cord){((x + 1) * game->spr_size) + game->offset,
			(y + 1) * game->spr_size});
	if (game->map->map[y][x - 1] != '1' && game->map->map[y][x + 1] == '1')
		new_sprite_to_bg(game, game->sprite->wall_c, (t_cord){game->spr_size,
			game->spr_size}, (t_cord){((x + 1) * game->spr_size) + game->offset,
			(y + 1) * game->spr_size});
	if (game->map->map[y][x - 1] == '1' && game->map->map[y][x + 1] != '1')
		new_sprite_to_bg(game, game->sprite->wall_c, (t_cord){game->spr_size,
			game->spr_size}, (t_cord){((x + 1) * game->spr_size) + game->offset,
			(y + 1) * game->spr_size}); // horizontal flip
}
