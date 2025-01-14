/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_bg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:31:05 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/01/14 18:30:32 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	sprite_to_bg_img(t_game *game, t_data *sprite, int x, int y)
{
	unsigned int color;
	int	wid;
	int	hei;

	hei = -1;
	while (++hei <= game->spr_size)
	{
		wid = -1;
		while (++wid <= game->spr_size)
		{
			color = get_pixel(sprite, wid, hei);
			ft_printf("why are we still here, just to suffer 1\n");
			put_pixel(game->bg, x + wid, y + hei, 0x0065E0E1);
		}	
	}
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
	{ // replace with sprite_to_bg_img(game, game->sprite->bord, x, y);
		mlx_put_image_to_window(game->mlx, game->win, game->sprite->bord->img,
			(x * game->spr_size) + game->offset, 0);
		mlx_put_image_to_window(game->mlx, game->win, game->sprite->bord->img,
			(x * game->spr_size) + game->offset, (y - 1) * game->spr_size);
	}
	while (--y >= 0)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->sprite->bord->img,
			game->offset, y * game->spr_size);
		mlx_put_image_to_window(game->mlx, game->win, game->sprite->bord->img,
			((x - 1) * game->spr_size) + game->offset, y * game->spr_size);
		if (game->offset)
		{
			mlx_put_image_to_window(game->mlx, game->win,
				game->sprite->bord_v->img, 0, y * game->spr_size);
			mlx_put_image_to_window(game->mlx, game->win,
				game->sprite->bord_v->img, (x * game->spr_size) + game->offset,
				y * game->spr_size);
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
		}
	}
}

void	put_sprite(t_game *game, int y, int x, int type)
{
	if (type == 'O')
		mlx_put_image_to_window(game->mlx, game->win, game->sprite->empty->img,
			((x + 1) * game->spr_size) + game->offset, (y + 1)
			* game->spr_size);
	else if (type == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->sprite->wall_h->img,
			((x + 1) * game->spr_size) + game->offset, (y + 1)
			* game->spr_size);
	else if (type == 'c')
		mlx_put_image_to_window(game->mlx, game->win, game->sprite->colt->img,
			((x + 1) * game->spr_size) + game->offset, (y + 1)
			* game->spr_size);
	else if (type == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->sprite->exit_c->img,
			((x + 1) * game->spr_size) + game->offset, (y + 1)
			* game->spr_size);
	else if (type == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->sprite->chara->img,
			((x + 1) * game->spr_size) + game->offset, (y + 1)
			* game->spr_size);
}

int get_pixel(t_data *img, int x, int y)
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
	ft_printf("why are we still here, just to suffer 2\n");
}

// GET COLOR THING
/* char	*my_mlx_pixel_get(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return (dst);
} */
