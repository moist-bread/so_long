/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 22:06:56 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/02/10 15:36:21 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	set_game(t_game **game, t_map *map)
{
	*game = malloc(sizeof(t_game));
	if (!(*game))
		game_destroyer(*game, map, 1);
	(*game)->collected = 0;
	(*game)->map = map;
	(*game)->mlx = mlx_init();
	if (!(*game)->mlx)
		game_destroyer(*game, map, 2);
	if (map->heigth < 10 && map->width < 19)
	{
		(*game)->win = mlx_new_window((*game)->mlx, (map->width + 2) * 90,
				(map->heigth + 2) * 90, "window dinamic");
		(*game)->gap = 0;
	}
	else
	{
		(*game)->win = mlx_new_window((*game)->mlx, 1920, 1080, "window big");
		(*game)->gap = 15;
	}
	if (!(*game)->win)
		game_destroyer(*game, map, 3);
	set_assets(*game);
	set_imgs(*game);
	return (0);
}

void	set_assets(t_game *game)
{
	game->chara_dir = 'R';
	game->sprite = malloc(sizeof(t_sprt));
	if (!game->sprite)
		game_destroyer(game, game->map, 4);
	make_sprite_data(game);
	if (game->map->heigth <= 10 && game->map->width <= 19)
	{
		set_sprites_big(game, 15);
		game->offset = 0;
	}
	else
	{
		set_sprites_small(game, 15);
		game->offset = 45;
	}
	data_making_checker(game, 2);
	get_sprite_data_bg(game);
	get_sprite_data_fg(game);
	get_sprite_data_extra(game);
}

void	set_imgs(t_game *game)
{
	game->bg = malloc(sizeof(t_data));
	if (!game->bg)
		game_destroyer(game, game->map, 7);
	if (game->map->heigth < 10 && game->map->width < 19)
	{
		game->bg->img = mlx_new_image(game->mlx, (game->map->width + 2) * 90,
				(game->map->heigth + 2) * 90);
	}
	else
	{
		game->bg->img = mlx_new_image(game->mlx, 1920, 1080);
	}
	if (!game->bg->img)
		game_destroyer(game, game->map, 8);
	game->bg->addr = mlx_get_data_addr(game->bg->img, &game->bg->bpp,
			&game->bg->len, &game->bg->endian);
}
