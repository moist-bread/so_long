/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:15:02 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/01/23 19:44:55 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	set_sprites_bg_big(t_game *game, int gap)
{
	ft_printf("setting big sprites (small map)\n");
	game->sprite->empty->img = mlx_xpm_file_to_image(game->mlx, EMPTY,
			&game->spr_size, &game->spr_size);
	game->sprite->wall_v->img = mlx_xpm_file_to_image(game->mlx, WALLV, &gap,
			&gap);
	game->sprite->wall_h->img = mlx_xpm_file_to_image(game->mlx, WALLH,
			&game->spr_size, &game->spr_size);
	game->sprite->colt->img = mlx_xpm_file_to_image(game->mlx, COLT,
			&game->spr_size, &game->spr_size);
	game->sprite->exit_c->img = mlx_xpm_file_to_image(game->mlx, EXITC,
			&game->spr_size, &game->spr_size);
	game->sprite->exit_o->img = mlx_xpm_file_to_image(game->mlx, EXITO,
			&game->spr_size, &game->spr_size);
	game->sprite->chara->img = mlx_xpm_file_to_image(game->mlx, CHARA,
			&game->spr_size, &game->spr_size);
	game->sprite->bord->img = mlx_xpm_file_to_image(game->mlx, BORD,
			&game->spr_size, &game->spr_size);
	game->sprite->bord_v->img = mlx_xpm_file_to_image(game->mlx, BORDV, &gap,
			&game->spr_size);
	game->sprite->bord_h->img = mlx_xpm_file_to_image(game->mlx, BORDH,
			&game->spr_size, &gap);
	game->sprite->bord_c->img = mlx_xpm_file_to_image(game->mlx, BORDC,
			&game->spr_size, &game->spr_size);
	game->spr_size = 90;
}

void	set_sprites_bg_small(t_game *game, int gap)
{
	ft_printf("setting small sprites (big map)\n");
	game->sprite->empty->img = mlx_xpm_file_to_image(game->mlx, SEMPTY,
			&game->spr_size, &game->spr_size);
	game->sprite->wall_v->img = mlx_xpm_file_to_image(game->mlx, SWALLV,
			&game->spr_size, &game->spr_size);
	game->sprite->wall_h->img = mlx_xpm_file_to_image(game->mlx, SWALLH,
			&game->spr_size, &game->spr_size);
	game->sprite->colt->img = mlx_xpm_file_to_image(game->mlx, SCOLT,
			&game->spr_size, &game->spr_size);
	game->sprite->exit_c->img = mlx_xpm_file_to_image(game->mlx, SEXITC,
			&game->spr_size, &game->spr_size);
	game->sprite->exit_o->img = mlx_xpm_file_to_image(game->mlx, SEXITO,
			&game->spr_size, &game->spr_size);
	game->sprite->chara->img = mlx_xpm_file_to_image(game->mlx, SCHARA,
			&game->spr_size, &game->spr_size);
	game->sprite->bord->img = mlx_xpm_file_to_image(game->mlx, SBORD,
			&game->spr_size, &game->spr_size);
	game->sprite->bord_v->img = mlx_xpm_file_to_image(game->mlx, SBORDV, &gap,
			&game->spr_size);
	game->sprite->bord_h->img = mlx_xpm_file_to_image(game->mlx, SBORDH,
			&game->spr_size, &gap);
	game->sprite->bord_c->img = mlx_xpm_file_to_image(game->mlx, SBORDC, &gap,
			&gap);
	game->spr_size = 45;
}

void	set_sprites_fg_big(t_game *game, int gap)
{
	(void)game;
	(void)gap;
}

void	set_sprites_fg_small(t_game *game, int gap)
{
	(void)game;
	(void)gap;
}