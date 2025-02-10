/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:15:33 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/02/10 11:31:41 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
		return (2);
	main_menu();
	map_parsing(argv[1], &map);
	sprite_checker(map);
	game_start(map);
	return (0);
}

void	main_menu(void)
{
	char	*line;

	main_menu_content();
	ft_printf(GRN "› you're a robot sent to collect" DEF);
	ft_printf("\t " HCYN "▖▞▙▗" DEF);
	ft_printf("\n" HCYN "▚▛▘▗\t" DEF);
	ft_printf(GRN "  valuable " YEL "SDCARDS\t\t" DEF);
	ft_printf("\t " HCYN "▖▞▙▗" DEF);
	ft_printf("\n\n\n" HCYN "▚▗▛▘\t" DEF);
	ft_printf(GRN "› escape with them through the" YEL " VENT" DEF);
	ft_printf("\t " HCYN "▖▞▙▗" DEF);
	ft_printf("\n\n\n" HCYN "▚▗▛▘\t" DEF);
	ft_printf(GRN "› TO MOVE, USE " CYN "__WASD__\t\t" DEF);
	ft_printf("\t " HCYN "▖▞▙▗" DEF);
	ft_printf("\n" HCYN "▚▛▘▗\t" DEF);
	ft_printf(GRN "  or " CYN "__ARROW KEYS__ \t\t" DEF);
	ft_printf("\t " HCYN "▖▞▙▗" DEF);
	ft_printf("\n\n\n\n" HCYN "▖▞▙▗" DEF "\t\t\t\t\t\t " HCYN "▖▞▙▗" DEF);
	ft_printf("\n" HCYN "▖▞▙▗ \t\t\t\t\t\t ▖▞▙▗" DEF);
	ft_printf("\n" HCYN "▚▛▘▜▝▞▟▙▘▖▞▙▗▚▛▘▜▝▞▟▛▙▘▖▞▙▗▞▙▗▚"
				"▛▘▜▝▞▟▙▘▖▞▙▗▟▙▘▖▞▙▗▚▛▘" DEF);
	ft_printf(YEL "\n\n\tHIT " CYN "__ENTER__" YEL " TO START THE GAME ..." DEF);
	line = get_next_line(1);
	free(line);
	ft_printf("\n\n" DEF);
}

void	main_menu_content(void)
{
	ft_printf(YEL "\n\n\tEAGERNESS ENTERTAINMENT PRESENTS ...\n\n" DEF);
	ft_printf("\n" HCYN "▚▛▘▜▝▞▟▙▘▖▞▙▗▚▛▘▜▝▞▟▛▙▘▖▞▙▗▞▙▗▚"
				"▛▘▜▝▞▟▙▘▖▞▙▗▟▙▘▖▞▙▗▚▛▘" DEF);
	ft_printf("\n" HCYN "▖▞▙▗ \t\t\t\t\t\t ▖▞▙▗" DEF);
	ft_printf("\n" HCYN "▖▞▙▗" DEF "\t\t\t\t\t\t " HCYN "▖▞▙▗" DEF);
	ft_printf("\n" HCYN "▖▞▙▗\t" DEF);
	ft_printf(GRN "› OUR " YEL "BRAND NEW" GRN " HANDHELD: " BLK CYNB " EAGN " DEF);
	ft_printf("\t " HCYN "▖▞▙▗" DEF);
	ft_printf("\n" HCYN "▖▞▙▗" DEF "\t\t\t\t\t\t " HCYN "▖▞▙▗" DEF);
	ft_printf("\n" HCYN "▖▞▙▗\t" DEF);
	ft_printf(GRN "› try it out now with our\t" DEF);
	ft_printf("\t " HCYN "▖▞▙▗" DEF);
	ft_printf("\n" HCYN "▖▞▙▗\t" DEF);
	ft_printf(GRN "  first (and only) game \t" DEF);
	ft_printf("\t " HCYN "▖▞▙▗" DEF);
	ft_printf("\n" HCYN "▖▞▙▗" DEF "\t\t\t\t\t\t " HCYN "▖▞▙▗" DEF);
	ft_printf("\n" HCYN "▖▞▙▗" DEF "\t\t\t\t\t\t " HCYN "▖▞▙▗" DEF);
	ft_printf("\n" HCYN "▖▞▙▗\t" DEF);
	ft_printf(BLK GRNB "› ~ game name ~ \t\t" DEF);
	ft_printf("\t " HCYN "▖▞▙▗" DEF);
	ft_printf("\n" HCYN "▖▞▙▗" DEF "\t\t\t\t\t\t " HCYN "▖▞▙▗" DEF);
	ft_printf("\n" HCYN "▖▞▙▗ \t\t\t\t\t\t ▖▞▙▗" DEF);
	ft_printf("\n" HCYN "▚▛▘▜▝▞▟▙▘▖▞▙▗▚▛▘▜▝▞▟▛▙▘▖▞▙▗▞▙▗▚"
				"▛▘▜▝▞▟▙▘▖▞▙▗▟▙▘▖▞▙▗▚▛▘" DEF);
	ft_printf("\n\n\n\n" HCYN "▚▗▛▘\t" DEF);
}

void	sprite_checker(t_map *map)
{
	int			fd;
	int			i;
	const char	*paths[28] = {BORD, BORDC, BVL, BVLC, SPKR, LOGO, BTN, ARRW,
			EMPTY1, WALL, WALLM, WALLC, EXITC, EXITO, COLT, CHARA1, CHARA2,
			CHARA3, SEMPTY1, SWALL, SWALLM, SWALLC, SEXITC, SEXITO, SCOLT,
			SCHARA1, SCHARA2, SCHARA3};

	i = -1;
	while (++i < 28)
	{
		fd = open(paths[i], O_RDONLY);
		if (fd > 2)
			close(fd);
		else
		{
			map->error = 8;
			error_exit(map->error, map);
		}
	}
}

void	game_start(t_map *map)
{
	t_game	*game;

	set_game(&game, map);
	put_border(game, map);
	fill_gap(game);
	put_bevel(game);
	put_corner(game, game->size);
	add_decor(game);
	put_map(game, map);
	mlx_loop_hook(game->mlx, render_game, game);
	mlx_hook(game->win, 17, 0, close_x, game);
	mlx_hook(game->win, 2, (1L << 0), player_move, game);
	mlx_loop(game->mlx);
}
