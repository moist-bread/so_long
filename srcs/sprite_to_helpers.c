/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_to_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:02:09 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/02/09 10:01:02 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	sprite_to_bg_mirr(t_game *game, t_data *sprite, t_cord sprt, t_cord win)
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
			color = get_pixel(sprite, sprt.y - hei - 1, sprt.x - wid - 1);
			if (color != TRANSPARENT)
				put_pixel(game->bg, win.x + wid, win.y + hei, color);
		}
	}
}

void	colorblock_to_bg(t_game *game, int color, t_cord sprt, t_cord win)
{
	int	wid;
	int	hei;

	hei = -1;
	while (++hei < sprt.y)
	{
		wid = -1;
		while (++wid < sprt.x)
			put_pixel(game->bg, win.x + wid, win.y + hei, color);
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
