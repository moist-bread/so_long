/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:15:02 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/01/28 07:46:55 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	set_sprites_big(t_game *game, int gap)
{
	set_sprites_both(game, gap);
	ft_printf("setting big sprites (small map)\n");
	game->sprite->empty_1->img = mlx_xpm_file_to_image(game->mlx, EMPTY1,
			&game->size, &game->size);
	game->sprite->empty_2->img = mlx_xpm_file_to_image(game->mlx, EMPTY2,
			&game->size, &game->size);
	game->sprite->wall->img = mlx_xpm_file_to_image(game->mlx, WALL,
			&game->size, &game->size);
	game->sprite->wall_m->img = mlx_xpm_file_to_image(game->mlx, WALLM,
			&game->size, &game->size);
	game->sprite->wall_c->img = mlx_xpm_file_to_image(game->mlx, WALLC,
			&game->size, &game->size);
	game->sprite->exit_c->img = mlx_xpm_file_to_image(game->mlx, EXITC,
			&game->size, &game->size);
	game->sprite->exit_o->img = mlx_xpm_file_to_image(game->mlx, EXITO,
			&game->size, &game->size);
	game->sprite->colt->img = mlx_xpm_file_to_image(game->mlx, COLT,
			&game->size, &game->size);
	game->sprite->chara_1->img = mlx_xpm_file_to_image(game->mlx, CHARA1,
			&game->size, &game->size);
	game->sprite->chara_2->img = mlx_xpm_file_to_image(game->mlx, CHARA2,
			&game->size, &game->size);
	game->size = 90;
}

void	set_sprites_small(t_game *game, int gap)
{
	set_sprites_both(game, gap);
	ft_printf("setting small bg sprites (big map)\n");
	game->sprite->empty_1->img = mlx_xpm_file_to_image(game->mlx, SEMPTY1,
			&game->size, &game->size);
	game->sprite->empty_2->img = mlx_xpm_file_to_image(game->mlx, SEMPTY2,
			&game->size, &game->size);
	game->sprite->wall->img = mlx_xpm_file_to_image(game->mlx, SWALL,
			&game->size, &game->size);
	game->sprite->wall_m->img = mlx_xpm_file_to_image(game->mlx, SWALLM,
			&game->size, &game->size);
	game->sprite->wall_c->img = mlx_xpm_file_to_image(game->mlx, SWALLC,
			&game->size, &game->size);
	game->sprite->exit_c->img = mlx_xpm_file_to_image(game->mlx, SEXITC,
			&game->size, &game->size);
	game->sprite->exit_o->img = mlx_xpm_file_to_image(game->mlx, SEXITO,
			&game->size, &game->size);
	game->sprite->colt->img = mlx_xpm_file_to_image(game->mlx, SCOLT,
			&game->size, &game->size);
	game->sprite->chara_1->img = mlx_xpm_file_to_image(game->mlx, SCHARA1,
			&game->size, &game->size);
	game->sprite->chara_2->img = mlx_xpm_file_to_image(game->mlx, SCHARA2,
			&game->size, &game->size);
	game->size = 45;
}

void	set_sprites_both(t_game *game, int gap)
{
	ft_printf("setting overlap sprites\n");
	game->sprite->bord->img = mlx_xpm_file_to_image(game->mlx, BORD,
			&game->size, &game->size);
	game->sprite->bord_c->img = mlx_xpm_file_to_image(game->mlx, BORDC,
			&game->size, &game->size);
	game->sprite->bevel->img = mlx_xpm_file_to_image(game->mlx, BVL, &gap,
			&game->size);
	game->sprite->bevel_c->img = mlx_xpm_file_to_image(game->mlx, BVLC, &gap,
			&gap);
	game->sprite->speaker->img = mlx_xpm_file_to_image(game->mlx, SPKR, &gap,
			&gap);
	game->sprite->logo->img = mlx_xpm_file_to_image(game->mlx, LOGO, &gap,
			&gap);
	game->sprite->button->img = mlx_xpm_file_to_image(game->mlx, BTN, &gap,
			&gap);
	game->sprite->arrow->img = mlx_xpm_file_to_image(game->mlx, ARRW, &gap,
			&gap);
}
