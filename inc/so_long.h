/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:31:49 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/01/06 16:48:55 by rduro-pe         ###   ########.fr       */
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

// STRUCTS
typedef struct s_map
{
	char	**map;
	int		empty;
	int		wall;
	int		colt;
	int		exit;
	int		ps;
	int		heigth;
	int		width;
	int		error;
}			t_map;

// TBD
int			map_parsing(char *map_file, t_map **map);
void		row_check(int fd, t_map *map);
t_map		*set_map_struct(void);
void		print_map(t_map *map);
void		make_map(int fd, t_map *map);
int			row_len(char *str);
void		free_map(t_map *map, int max);

#endif