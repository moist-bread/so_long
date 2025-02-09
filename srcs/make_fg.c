/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_fg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:02:16 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/02/09 10:02:25 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	add_decor(t_game *game)
{
	sprite_to_bg(game, game->sprite->speaker, (t_cord){45, 45}, (t_cord){30
		+ game->gap, game->map->heigth * game->size - game->gap});
	sprite_to_bg_hflip(game, game->sprite->speaker, (t_cord){45, 45},
		(t_cord){(game->map->width + 1) * game->size + game->gap + 15
		+ game->offset, game->map->heigth * game->size - game->gap});
	if (game->map->heigth <= 10 && game->map->width <= 19)
		return ;
	if (game->map->width <= 34)
		sprite_to_bg(game, game->sprite->logo, (t_cord){180, 180}, (t_cord){37
			* game->size, 1 * game->size});
	if (game->map->width <= 34 || game->map->heigth <= 16)
		sprite_to_bg(game, game->sprite->button, (t_cord){180, 180}, (t_cord){37
			* game->size, 18 * game->size});
	if (game->map->heigth <= 16)
		sprite_to_bg(game, game->sprite->arrow, (t_cord){180, 180},
			(t_cord){game->size + game->gap + game->offset, 18 * game->size});
	// ideal: 16 x 34
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
		colorblock_to_bg(game, 0xADC7C7, (t_cord){game->size, game->size},
			(t_cord){((x + 1) * game->size) + game->gap + game->offset, (y + 1)
			* game->size});
	else if (type == 'O' || type == 'c' || type == 'E' || type == 'P')
		sprite_to_bg(game, game->sprite->empty_1, (t_cord){game->size,
			game->size}, (t_cord){((x + 1) * game->size) + game->gap
			+ game->offset, (y + 1) * game->size});
	else if (type == '1')
		wall_selector(game, y, x);
	if (type == 'c')
		sprite_to_bg(game, game->sprite->colt, (t_cord){game->size, game->size},
			(t_cord){((x + 1) * game->size) + game->gap + game->offset, (y + 1)
			* game->size});
	else if (type == 'E')
		sprite_to_bg(game, game->sprite->exit_c, (t_cord){game->size,
			game->size}, (t_cord){((x + 1) * game->size) + game->gap
			+ game->offset, (y + 1) * game->size});
	else if (type == 'e')
		sprite_to_bg(game, game->sprite->exit_o, (t_cord){game->size,
			game->size}, (t_cord){((x + 1) * game->size) + game->gap
			+ game->offset, (y + 1) * game->size});
}

void	wall_selector(t_game *game, int y, int x)
{
	if (!y || !x || y == game->map->heigth - 1 || x == game->map->width - 1)
		colorblock_to_bg(game, 0xFF0F0F0F, (t_cord){game->size, game->size},
			(t_cord){((x + 1) * game->size) + game->gap + game->offset, (y + 1)
			* game->size});
	else if (game->map->map[y][x - 1] != '1' && game->map->map[y][x + 1] != '1')
		sprite_to_bg(game, game->sprite->wall, (t_cord){game->size, game->size},
			(t_cord){((x + 1) * game->size) + game->gap + game->offset, (y + 1)
			* game->size});
	else if (game->map->map[y][x - 1] == '1' && game->map->map[y][x + 1] == '1')
		sprite_to_bg(game, game->sprite->wall_m, (t_cord){game->size,
			game->size}, (t_cord){((x + 1) * game->size) + game->gap
			+ game->offset, (y + 1) * game->size});
	else if (game->map->map[y][x - 1] != '1' && game->map->map[y][x + 1] == '1')
		sprite_to_bg(game, game->sprite->wall_c, (t_cord){game->size,
			game->size}, (t_cord){((x + 1) * game->size) + game->gap
			+ game->offset, (y + 1) * game->size});
	else if (game->map->map[y][x - 1] == '1' && game->map->map[y][x + 1] != '1')
		sprite_to_bg_hflip(game, game->sprite->wall_c, (t_cord){game->size,
			game->size}, (t_cord){((x + 1) * game->size) + game->gap
			+ game->offset, (y + 1) * game->size});
}
