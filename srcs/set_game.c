/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 22:06:56 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/02/03 12:48:01 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	set_game(t_game **game, t_map *map)
{
	*game = malloc(sizeof(t_game));
	if (!(*game))
		game_destroyer_3000(*game, map, 1);
	(*game)->collected = 0;
	(*game)->map = map;
	(*game)->mlx = mlx_init();
	if (!(*game)->mlx)
		game_destroyer_3000(*game, map, 2);
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
		game_destroyer_3000(*game, map, 3);
	set_assets(*game);
	set_imgs(*game);
	ft_printf("PRELIMINAR SETTINGS ARE DONE\n\n");
	return (0);
}

void	set_assets(t_game *game)
{
	game->chara_dir = 'R';
	game->sprite = malloc(sizeof(t_sprt));
	if (!game->sprite)
		game_destroyer_3000(game, game->map, 4);
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
	ft_printf("set sprites %d (success)\n", game->size);
	data_making_checker(game, 2);
	get_sprite_data_bg(game);
	get_sprite_data_fg(game);
	get_sprite_data_extra(game);
	ft_printf("get sprite data(success)\n");
}

void	set_imgs(t_game *game)
{
	ft_printf("mallocing back and fore ground data\n");
	game->bg = malloc(sizeof(t_data));
	if (!game->bg)
		game_destroyer_3000(game, game->map, 7);
	game->fg = malloc(sizeof(t_data));
	if (!game->fg)
		game_destroyer_3000(game, game->map, 8);
	if (game->map->heigth < 10 && game->map->width < 19)
	{
		game->bg->img = mlx_new_image(game->mlx, (game->map->width + 2) * 90,
				(game->map->heigth + 2) * 90);
		game->fg->img = mlx_new_image(game->mlx, (game->map->width + 2) * 90,
				(game->map->heigth + 2) * 90);
	}
	else
	{
		game->bg->img = mlx_new_image(game->mlx, 1920, 1080);
		game->fg->img = mlx_new_image(game->mlx, 1920, 1080);
	}
	if (!game->bg->img || !game->fg->img)
		game_destroyer_3000(game, game->map, 8);
	game->bg->addr = mlx_get_data_addr(game->bg->img, &game->bg->bpp,
			&game->bg->len, &game->bg->endian);
	game->fg->addr = mlx_get_data_addr(game->fg->img, &game->fg->bpp,
			&game->fg->len, &game->fg->endian);
}
