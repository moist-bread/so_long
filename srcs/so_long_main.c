/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:15:33 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/01/09 18:11:02 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
		return (2);
	map_parsing(argv[1], &map);
	game_start(map);
	free_map(map, map->heigth);
	return (0);
}

void	my_mlx_pixel_put(char *addr, int line_length, int bits_per_pixel, int y, int x, int color)
{
	char	*dst;

	dst = addr + (y * line_length + x * (bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	key_win1(int key, void *p)
{
	(void)p;
	ft_printf("%p (key)\n", key);
	return(0);
}

void	game_start(t_map *map)
{
	void *mlx;
	void *mlx_win;
	void *img;
	void *img2;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
	char	*relative_path = "./beetles.xpm";
	int		img_width;
	int		img_height;

	(void)map;
	// initialize
	if (!(mlx = mlx_init()))
		exit(1); // -make it free
	// pop up with xy dimentions and name depending on map size
	if (map->heigth < 10 && map->width < 19)
		mlx_win = mlx_new_window(mlx, (map->width + 2) * 90, (map->heigth + 2) * 90, "window");
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
	// putting the xpm file in the img2 
	img2 = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	// put the layers in the window
	mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);
	//mlx_put_image_to_window(mlx, mlx_win, img2, 500, 0);
	// write on the window with xy coordinates, and color, a sentence
	mlx_string_put(mlx, mlx_win, 200, 600 / 2, 0xFF99FF, "lorem ipsum");
	// mlx_key_hook(mlx_win, key_win1, 0); // key detecter
	mlx_loop(mlx);

}

void make_grid(char *addr, int line_length, int bits_per_pixel)
{
	int y;
	int x;
	
	y = 89;
	while(++y < 180)
	{
		x = 114;
		while (++x < 205)
			my_mlx_pixel_put(addr, line_length, bits_per_pixel, y, x, 0x00E4CDFF);
	}
	y =89;
	while(++y < 180)
	{
		x = 204;
		while (++x < 295)
			my_mlx_pixel_put(addr, line_length, bits_per_pixel, y, x, 0x0065E0E1);
	}
}