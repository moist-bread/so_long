/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 22:06:56 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/01/10 22:07:19 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	set_game(t_game **game, t_map *map)
{
	*game = malloc(sizeof(t_game));
	if (!(*game))
		return (1); // -make it game destroyer
	set_assets(*game, map);
	(*game)->mlx = mlx_init();
	if (!(*game)->mlx)
		return (1); // -make it game destroyer
	if (map->heigth < 10 && map->width < 19)
		(*game)->win = mlx_new_window((*game)->mlx, (map->width + 2) * 90,
				(map->heigth + 2) * 90, "window");
	else
		(*game)->win = mlx_new_window((*game)->mlx, 1920, 1080, "window");
	if (!(*game)->win)
		return (1); // -make it game destroyer
	return(0);
}

void	set_assets(t_game *game, t_map *map)
{
	int	sqr;
	int	gap;

	sqr = 90;
	gap = 15;
	game->sprite = malloc(sizeof(t_sprt));
	if (!game->sprite)
		exit(1); // -make it free
	game->sprite->empty = mlx_xpm_file_to_image(game->mlx, EMPTY, &sqr, &sqr);
	game->sprite->wall_v = mlx_xpm_file_to_image(game->mlx, WALLV, &sqr, &sqr);
	game->sprite->wall_h = mlx_xpm_file_to_image(game->mlx, WALLH, &sqr, &sqr);
	game->sprite->colt = mlx_xpm_file_to_image(game->mlx, COLT, &sqr, &sqr);
	game->sprite->exit_c = mlx_xpm_file_to_image(game->mlx, EXITC, &sqr, &sqr);
	game->sprite->exit_o = mlx_xpm_file_to_image(game->mlx, EXITO, &sqr, &sqr);
	game->sprite->chara = mlx_xpm_file_to_image(game->mlx, CHARA, &sqr, &sqr);
	game->sprite->bord = mlx_xpm_file_to_image(game->mlx, BORD, &sqr, &sqr);
	game->sprite->bord_v = mlx_xpm_file_to_image(game->mlx, BORDV, &gap, &sqr);
	game->sprite->bord_h = mlx_xpm_file_to_image(game->mlx, BORDH, &sqr, &gap);
	game->sprite->bord_c = mlx_xpm_file_to_image(game->mlx, BORDC, &gap, &gap);
	if (!game->sprite->empty || !game->sprite->wall_v || !game->sprite->wall_h
		|| !game->sprite->colt || !game->sprite->exit_c || !game->sprite->exit_o
		|| !game->sprite->chara || !game->sprite->bord || !game->sprite->bord_v
		|| !game->sprite->bord_h || !game->sprite->bord_c)
		img_destroyer(game, map);
}

void	img_destroyer(t_game *game, t_map *map)
{
	(void)map;
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
