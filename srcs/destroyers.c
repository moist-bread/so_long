/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroyers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:55:59 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/02/10 11:35:16 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// 1 game didnt malloc
// 2 mlx didnt create
// 3 win didnt create
// 4 game sprite didnt malloc
// 5 sprites didnt malloc
// 6 sprite imgs didnt create
// 7 game bg didnt malloc
// 8 bg bg img didnt create
// 10 end of program

void	game_destroyer(t_game *game, t_map *map, int status)
{
	free_map(map, map->heigth);
	if (status >= 8)
		mlx_destroy_image(game->mlx, game->bg->img);
	if (status >= 7)
		free(game->bg);
	if (status >= 6)
		img_destroyer(game);
	if (status >= 5)
		sprite_destroyer(game);
	if (status >= 4)
		mlx_destroy_window(game->mlx, game->win);
	if (status >= 3)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (status >= 2)
		free(game);
	if (status >= 1)
		exit(status);
}

void	img_destroyer(t_game *game)
{
	ft_printf("img destroyer 3000\n");
	if (game->sprite->bord->img)
		mlx_destroy_image(game->mlx, game->sprite->bord->img);
	if (game->sprite->bord_c->img)
		mlx_destroy_image(game->mlx, game->sprite->bord_c->img);
	if (game->sprite->bevel->img)
		mlx_destroy_image(game->mlx, game->sprite->bevel->img);
	if (game->sprite->bevel_c->img)
		mlx_destroy_image(game->mlx, game->sprite->bevel_c->img);
	if (game->sprite->speaker->img)
		mlx_destroy_image(game->mlx, game->sprite->speaker->img);
	if (game->sprite->logo->img)
		mlx_destroy_image(game->mlx, game->sprite->logo->img);
	if (game->sprite->button->img)
		mlx_destroy_image(game->mlx, game->sprite->button->img);
	if (game->sprite->arrow->img)
		mlx_destroy_image(game->mlx, game->sprite->arrow->img);
	img_fg_destroyer(game);
}

void	img_fg_destroyer(t_game *game)
{
	if (game->sprite->empty_1->img)
		mlx_destroy_image(game->mlx, game->sprite->empty_1->img);
	if (game->sprite->wall->img)
		mlx_destroy_image(game->mlx, game->sprite->wall->img);
	if (game->sprite->wall_m->img)
		mlx_destroy_image(game->mlx, game->sprite->wall_m->img);
	if (game->sprite->wall_c->img)
		mlx_destroy_image(game->mlx, game->sprite->wall_c->img);
	if (game->sprite->exit_c->img)
		mlx_destroy_image(game->mlx, game->sprite->exit_c->img);
	if (game->sprite->exit_o->img)
		mlx_destroy_image(game->mlx, game->sprite->exit_o->img);
	if (game->sprite->colt->img)
		mlx_destroy_image(game->mlx, game->sprite->colt->img);
	if (game->sprite->chara_1->img)
		mlx_destroy_image(game->mlx, game->sprite->chara_1->img);
	if (game->sprite->chara_2->img)
		mlx_destroy_image(game->mlx, game->sprite->chara_2->img);
	if (game->sprite->chara_3->img)
		mlx_destroy_image(game->mlx, game->sprite->chara_3->img);
}

void	sprite_destroyer(t_game *game)
{
	ft_printf("sprite destroyer 3000\n");
	if (game->sprite->bord)
		free(game->sprite->bord);
	if (game->sprite->bord_c)
		free(game->sprite->bord_c);
	if (game->sprite->bevel)
		free(game->sprite->bevel);
	if (game->sprite->bevel_c)
		free(game->sprite->bevel_c);
	if (game->sprite->speaker)
		free(game->sprite->speaker);
	if (game->sprite->logo)
		free(game->sprite->logo);
	if (game->sprite->button)
		free(game->sprite->button);
	if (game->sprite->arrow)
		free(game->sprite->arrow);
	sprite_fg_destroyer(game);
}

void	sprite_fg_destroyer(t_game *game)
{
	if (game->sprite->empty_1)
		free(game->sprite->empty_1);
	if (game->sprite->wall)
		free(game->sprite->wall);
	if (game->sprite->wall_m)
		free(game->sprite->wall_m);
	if (game->sprite->wall_c)
		free(game->sprite->wall_c);
	if (game->sprite->exit_c)
		free(game->sprite->exit_c);
	if (game->sprite->exit_o)
		free(game->sprite->exit_o);
	if (game->sprite->colt)
		free(game->sprite->colt);
	if (game->sprite->chara_1)
		free(game->sprite->chara_1);
	if (game->sprite->chara_2)
		free(game->sprite->chara_2);
	if (game->sprite->chara_3)
		free(game->sprite->chara_3);
	free(game->sprite);
}
