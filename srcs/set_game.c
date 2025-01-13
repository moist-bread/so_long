/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 22:06:56 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/01/13 19:38:11 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	set_game(t_game **game, t_map *map)
{
	*game = malloc(sizeof(t_game));
	if (!(*game))
		return (1); // -make it game destroyer
	(*game)->mlx = mlx_init();
	if (!(*game)->mlx)
		return (1); // -make it game destroyer
	(*game)->offset = 0;
	if (map->heigth < 10 && map->width < 19)
		(*game)->win = mlx_new_window((*game)->mlx, (map->width + 2) * 90,
				(map->heigth + 2) * 90, "window dinamic");
	else
	{
		(*game)->win = mlx_new_window((*game)->mlx, 1920, 1080, "window big");
		(*game)->offset = 15;
	}
	if (!(*game)->win)
		return (1); // -make it game destroyer
	set_assets(*game, map);
	// get_data(*game);
	return (0);
}

void	get_data(t_game *game)
{
	(void)game;
}

void	set_assets(t_game *game, t_map *map)
{
	// DO A JOIN FOR PATHS WITH A FLAG
	// SO IT WORKS FOR BIG AND SMALL
	game->sprite = malloc(sizeof(t_sprt));
	if (!game->sprite)
		exit(1); // -make it free
	// make_sprite_data(game);
	if (map->heigth <= 10 && map->width <= 19)
	{
		game->spr_size = 90;
		set_sprites_bg(game, 15);
		// set_sprites_fg(game, 15);
	}
	else
	{
		game->spr_size = 45;
		set_sprites_bg(game, 15);
		// set_sprites_fg(game, 15);
	}
	if (!game->sprite->empty || !game->sprite->wall_v || !game->sprite->wall_h
		|| !game->sprite->colt || !game->sprite->exit_c || !game->sprite->exit_o
		|| !game->sprite->chara || !game->sprite->bord || !game->sprite->bord_v
		|| !game->sprite->bord_h || !game->sprite->bord_c)
		img_destroyer(game, map); // -make it game_destroyer
}

/* void	make_sprite_data(t_game *game)
{
	game->sprite->empty = malloc(sizeof(t_data));
	game->sprite->wall_v = malloc(sizeof(t_data));
	game->sprite->wall_h = malloc(sizeof(t_data));
	game->sprite->colt = malloc(sizeof(t_data));
	game->sprite->exit_c = malloc(sizeof(t_data));
	game->sprite->exit_o = malloc(sizeof(t_data));
	game->sprite->chara = malloc(sizeof(t_data));
	game->sprite->bord = malloc(sizeof(t_data));
	game->sprite->bord_v = malloc(sizeof(t_data));
	game->sprite->bord_h = malloc(sizeof(t_data));
	game->sprite->bord_c = malloc(sizeof(t_data));
	if (!game->sprite->empty || !game->sprite->wall_v
		|| !game->sprite->wall_h
		|| !game->sprite->colt || !game->sprite->exit_c || !game->sprite->exit_o
		|| !game->sprite->chara || !game->sprite->bord || !game->sprite->bord_v
		|| !game->sprite->bord_h || !game->sprite->bord_c) 
} 
*/

void	set_sprites_bg(t_game *game, int gap)
{
	game->sprite->empty = mlx_xpm_file_to_image(game->mlx, EMPTY,
			&game->spr_size, &game->spr_size);
	game->sprite->wall_v = mlx_xpm_file_to_image(game->mlx, WALLV,
			&game->spr_size, &game->spr_size);
	game->sprite->wall_h = mlx_xpm_file_to_image(game->mlx, WALLH,
			&game->spr_size, &game->spr_size);
	game->sprite->colt = mlx_xpm_file_to_image(game->mlx, COLT, &game->spr_size,
			&game->spr_size);
	game->sprite->exit_c = mlx_xpm_file_to_image(game->mlx, EXITC,
			&game->spr_size, &game->spr_size);
	game->sprite->exit_o = mlx_xpm_file_to_image(game->mlx, EXITO,
			&game->spr_size, &game->spr_size);
	game->sprite->chara = mlx_xpm_file_to_image(game->mlx, CHARA,
			&game->spr_size, &game->spr_size);
	game->sprite->bord = mlx_xpm_file_to_image(game->mlx, BORD, &game->spr_size,
			&game->spr_size);
	game->sprite->bord_v = mlx_xpm_file_to_image(game->mlx, BORDV, &gap,
			&game->spr_size);
	game->sprite->bord_h = mlx_xpm_file_to_image(game->mlx, BORDH,
			&game->spr_size, &gap);
	game->sprite->bord_c = mlx_xpm_file_to_image(game->mlx, BORDC, &gap, &gap);
}


void	img_destroyer(t_game *game, t_map *map)
{
	(void)map;
	ft_printf("img destroyer 3000\n");
	// make into img destroyer and do the window and game destroying here and exit with frees
	if (game->sprite->empty)
		mlx_destroy_image(game->mlx, game->sprite->empty);
	if (game->sprite->wall_v)
		mlx_destroy_image(game->mlx, game->sprite->wall_v);
	if (game->sprite->wall_h)
		mlx_destroy_image(game->mlx, game->sprite->wall_h);
	if (game->sprite->colt)
		mlx_destroy_image(game->mlx, game->sprite->colt);
	if (game->sprite->exit_c)
		mlx_destroy_image(game->mlx, game->sprite->exit_c);
	if (game->sprite->exit_o)
		mlx_destroy_image(game->mlx, game->sprite->exit_o);
	if (game->sprite->chara)
		mlx_destroy_image(game->mlx, game->sprite->chara);
	if (game->sprite->bord)
		mlx_destroy_image(game->mlx, game->sprite->bord);
	if (game->sprite->bord_v)
		mlx_destroy_image(game->mlx, game->sprite->bord_v);
	if (game->sprite->bord_h)
		mlx_destroy_image(game->mlx, game->sprite->bord_h);
	if (game->sprite->bord_c)
		mlx_destroy_image(game->mlx, game->sprite->bord_c);
	// end
}
