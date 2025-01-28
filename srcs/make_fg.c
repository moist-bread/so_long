/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_fg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:02:16 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/01/28 14:15:22 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	add_decor(t_game *game)
{
	new_sprite_to_bg(game, game->sprite->speaker, (t_cord){45, 45},
		(t_cord){game->size - 15 + game->offset - 45, game->map->heigth
		* game->size - game->offset});
	new_sprite_to_bg_hflip(game, game->sprite->speaker, (t_cord){45, 45},
		(t_cord){(game->map->width + 1) * game->size + game->offset + 15,
		game->map->heigth * game->size - game->offset});
	if (game->map->heigth <= 10 && game->map->width <= 19)
		return ;
	if (game->map->width <= 35)
		new_sprite_to_bg(game, game->sprite->logo, (t_cord){180, 180},
			(t_cord){(37 * game->size) + game->offset, 1 * game->size});
	if (game->map->width <= 35 || game->map->heigth <= 16)
		new_sprite_to_bg(game, game->sprite->logo, (t_cord){180, 180},
			(t_cord){(37 * game->size) + game->offset, 18 * game->size});
	if (game->map->heigth <= 16)
		new_sprite_to_bg(game, game->sprite->logo, (t_cord){180, 180},
			(t_cord){game->size + game->offset, 18 * game->size});
	// ideal: 16 x 35
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
		colorblock_to_bg(game, 0xC7C7C7, (t_cord){game->size, game->size},
			(t_cord){((x + 1) * game->size) + game->offset, (y + 1)
			* game->size});
	else if (type == 'O' || type == 'c' || type == 'E' || type == 'P')
		new_sprite_to_bg(game, game->sprite->empty_1, (t_cord){game->size,
			game->size}, (t_cord){((x + 1) * game->size) + game->offset, (y + 1)
			* game->size});
	else if (type == '1')
		wall_selector(game, y, x);
	if (type == 'c')
		new_sprite_to_bg(game, game->sprite->colt, (t_cord){game->size,
			game->size}, (t_cord){((x + 1) * game->size) + game->offset, (y + 1)
			* game->size});
	else if (type == 'E')
		new_sprite_to_bg(game, game->sprite->exit_c, (t_cord){game->size,
			game->size}, (t_cord){((x + 1) * game->size) + game->offset, (y + 1)
			* game->size});
	else if (type == 'e')
		new_sprite_to_bg(game, game->sprite->exit_o, (t_cord){game->size,
			game->size}, (t_cord){((x + 1) * game->size) + game->offset, (y + 1)
			* game->size});
}

void	wall_selector(t_game *game, int y, int x)
{
	if (!y || !x || y == game->map->heigth - 1 || x == game->map->width - 1)
		colorblock_to_bg(game, 0xFF0F0F0F, (t_cord){game->size, game->size},
			(t_cord){((x + 1) * game->size) + game->offset, (y + 1)
			* game->size});
	else if (game->map->map[y][x - 1] != '1' && game->map->map[y][x + 1] != '1')
		new_sprite_to_bg(game, game->sprite->wall, (t_cord){game->size,
			game->size}, (t_cord){((x + 1) * game->size) + game->offset, (y + 1)
			* game->size});
	else if (game->map->map[y][x - 1] == '1' && game->map->map[y][x + 1] == '1')
		new_sprite_to_bg(game, game->sprite->wall_m, (t_cord){game->size,
			game->size}, (t_cord){((x + 1) * game->size) + game->offset, (y + 1)
			* game->size});
	else if (game->map->map[y][x - 1] != '1' && game->map->map[y][x + 1] == '1')
		new_sprite_to_bg(game, game->sprite->wall_c, (t_cord){game->size,
			game->size}, (t_cord){((x + 1) * game->size) + game->offset, (y + 1)
			* game->size});
	else if (game->map->map[y][x - 1] == '1' && game->map->map[y][x + 1] != '1')
		new_sprite_to_bg_hflip(game, game->sprite->wall_c, (t_cord){game->size,
			game->size}, (t_cord){((x + 1) * game->size) + game->offset, (y + 1)
			* game->size});
}
