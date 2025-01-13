/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 22:06:56 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/01/13 23:30:52 by rduro-pe         ###   ########.fr       */
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
	if (map->heigth < 10 && map->width < 19)
	{
		(*game)->win = mlx_new_window((*game)->mlx, (map->width + 2) * 90,
				(map->heigth + 2) * 90, "window dinamic");
		(*game)->offset = 0;
	}
	else
	{
		(*game)->win = mlx_new_window((*game)->mlx, 1920, 1080, "window big");
		(*game)->offset = 15;
	}
	if (!(*game)->win)
		return (1); // -make it game destroyer
	set_assets(*game, map);
	return (0);
}

void	set_imgs(t_game *game, t_map *map)
{
	if (map->heigth < 10 && map->width < 19)
	{
		game->bg_img = mlx_new_image(game->mlx, (map->width + 2) * 90,
				(map->heigth + 2) * 90);
	}
	else
	{
		game->bg_img = mlx_new_image(game->mlx, 1920, 1080);
	}
}

void	get_sprite_data_bg(t_game *game)
{
	game->data->empty->addr = mlx_get_data_addr(game->sprite->empty,
			game->data->empty->bpp, game->data->empty->len,
			game->data->empty->endian);
	game->data->wall_v->addr = mlx_get_data_addr(game->sprite->wall_v,
			game->data->wall_v->bpp, game->data->wall_v->len,
			game->data->wall_v->endian);
	game->data->wall_h->addr = mlx_get_data_addr(game->sprite->wall_h,
			game->data->wall_h->bpp, game->data->wall_h->len,
			game->data->wall_h->endian);
	game->data->colt->addr = mlx_get_data_addr(game->sprite->colt,
			game->data->colt->bpp, game->data->colt->len,
			game->data->colt->endian);
	game->data->exit_c->addr = mlx_get_data_addr(game->sprite->exit_c,
			game->data->exit_c->bpp, game->data->exit_c->len,
			game->data->exit_c->endian);
	game->data->exit_o->addr = mlx_get_data_addr(game->sprite->exit_o,
			game->data->exit_o->bpp, game->data->exit_o->len,
			game->data->exit_o->endian);
	game->data->chara->addr = mlx_get_data_addr(game->sprite->chara,
			game->data->chara->bpp, game->data->chara->len,
			game->data->chara->endian);
	game->data->bord->addr = mlx_get_data_addr(game->sprite->bord,
			game->data->bord->bpp, game->data->bord->len,
			game->data->bord->endian);
	game->data->bord_v->addr = mlx_get_data_addr(game->sprite->bord_v,
			game->data->bord_v->bpp, game->data->bord_v->len,
			game->data->bord_v->endian);
	game->data->bord_h->addr = mlx_get_data_addr(game->sprite->bord_h,
			game->data->bord_h->bpp, game->data->bord_h->len,
			game->data->bord_h->endian);
	game->data->bord_c->addr = mlx_get_data_addr(game->sprite->bord_c,
			game->data->bord_c->bpp, game->data->bord_c->len,
			game->data->bord_c->endian);
}

void	set_assets(t_game *game, t_map *map)
{
	game->sprite = malloc(sizeof(t_sprt));
	if (!game->sprite)
		exit(1); // -make it free
	make_sprite_data(game);
	if (map->heigth <= 10 && map->width <= 19)
	{
		game->spr_size = 90;
		set_sprites_bg_big(game, 15);
		// set_sprites_fg(game, 15);
	}
	else
	{
		game->spr_size = 45;
		set_sprites_bg_small(game, 15);
		// set_sprites_fg(game, 15);
	}
	if (!game->sprite->empty || !game->sprite->wall_v || !game->sprite->wall_h
		|| !game->sprite->colt || !game->sprite->exit_c || !game->sprite->exit_o
		|| !game->sprite->chara || !game->sprite->bord || !game->sprite->bord_v
		|| !game->sprite->bord_h || !game->sprite->bord_c)
		img_destroyer(game, map); // -make it game_destroyer
	get_sprite_data_bg(game);
	// get_sprite_data_fg(*game);
}

void	make_sprite_data(t_game *game)
{
	game->data->empty = malloc(sizeof(t_data));
	game->data->wall_v = malloc(sizeof(t_data));
	game->data->wall_h = malloc(sizeof(t_data));
	game->data->colt = malloc(sizeof(t_data));
	game->data->exit_c = malloc(sizeof(t_data));
	game->data->exit_o = malloc(sizeof(t_data));
	game->data->chara = malloc(sizeof(t_data));
	game->data->bord = malloc(sizeof(t_data));
	game->data->bord_v = malloc(sizeof(t_data));
	game->data->bord_h = malloc(sizeof(t_data));
	game->data->bord_c = malloc(sizeof(t_data));
	if (!game->data->empty || !game->data->wall_v || !game->data->wall_h
		|| !game->data->colt || !game->data->exit_c || !game->data->exit_o
		|| !game->data->chara || !game->data->bord || !game->data->bord_v
		|| !game->data->bord_h || !game->data->bord_c)
		img_destroyer(game, map); // -make it game_destroyer
}

void	set_sprites_bg_big(t_game *game, int gap)
{
	ft_printf("setting big sprites (small map)\n") game->sprite->empty = mlx_xpm_file_to_image(game->mlx,
			EMPTY, &game->spr_size, &game->spr_size);
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

void	set_sprites_bg_small(t_game *game, int gap)
{
	ft_printf("setting small sprites (big map)\n") game->sprite->empty = mlx_xpm_file_to_image(game->mlx,
			SEMPTY, &game->spr_size, &game->spr_size);
	game->sprite->wall_v = mlx_xpm_file_to_image(game->mlx, SWALLV,
			&game->spr_size, &game->spr_size);
	game->sprite->wall_h = mlx_xpm_file_to_image(game->mlx, SWALLH,
			&game->spr_size, &game->spr_size);
	game->sprite->colt = mlx_xpm_file_to_image(game->mlx, SCOLT,
			&game->spr_size, &game->spr_size);
	game->sprite->exit_c = mlx_xpm_file_to_image(game->mlx, SEXITC,
			&game->spr_size, &game->spr_size);
	game->sprite->exit_o = mlx_xpm_file_to_image(game->mlx, SEXITO,
			&game->spr_size, &game->spr_size);
	game->sprite->chara = mlx_xpm_file_to_image(game->mlx, SCHARA,
			&game->spr_size, &game->spr_size);
	game->sprite->bord = mlx_xpm_file_to_image(game->mlx, SBORD,
			&game->spr_size, &game->spr_size);
	game->sprite->bord_v = mlx_xpm_file_to_image(game->mlx, SBORDV, &gap,
			&game->spr_size);
	game->sprite->bord_h = mlx_xpm_file_to_image(game->mlx, SBORDH,
			&game->spr_size, &gap);
	game->sprite->bord_c = mlx_xpm_file_to_image(game->mlx, SBORDC, &gap, &gap);
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
