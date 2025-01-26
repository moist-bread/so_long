/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:31:49 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/01/26 17:48:54 by rduro-pe         ###   ########.fr       */
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
// big bg
# define BORD "./textures/big/border.xpm"
# define BORDC "./textures/big/border_c.xpm"
# define BVL "./textures/big/bevel.xpm"
# define BVLC "./textures/big/bevel_c.xpm"
# define SPKR "./textures/big/speaker.xpm"
# define LOGO "./textures/big/logo.xpm"
# define BTN "./textures/big/button.xpm"
# define ARRW "./textures/big/arrow.xpm"

// big fg
# define EMPTY1 "./textures/big/empty_1.xpm"
# define EMPTY2 "./textures/big/empty_2.xpm"
# define WALL "./textures/big/wall.xpm"
# define WALLM "./textures/big/wall_m.xpm"
# define WALLC "./textures/big/wall_c.xpm"
# define EXITC "./textures/big/exit_c.xpm"
# define EXITO "./textures/big/exit_o.xpm"
# define COLT "./textures/big/colt.xpm"
# define CHARA1 "./textures/big/chara_1.xpm"
# define CHARA2 "./textures/big/chara_2.xpm"

// small asset paths
// small bg
# define SBORD "./textures/small/border.xpm"
# define SBORDC "./textures/small/border_c.xpm"
# define SBVL "./textures/small/bevel.xpm"
# define SBVLC "./textures/small/bevel_c.xpm"
# define SSPKR "./textures/small/speaker.xpm"
# define SLOGO "./textures/small/logo.xpm"
# define SBTN "./textures/small/button.xpm"
# define SARRW "./textures/small/arrow.xpm"

// small fg
# define SEMPTY1 "./textures/small/empty_1.xpm"
# define SEMPTY2 "./textures/small/empty_2.xpm"
# define SWALL "./textures/small/wall.xpm"
# define SWALLM "./textures/small/wall_m.xpm"
# define SWALLC "./textures/small/wall_c.xpm"
# define SEXITC "./textures/small/exit_c.xpm"
# define SEXITO "./textures/small/exit_o.xpm"
# define SCOLT "./textures/small/colt.xpm"
# define SCHARA1 "./textures/small/chara_1.xpm"
# define SCHARA2 "./textures/small/chara_2.xpm"

# define TRANSPARENT 0xFF000000

// STRUCTS
typedef struct s_cord
{
	int		x;
	int		y;
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
	t_data	*bord;
	t_data	*bord_c;
	t_data	*bevel;
	t_data	*bevel_c;
	t_data	*speaker;
	t_data	*logo;
	t_data	*button;
	t_data	*arrow;
	t_data	*empty_1;
	t_data	*empty_2;
	t_data	*wall;
	t_data	*wall_m;
	t_data	*wall_c;
	t_data	*exit_c;
	t_data	*exit_o;
	t_data	*colt;
	t_data	*chara_1;
	t_data	*chara_2;
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
void		new_sprite_to_bg(t_game *game, t_data *sprite, t_cord sprt,
				t_cord win);

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
void		set_assets(t_game *game);
void		set_imgs(t_game *game);

// SET SPRITES
void		set_sprites_big(t_game *game, int gap);
void		set_sprites_fg_big(t_game *game);
void		set_sprites_small(t_game *game, int gap);
void		set_sprites_fg_small(t_game *game);

// MAKE DATA
void		make_sprite_data(t_game *game);
void		data_making_checker(t_game *game, int type);
void		get_sprite_data_bg(t_game *game);
void		get_sprite_data_fg(t_game *game);
void		get_sprite_data_extra(t_game *game);

// DESTROYERS
void		game_destroyer_3000(t_game *game, t_map *map, int status);
void		img_destroyer(t_game *game);
void		img_fg_destroyer(t_game *game);
void		sprite_destroyer(t_game *game);
void		sprite_fg_destroyer(t_game *game);

// MAKE FG
void		put_map(t_game *game, t_map *map);
void		put_sprite(t_game *game, int y, int x, int type);

// MAKE BG
void		put_border(t_game *game, t_map *map);
void		put_bevel(t_game *game);
void		put_corner(t_game *game, int size);
void		fill_gap(t_game *game);
void		add_decor(t_game *game);

// SPRITE TO BG
void		sprite_to_bg(t_game *game, t_data *sprite, int x, int y);
void		sprite_to_bg_hflip(t_game *game, t_data *sprite, int x, int y);
void		sprite_to_bg_vflip(t_game *game, t_data *sprite, int x, int y);
void		sprite_to_bg_rotr(t_game *game, t_data *sprite, int x, int y);
void		sprite_to_bg_rotl(t_game *game, t_data *sprite, int x, int y);
void		sprite_to_bg_mirr(t_game *game, t_data *sprite, int x, int y);

// sim, há mais
void		gap_to_bg_h(t_game *game, t_data *sprite, int x, int y);
void		gap_to_bg_hflip(t_game *game, t_data *sprite, int x, int y);
void		gap_to_bg_h_vflip(t_game *game, t_data *sprite, int x, int y);
void		corn_to_bg(t_game *game, t_data *sprite, int x, int y);
void		square_to_bg(t_game *game, int color, int x, int y);
void		rectangle_to_bg(t_game *game, int color, int x, int y);

// SPRITE TO HELPERS
int			get_pixel(t_data *data, int x, int y);
void		put_pixel(t_data *data, int x, int y, int color);
void		gap_to_bg(t_game *game, t_data *sprite, int x, int y);
void		sprite_to_fg(t_game *game, t_data *sprite, int x, int y);

// LOOP
int			render_game(t_game *game);
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