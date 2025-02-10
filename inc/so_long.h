/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:31:49 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/02/10 16:00:18 by rduro-pe         ###   ########.fr       */
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

// universal asset paths
# define BORD "./textures/border.xpm"
# define BORDC "./textures/border_c.xpm"
# define BVL "./textures/bevel.xpm"
# define BVLC "./textures/bevel_c.xpm"
# define SPKR "./textures/speaker.xpm"
# define LOGO "./textures/logo.xpm"
# define BTN "./textures/button.xpm"
# define ARRW "./textures/arrow.xpm"

// big asset paths
# define EMPTY1 "./textures/big/empty_1.xpm"
# define WALL "./textures/big/wall.xpm"
# define WALLM "./textures/big/wall_m.xpm"
# define WALLC "./textures/big/wall_c.xpm"
# define EXITC "./textures/big/exit_c.xpm"
# define EXITO "./textures/big/exit_o.xpm"
# define COLT "./textures/big/colt.xpm"
# define CHARA1 "./textures/big/chara_1.xpm"
# define CHARA2 "./textures/big/chara_2.xpm"
# define CHARA3 "./textures/big/chara_3.xpm"

// small asset paths
# define SEMPTY1 "./textures/small/empty_1.xpm"
# define SWALL "./textures/small/wall.xpm"
# define SWALLM "./textures/small/wall_m.xpm"
# define SWALLC "./textures/small/wall_c.xpm"
# define SEXITC "./textures/small/exit_c.xpm"
# define SEXITO "./textures/small/exit_o.xpm"
# define SCOLT "./textures/small/colt.xpm"
# define SCHARA1 "./textures/small/chara_1.xpm"
# define SCHARA2 "./textures/small/chara_2.xpm"
# define SCHARA3 "./textures/small/chara_3.xpm"

// colors
# define TRANSPARENT 0xFF000000
# define DEF "\e[0m"

# define YEL "\e[0;33m"
# define GRN "\e[0;32m"
# define CYN "\e[0;36m"
# define BLK "\e[0;30m"
# define HCYN "\e[0;96m"

// backgrounds
# define CYNB "\e[46m"
# define GRNB "\e[42m"

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
	t_data	*wall;
	t_data	*wall_m;
	t_data	*wall_c;
	t_data	*exit_c;
	t_data	*exit_o;
	t_data	*colt;
	t_data	*chara_1;
	t_data	*chara_2;
	t_data	*chara_3;
}			t_sprt;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	int		offset;
	int		gap;
	int		size;
	int		collected;
	int		chara_dir;
	t_sprt	*sprite;
	t_data	*bg;
	t_map	*map;
}			t_game;

// TBD

// MAIN
void		sprite_checker(t_map *map);
void		game_start(t_map *map);

// MESSAGES
void		main_menu(char *input);
void		main_menu_content(void);
void		main_menu_instruct(char *input);
void		exit_message(int type);

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
void		set_sprites_small(t_game *game, int gap);
void		set_sprites_both(t_game *game, int gap);

// MAKE DATA
void		make_sprite_data(t_game *game);
void		data_making_checker(t_game *game, int type);
void		get_sprite_data_bg(t_game *game);
void		get_sprite_data_fg(t_game *game);
void		get_sprite_data_extra(t_game *game);

// DESTROYERS
void		game_destroyer(t_game *game, t_map *map, int status);
void		img_destroyer(t_game *game);
void		img_fg_destroyer(t_game *game);
void		sprite_destroyer(t_game *game);
void		sprite_fg_destroyer(t_game *game);

// MAKE BG
void		put_border(t_game *game, t_map *map);
void		fill_gap(t_game *game);
void		put_bevel(t_game *game);
void		put_corner(t_game *game, int size);
void		assign_xy(t_game *game, int *x, int *y, int zone);

// MAKE FG
void		add_decor(t_game *game);
void		put_map(t_game *game, t_map *map);
void		put_sprite(t_game *game, int y, int x, int type);
void		wall_selector(t_game *game, int y, int x);

// SPRITE TO BG
void		sprite_to_bg(t_game *game, t_data *sprite, t_cord sprt, t_cord win);
void		sprite_to_bg_vflip(t_game *game, t_data *sprite, t_cord sprt,
				t_cord win);
void		sprite_to_bg_hflip(t_game *game, t_data *sprite, t_cord sprt,
				t_cord win);
void		sprite_to_bg_rotr(t_game *game, t_data *sprite, t_cord sprt,
				t_cord win);
void		sprite_to_bg_rotl(t_game *game, t_data *sprite, t_cord sprt,
				t_cord win);

// SPRITE TO HELPERS
void		sprite_to_bg_mirr(t_game *game, t_data *sprite, t_cord sprt,
				t_cord win);
void		colorblock_to_bg(t_game *game, int color, t_cord sprt, t_cord win);
int			get_pixel(t_data *data, int x, int y);
void		put_pixel(t_data *data, int x, int y, int color);

// LOOP
int			render_game(t_game *game);
void		player_sprite_selector(t_game *game);
int			player_move(int key, t_game *game);
void		move_check(t_game *game, int axis, int dir, int key);
int			close_x(t_game *game);

#endif