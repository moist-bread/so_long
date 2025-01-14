/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroyers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:55:59 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/01/14 13:56:21 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	img_destroyer(t_game *game, t_map *map)
{
	(void)map;
	ft_printf("img destroyer 3000\n");
	// make into img destroyer and do the window and game destroying here and exit with frees
	if (game->sprite->empty->img)
		mlx_destroy_image(game->mlx, game->sprite->empty->img);
	if (game->sprite->wall_v->img)
		mlx_destroy_image(game->mlx, game->sprite->wall_v->img);
	if (game->sprite->wall_h->img)
		mlx_destroy_image(game->mlx, game->sprite->wall_h->img);
	if (game->sprite->colt->img)
		mlx_destroy_image(game->mlx, game->sprite->colt->img);
	if (game->sprite->exit_c->img)
		mlx_destroy_image(game->mlx, game->sprite->exit_c->img);
	if (game->sprite->exit_o->img)
		mlx_destroy_image(game->mlx, game->sprite->exit_o->img);
	if (game->sprite->chara->img)
		mlx_destroy_image(game->mlx, game->sprite->chara->img);
	if (game->sprite->bord->img)
		mlx_destroy_image(game->mlx, game->sprite->bord->img);
	if (game->sprite->bord_v->img)
		mlx_destroy_image(game->mlx, game->sprite->bord_v->img);
	if (game->sprite->bord_h->img)
		mlx_destroy_image(game->mlx, game->sprite->bord_h->img);
	if (game->sprite->bord_c->img)
		mlx_destroy_image(game->mlx, game->sprite->bord_c->img);
	// end
}
