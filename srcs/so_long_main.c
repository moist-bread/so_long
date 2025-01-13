/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:15:33 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/01/13 23:37:56 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	game_stort_test(t_map *map);

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
		return (2);
	map_parsing(argv[1], &map);
	// game_stort_test(map);
	game_start(map);
	free_map(map, map->heigth);
	return (0);
}

void	game_start(t_map *map)
{
	t_game	*game;

	set_game(&game, map);
	put_border(game, map);
	put_map(game, map);
	mlx_loop(game->mlx);
}

void	sprite_to_bg_img(t_game *game, void *sprite, int x, int y)
{
}

void	put_border(t_game *game, t_map *map)
{
	int	y;
	int	x;

	y = map->heigth + 2;
	x = 0;
	while ((!game->offset && ++x < map->width + 2) || (game->offset
			&& ++x < 21))
	{ // replace with sprite_to_bg_img(game, game->sprite->border, x, y);
		mlx_put_image_to_window(game->mlx, game->win, game->sprite->colt, (x
				* game->spr_size) + game->offset, 0);
		mlx_put_image_to_window(game->mlx, game->win, game->sprite->colt, (x
				* game->spr_size) + game->offset, (y - 1) * game->spr_size);
	}
	while (--y >= 0)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->sprite->colt,
			game->offset, y * game->spr_size);
		mlx_put_image_to_window(game->mlx, game->win, game->sprite->colt, ((x
					- 1) * game->spr_size) + game->offset, y * game->spr_size);
		if (game->offset)
		{
			mlx_put_image_to_window(game->mlx, game->win, game->sprite->bord_v,
				0, y * game->spr_size);
			mlx_put_image_to_window(game->mlx, game->win, game->sprite->bord_v,
				(x * game->spr_size) + game->offset, y * game->spr_size);
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
		mlx_put_image_to_window(game->mlx, game->win, game->sprite->empty, ((x
					+ 1) * game->spr_size) + game->offset, (y + 1)
			* game->spr_size);
	else if (type == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->sprite->wall_h, ((x
					+ 1) * game->spr_size) + game->offset, (y + 1)
			* game->spr_size);
	else if (type == 'c')
		mlx_put_image_to_window(game->mlx, game->win, game->sprite->colt, ((x
					+ 1) * game->spr_size) + game->offset, (y + 1)
			* game->spr_size);
	else if (type == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->sprite->exit_c, ((x
					+ 1) * game->spr_size) + game->offset, (y + 1)
			* game->spr_size);
	else if (type == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->sprite->chara, ((x
					+ 1) * game->spr_size) + game->offset, (y + 1)
			* game->spr_size);
}

void	my_mlx_pixel_put(char *addr, int line_length, int bits_per_pixel, int y,
		int x, int color)
{
	char	*dst;

	dst = addr + (y * line_length + x * (bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

// GET COLOR THING
/* char	*my_mlx_pixel_get(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return (dst);
} */
int	key_win1(int key, void *p)
{
	(void)p;
	ft_printf("%p (key)\n", key);
	return (0);
}

void	game_stort_test(t_map *map)
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*relative_path;

	// void	*img2;
	// int		img_width;
	// int		img_height;
	relative_path = "./assets/big/beetles.xpm";
	// initialize
	if (!(mlx = mlx_init()))
		exit(1); // -make it free
	// pop up with xy dimentions and name depending on map size
	if (map->heigth < 10 && map->width < 19)
		mlx_win = mlx_new_window(mlx, (map->width + 2) * 90, (map->heigth + 2)
				* 90, "window");
	else
		mlx_win = mlx_new_window(mlx, 1920, 1080, "window");
	if (!mlx_win)
		exit(1); // -make it free
	// great the empty img (like a layer)
	img = mlx_new_image(mlx, 1920, 1080);
	// get information of the img (layer config)
	addr = mlx_get_data_addr(img, &bits_per_pixel, &line_length, &endian);
	// putting the pixels in the img
	// make_grid(addr, line_length, bits_per_pixel);
	make_square(addr, line_length, bits_per_pixel);
	// putting the xpm file in the img2
	// img2 = mlx_xpm_file_to_image(mlx, relative_path, &img_width,
	// &img_height);
	// put the layers in the window
	mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);
	// mlx_put_image_to_window(mlx, mlx_win, img2, 15, 0);
	// write on the window with xy coordinates, and color, a sentence
	mlx_string_put(mlx, mlx_win, 200, 600 / 2, 0xFF99FF, "lorem ipsum");
	mlx_key_hook(mlx_win, key_win1, 0); // key detecter
	mlx_loop(mlx);
}

void	make_square(char *addr, int line_length, int bits_per_pixel)
{
	int	y;
	int	x;

	y = 44;
	while (++y < 90)
	{
		x = 44;
		while (++x < 90)
			my_mlx_pixel_put(addr, line_length, bits_per_pixel, y, x,
				0x00E4CDFF);
	}
}

void	make_grid(char *addr, int line_length, int bits_per_pixel)
{
	int y;
	int x;

	y = 89;
	while (++y < 180)
	{
		x = 114;
		while (++x < 205)
			my_mlx_pixel_put(addr, line_length, bits_per_pixel, y, x,
				0x00E4CDFF);
	}
	y = 89;
	while (++y < 180)
	{
		x = 204;
		while (++x < 295)
			my_mlx_pixel_put(addr, line_length, bits_per_pixel, y, x,
				0x0065E0E1);
	}
}