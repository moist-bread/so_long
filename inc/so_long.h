/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:31:49 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/01/17 15:32:10 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// LIBS
# include "libft/libft.h"
# include "minilibx_linux/mlx.h"
# include "minilibx_linux/mlx_int.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// DEFINES
// big asset paths
# define EMPTY "./assets/big/empty.xpm"
# define WALLV "./assets/big/wall_v.xpm"
# define WALLH "./assets/big/wall_h.xpm"
# define COLT "./assets/big/colt.xpm"
# define EXITC "./assets/big/exit_c.xpm"
# define EXITO "./assets/big/exit_o.xpm"
# define CHARA "./assets/big/player.xpm"
# define BORD "./assets/big/border.xpm"
# define BORDV "./assets/big/border_v.xpm"
# define BORDH "./assets/big/border_h.xpm"
# define BORDC "./assets/big/border_c.xpm"

// small asset paths
# define SEMPTY "./assets/small/empty.xpm"
# define SWALLV "./assets/small/wall_v.xpm"
# define SWALLH "./assets/small/wall_h.xpm"
# define SCOLT "./assets/small/colt.xpm"
# define SEXITC "./assets/small/exit_c.xpm"
# define SEXITO "./assets/small/exit_o.xpm"
# define SCHARA "./assets/small/player.xpm"
# define SBORD "./assets/small/border.xpm"
# define SBORDV "./assets/small/border_v.xpm"
# define SBORDH "./assets/small/border_h.xpm"
# define SBORDC "./assets/small/border_c.xpm"

# define TRANSPARENT 0xFF000000 // MAKE IT CHROMA KEY

// STRUCTS
typedef struct s_cord
{
	int		y;
	int		x;
}			t_cord;

typedef struct s_map
{
	char	**map;
	int		empty;
	int		walls;
	int		colt;
	int		exit;
	t_cord	exit_cord;
	int		ps;
	t_cord	ps_cord;
	int		heigth;
	int		width;
	int		error;
}			t_map;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		len;
	int		endian;
}			t_data;

typedef struct s_sprt
{
	t_data	*empty;
	t_data	*wall_v;
	t_data	*wall_h;
	t_data	*colt;
	t_data	*exit_c;
	t_data	*exit_o;
	t_data	*chara;
	t_data	*bord;
	t_data	*bord_v;
	t_data	*bord_h;
	t_data	*bord_c;
}			t_sprt;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	int		offset;
	int		spr_size;
	int		collected;
	t_sprt	*sprite;
	t_data	*bg;
	t_data	*fg;
	t_map	*map;
}			t_game;

// TBD
void		put_in_border(t_game *game);
void		gap_to_bg_img_h(t_game *game, t_data *sprite, int x, int y);

// MAIN
void		game_start(t_map *map);

// MAP PARSING
int			map_parsing(char *map_file, t_map **map);
void		row_check(int fd, t_map *map);
int			row_len(char *str);
void		valid_path_check(int seen_colt, t_map *map);
void		error_exit(int ret, t_map *map);

// MAKE MAP
t_map		*set_map_struct(void);
int			make_map(int fd, t_map *map);
void		free_map(t_map *map, int max);
void		print_map(t_map *map);
void		print_map_elems(t_map *map);

// MAP FULL CHECK
void		map_full_check(t_map *map);
void		map_wall_check(t_map *map);
void		map_elem_count(t_map *map);
void		is_e_or_ps(int y, int x, t_map *map, int type);
int			map_flood_fill(int y, int x, t_map *map);

// SET GAME
int			set_game(t_game **game, t_map *map);
void		set_assets(t_game *game, t_map *map);
void		set_imgs(t_game *game, t_map *map);

// SET SPRITES
void		set_sprites_bg_big(t_game *game, int gap);
void	set_sprites_fg_big(t_game *game, int gap); // to be made
void		set_sprites_bg_small(t_game *game, int gap);
void	set_sprites_fg_small(t_game *game, int gap); // to be made

// MAKE DATA
void		make_sprite_data(t_game *game, t_map *map);
void		get_sprite_data_bg(t_game *game);
void	get_sprite_data_fg(t_game *game); // to be made

// DESTROYERS
// - destroy check
void		img_destroyer(t_game *game);
void		game_destroyer(t_game *game, t_map *map);
// -game free exit

// MAKE BG
void		put_border(t_game *game, t_map *map);
void		put_corner(t_game *game);
void		put_map(t_game *game, t_map *map);
void		put_sprite(t_game *game, int y, int x, int type);
void		put_fg(t_game *game, int y, int x, int type);

// SPRITE TO BG
void		sprite_to_bg_img(t_game *game, t_data *sprite, int x, int y);
void		sprite_to_bg_img_hflip(t_game *game, t_data *sprite, int x, int y);
void		sprite_to_bg_img_vflip(t_game *game, t_data *sprite, int x, int y);
void		sprite_to_bg_img_rotr(t_game *game, t_data *sprite, int x, int y);
void		sprite_to_bg_img_rotl(t_game *game, t_data *sprite, int x, int y);

// SPRITE TO HELPERS
int			get_pixel(t_data *data, int x, int y);
void		put_pixel(t_data *data, int x, int y, int color);
void		gap_to_bg_img(t_game *game, t_data *sprite, int x, int y);
void		sprite_to_fg_img(t_game *game, t_data *sprite, int x, int y);

// LOOP
int			put_player(t_game *game);
int			player_move(int key, t_game *game);
void		move_check(t_game *game, int axis, int dir);

// TESTS
void		game_stort_test(t_map *map);
void		game_stort_test2(t_map *map);
void		make_square(char *addr, int line_length, int bits_per_pixel);
void		make_grid(char *addr, int line_length, int bits_per_pixel);
void		my_mlx_pixel_put(char *addr, int line_length, int bits_per_pixel,
				int y, int x, int color);
int			key_win1(int key, void *p);

#endif