/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroyers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:55:59 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/01/17 17:47:51 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	game_destroyer(t_game *game, t_map *map)
{
	free_map(map, map->heigth);
	if (!game)
		exit(1);
	if (!game->mlx || !game->win)
	{
		free(game);
		exit(1);
	}
	if (!game->sprite)
	{
		mlx_destroy_window(game->mlx, game->win);
		free(game);
		exit(1);
	}
	if (!game->sprite->empty || !game->sprite->wall_v || !game->sprite->wall_h
		|| !game->sprite->colt || !game->sprite->exit_c || !game->sprite->exit_o
		|| !game->sprite->chara || !game->sprite->bord || !game->sprite->bord_v
		|| !game->sprite->bord_h || !game->sprite->bord_c)
	{
		free(game->sprite);
		mlx_destroy_window(game->mlx, game->win);
		free(game);
		exit(1);
	}
	if (!game->sprite->empty->img || !game->sprite->wall_v->img
		|| !game->sprite->wall_h->img || !game->sprite->colt->img
		|| !game->sprite->exit_c->img || !game->sprite->exit_o->img
		|| !game->sprite->chara->img || !game->sprite->bord->img
		|| !game->sprite->bord_v->img || !game->sprite->bord_h->img
		|| !game->sprite->bord_c->img)
	{
		img_destroyer(game);
		free(game->sprite);
		mlx_destroy_window(game->mlx, game->win);
		free(game);
		exit(1);
	}
	if (!game->bg || !game->fg)
	{
		if (game->bg)
			free(game->bg);
		if (game->fg)
			free(game->fg);
		img_destroyer(game);
		free(game->sprite);
		mlx_destroy_window(game->mlx, game->win);
		free(game);
		exit(1);
	}
	if (!game->bg->img || !game->fg->img)
	{
		if (game->bg->img)
			mlx_destroy_image(game->mlx, game->bg->img);
		if (game->fg->img)
			mlx_destroy_image(game->mlx, game->fg->img);
		free(game->bg);
		free(game->fg);
		img_destroyer(game);
		free(game->sprite);
		mlx_destroy_window(game->mlx, game->win);
		free(game);
		exit(1);
	}
	ft_printf("normal exit\n\n");
	mlx_destroy_image(game->mlx, game->bg->img);
	mlx_destroy_image(game->mlx, game->fg->img);
	free(game->bg);
	free(game->fg);
	img_destroyer(game);
	free (game->sprite->empty);
	free (game->sprite->wall_v);
	free (game->sprite->wall_h);
	free (game->sprite->colt);
	free (game->sprite->exit_c);
	free (game->sprite->exit_o);
	free (game->sprite->chara);
	free (game->sprite->bord);
	free (game->sprite->bord_v);
	free (game->sprite->bord_h);
	free (game->sprite->bord_c);
	free(game->sprite);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game);
	exit(0);
}

void	img_destroyer(t_game *game)
{
	ft_printf("img destroyer 3000\n");
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
}
