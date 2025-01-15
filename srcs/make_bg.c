/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_bg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:31:05 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/01/15 19:16:02 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	sprite_to_bg_img(t_game *game, t_data *sprite, int x, int y)
{
	unsigned int	color;
	int				wid;
	int				hei;

	hei = -1;
	while (++hei < game->spr_size)
	{
		wid = -1;
		while (++wid < game->spr_size)
		{
			color = get_pixel(sprite, wid, hei);
			put_pixel(game->bg, x + wid, y + hei, color);
		}
	}
}

void	sprite_to_fg_img(t_game *game, t_data *sprite, int x, int y)
{
	unsigned int	color;
	int				wid;
	int				hei;

	hei = -1;
	while (++hei < game->spr_size)
	{
		wid = -1;
		while (++wid < game->spr_size)
		{
			color = get_pixel(sprite, wid, hei);
			if (color != TRANSPARENT)
				put_pixel(game->fg, x + wid, y + hei, color);
		}
	}
}

void	gap_to_bg_img(t_game *game, t_data *sprite, int x, int y)
{
	unsigned int	color;
	int				wid;
	int				hei;

	hei = -1;
	while (++hei < game->spr_size)
	{
		wid = -1;
		while (++wid < 15)
		{
			color = get_pixel(sprite, wid, hei);
			put_pixel(game->bg, x + wid, y + hei, color);
		}
	}
}

int	get_pixel(t_data *img, int x, int y)
{
	char	*dst;

	dst = img->addr + (y * img->len + x * (img->bpp / 8));
	return (*(unsigned int *)dst);
}

void	put_pixel(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	put_border(t_game *game, t_map *map)
{
	int	y;
	int	x;

	if (map->heigth > 10 || map->width > 19)
		y = 24;
	else
		y = map->heigth + 2;
	x = 0;
	while ((!game->offset && ++x < map->width + 2) || (game->offset
			&& ((game->spr_size == 90 && ++x < 21) || (game->spr_size == 45
					&& ++x < 42))))
	{
		sprite_to_bg_img(game, game->sprite->bord, (x * game->spr_size)
			+ game->offset, 0);
		sprite_to_bg_img(game, game->sprite->bord, (x * game->spr_size)
			+ game->offset, (y - 1) * game->spr_size);
	}
	while (--y >= 0)
	{
		sprite_to_bg_img(game, game->sprite->bord, game->offset, y
			* game->spr_size);
		sprite_to_bg_img(game, game->sprite->bord, ((x - 1) * game->spr_size)
			+ game->offset, y * game->spr_size);
		if (game->offset)
		{
			gap_to_bg_img(game, game->sprite->bord_v, 0, y * game->spr_size);
			gap_to_bg_img(game, game->sprite->bord_v, (x * game->spr_size)
				+ game->offset, y * game->spr_size);
		}
	}
}

void	put_map(t_game *game, t_map *map)
{
	int	y;
	int	x;

	y = -1;
	while (map->map[++y])
	{
		x = -1;
		while (map->map[y][++x])
		{
			put_sprite(game, y, x, map->map[y][x]);
			put_fg(game, y, x, map->map[y][x]);
		}
	}
}

int	put_player(t_game *game) // change name to something else pls
{
	// (void)game;
	mlx_clear_window(game->mlx, game->win);
	if (game->map->map[game->map->ps_cord.y][game->map->ps_cord.x] == 'c')
	{
		// collected++;
		put_sprite(game, game->map->ps_cord.y, game->map->ps_cord.x, 'O');
		game->map->map[game->map->ps_cord.y][game->map->ps_cord.x] = 'C';
	}
	// if (collected == game->map->colt) 
	// 	put_sprite(game, game->map->ps_cord.y, game->map->ps_cord.x, 'E');
	mlx_put_image_to_window(game->mlx, game->win, game->bg->img, 0, 0);
	// mlx_put_image_to_window(game->mlx, game->win, game->fg->img, 0, 0);
	// sprite_to_fg_img(game, game->sprite->bord, ((game->map->ps_cord.x + 1)
	// 		* game->spr_size) + game->offset, (game->map->ps_cord.y + 1)
	// 	* game->spr_size);
	mlx_put_image_to_window(game->mlx, game->win, game->sprite->chara->img,
		((game->map->ps_cord.x + 1) * game->spr_size) + game->offset,
		(game->map->ps_cord.y + 1) * game->spr_size);
	return (0);
}

void	put_fg(t_game *game, int y, int x, int type)
{
	// CHANGE BACK TO FG WHEN IT HAS TRANSPARENCY
	if (type == 'c')
		sprite_to_bg_img(game, game->sprite->colt, ((x + 1) * game->spr_size)
			+ game->offset, (y + 1) * game->spr_size);
	if (type == 'E')
		sprite_to_bg_img(game, game->sprite->exit_c, ((x + 1) * game->spr_size)
			+ game->offset, (y + 1) * game->spr_size);
	/* if (type == 'P')
		sprite_to_bg_img(game, game->sprite->chara, ((x + 1) * game->spr_size)
			+ game->offset, (y + 1) * game->spr_size); */
}

void	put_sprite(t_game *game, int y, int x, int type)
{
	if (type == 'O' || type == 'c' || type == 'E' || type == 'P')
		sprite_to_bg_img(game, game->sprite->empty, ((x + 1) * game->spr_size)
			+ game->offset, (y + 1) * game->spr_size);
	else if (type == '1')
		sprite_to_bg_img(game, game->sprite->wall_h, ((x + 1) * game->spr_size)
			+ game->offset, (y + 1) * game->spr_size);
	/* else if (type == 'c')
		sprite_to_bg_img(game, game->sprite->colt, ((x + 1) * game->spr_size)
			+ game->offset, (y + 1) * game->spr_size);
	else if (type == 'E')
		sprite_to_bg_img(game, game->sprite->exit_c, ((x + 1) * game->spr_size)
			+ game->offset, (y + 1) * game->spr_size);
	else if (type == 'P')
		sprite_to_bg_img(game, game->sprite->chara, ((x + 1) * game->spr_size)
			+ game->offset, (y + 1) * game->spr_size); */
}
