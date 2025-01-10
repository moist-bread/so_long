/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:23:43 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/01/10 21:40:47 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	*mlx;
void	*mlx_win;

/* int	key_win1(int key, void *p)
{
	(void)p;
	if (key == 0xFF1B)
	{
		mlx_destroy_window(mlx, mlx_win);
		exit(0);
	}
	return(0);
} */

int	window_test(void)
{
	// initialize
	if (!(mlx = mlx_init()))
		exit(1);
	// pop up with xy dimentions and name
	if (!(mlx_win = mlx_new_window(mlx, 1920, 1080, "window")))
		exit(1);
	// write on the window with xy coordinates, and color, a sentence
	mlx_string_put(mlx, mlx_win, 200, 1080 / 2, 0xFF99FF, "lorem ipsum");
	// detect key presses, in this case ESC key
	mlx_key_hook(mlx_win, key_win1, 0);
	mlx_loop(mlx);
	return(0);
}