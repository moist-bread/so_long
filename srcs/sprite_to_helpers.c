/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_to_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:02:09 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/01/17 12:03:31 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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
		while (++wid < game->offset)
		{
			color = get_pixel(sprite, wid, hei);
			put_pixel(game->bg, x + wid, y + hei, color);
		}
	}
}

void	gap_to_bg_img_h(t_game *game, t_data *sprite, int x, int y)
{
	unsigned int	color;
	int				wid;
	int				hei;

	hei = -1;
	while (++hei < game->offset)
	{
		wid = -1;
		while (++wid < game->spr_size)
		{
			color = get_pixel(sprite, wid, hei);
			put_pixel(game->bg, x + wid, y + hei, color);
		}
	}
}
