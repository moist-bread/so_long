/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_to_bg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 08:42:08 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/01/26 17:48:39 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	sprite_to_bg(t_game *game, t_data *sprite, int x, int y)
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
				put_pixel(game->bg, x + wid, y + hei, color);
		}
	}
}

void	new_sprite_to_bg(t_game *game, t_data *sprite, t_cord sprt, t_cord win)
{
	unsigned int	color;
	int				wid;
	int				hei;

	hei = -1;
	while (++hei < sprt.y)
	{
		wid = -1;
		while (++wid < sprt.x)
		{
			color = get_pixel(sprite, wid, hei);
			if (color != TRANSPARENT)
				put_pixel(game->bg, win.x + wid, win.y + hei, color);
		}
	}
}

void	sprite_to_bg_hflip(t_game *game, t_data *sprite, int x, int y)
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
			color = get_pixel(sprite, game->spr_size - wid - 1, hei);
			put_pixel(game->bg, x + wid, y + hei, color);
		}
	}
}

void	sprite_to_bg_vflip(t_game *game, t_data *sprite, int x, int y)
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
			color = get_pixel(sprite, wid, game->spr_size - hei - 1);
			put_pixel(game->bg, x + wid, y + hei, color);
		}
	}
}

void	sprite_to_bg_rotr(t_game *game, t_data *sprite, int x, int y)
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
			color = get_pixel(sprite, game->spr_size - hei - 1, wid);
			put_pixel(game->bg, x + wid, y + hei, color);
		}
	}
}

void	sprite_to_bg_rotl(t_game *game, t_data *sprite, int x, int y)
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
			color = get_pixel(sprite, hei, game->spr_size - wid - 1);
			put_pixel(game->bg, x + wid, y + hei, color);
		}
	}
}

void	sprite_to_bg_mirr(t_game *game, t_data *sprite, int x, int y)
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
			color = get_pixel(sprite, game->spr_size - hei - 1, game->spr_size
					- wid - 1);
			put_pixel(game->bg, x + wid, y + hei, color);
		}
	}
}
