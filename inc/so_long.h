/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:31:49 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/01/10 22:09:19 by rduro-pe         ###   ########.fr       */
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
# define EMPTY "./assests/empty.xpm"
# define WALLV "./assests/wall_v.xpm"
# define WALLH "./assests/wall_h.xpm"
# define COLT "./assests/colt.xpm"
# define EXITC "./assests/exit_c.xpm"
# define EXITO "./assests/exit_o.xpm"
# define CHARA "./assests/player.xpm"
# define BORD "./assests/border.xpm"
# define BORDV "./assests/border_v.xpm"
# define BORDH "./assests/border_h.xpm"
# define BORDC "./assests/border_c.xpm"

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

typedef struct s_sprt
{
	void	*empty;
	void	*wall_v;
	void	*wall_h;
	void	*colt;
	void	*exit_c;
	void	*exit_o;
	void	*chara;
	void	*bord;
	void	*bord_v;
	void	*bord_h;
	void	*bord_c;
}			t_sprt;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_sprt	*sprite;
}			t_game;

// TBD
void		game_start(t_map *map);
int			key_win1(int key, void *p);
void		make_grid(char *addr, int line_length, int bits_per_pixel);

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
void		img_destroyer(t_game *game, t_map *map);
// -game destroyer
// -game free exit

#endif