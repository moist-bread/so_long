/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:23:43 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/01/14 15:18:04 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	game_stort_test2(t_map *map)
{
	t_game	*game;

	(void)map;
	game = malloc(sizeof(t_game));
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 1920, 1080, "window big");
	// great the empty img (like a layer)
	// img = mlx_new_image(game->mlx, 1920, 1080);
	// get information of the img (layer config)
	// addr = mlx_get_data_addr(img, &bits_per_pixel, &line_length, &endian);
	// putting the pixels in the img
	// make_grid(addr, line_length, bits_per_pixel);
	// make_square(addr, line_length, bits_per_pixel);
	// putting the xpm file in the img2
	game->spr_size = 90;
	game->bg = malloc(sizeof(t_data *));
	game->bg->img = mlx_xpm_file_to_image(game->mlx, EMPTY, &game->spr_size,
			&game->spr_size);
	game->bg->len = 2;
	ft_printf("%p", game->bg->img);
	// put the layers in the window
	// mlx_put_image_to_window(game->mlx, game->win, img, 0, 0);
	mlx_put_image_to_window(game->mlx, game->win, game->bg->img, 15, 15);
	// write on the window with xy coordinates, and color, a sentence
	mlx_string_put(game->mlx, game->win, 200, 600 / 2, 0xFF99FF, "lorem ipsum");
	mlx_key_hook(game->win, key_win1, 0); // key detecter
	mlx_loop(game->mlx);
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
	void	*img2;
	int		img_width;
	int		img_height;

	relative_path = EMPTY;
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
	make_grid(addr, line_length, bits_per_pixel);
	make_square(addr, line_length, bits_per_pixel);
	// putting the xpm file in the img2
	img2 = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	// put the layers in the window
	mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);
	mlx_put_image_to_window(mlx, mlx_win, img2, 15, 0);
	ft_printf("im so confused\n");
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
	int	y;
	int	x;

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

void	my_mlx_pixel_put(char *addr, int line_length, int bits_per_pixel, int y,
		int x, int color)
{
	char	*dst;

	dst = addr + (y * line_length + x * (bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	key_win1(int key, void *p)
{
	(void)p;
	ft_printf("%p (key)\n", key);
	return (0);
}
