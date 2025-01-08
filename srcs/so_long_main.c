/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:15:33 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/01/08 18:10:03 by rduro-pe         ###   ########.fr       */
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

void	game_start(t_map *map)
{
	void *mlx;
	void *mlx_win;
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;

	(void)map;
	// initialize
	if (!(mlx = mlx_init()))
		exit(1); // -make it free
	// pop up with xy dimentions and name
	if (!(mlx_win = mlx_new_window(mlx, 1920, 1080, "window")))
		exit(1); // -make it free
	// great the empty img (like a layer)
	img = mlx_new_image(mlx, 1920, 1080);
	// get information of the img (layer config)
	addr = mlx_get_data_addr(img, &bits_per_pixel, &line_length, &endian);
	
	// put the img in the window
	mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);
	// write on the window with xy coordinates, and color, a sentence
	mlx_string_put(mlx, mlx_win, 200, 1080 / 2, 0xFF99FF, "lorem ipsum");
	mlx_loop(mlx);
}