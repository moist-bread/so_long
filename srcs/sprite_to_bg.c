/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_to_bg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 08:42:08 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/01/27 18:50:29 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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

void	new_sprite_to_bg_hflip(t_game *game, t_data *sprite, t_cord sprt,
		t_cord win)
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
			color = get_pixel(sprite, sprt.x - wid - 1, hei);
			if (color != TRANSPARENT)
				put_pixel(game->bg, win.x + wid, win.y + hei, color);
		}
	}
}

void	new_sprite_to_bg_vflip(t_game *game, t_data *sprite, t_cord sprt,
		t_cord win)
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
			color = get_pixel(sprite, wid, sprt.y - hei - 1);
			if (color != TRANSPARENT)
				put_pixel(game->bg, win.x + wid, win.y + hei, color);
		}
	}
}

void	new_sprite_to_bg_rotr(t_game *game, t_data *sprite, t_cord sprt,
		t_cord win)
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
			color = get_pixel(sprite, sprt.y - hei - 1, wid);
			if (color != TRANSPARENT)
				put_pixel(game->bg, win.x + wid, win.y + hei, color);
		}
	}
}

void	new_sprite_to_bg_rotl(t_game *game, t_data *sprite, t_cord sprt,
		t_cord win)
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
			color = get_pixel(sprite, hei, sprt.x - wid - 1);
			if (color != TRANSPARENT)
				put_pixel(game->bg, win.x + wid, win.y + hei, color);
		}
	}
}
