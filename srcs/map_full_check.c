/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_full_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:40:45 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/01/13 14:40:02 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	map_full_check(t_map *map)
{
	map_wall_check(map);
	if (map->error)
		return ;
	map_elem_count(map);
	print_map_elems(map);
	if (map->error)
		return ;
	valid_path_check(map_flood_fill(map->ps_cord.y, map->ps_cord.x, map), map);
	if (map->error)
		return ;
	print_map(map);
	ft_printf("if there's a will there's a way\n\n");
}

void	map_wall_check(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->width && !map->error)
		if (map->map[0][i] != '1' || map->map[map->heigth - 1][i] != '1')
			map->error = 4;
	i = 0;
	while (++i < map->heigth - 1 && !map->error)
		if (map->map[i][0] != '1' || map->map[i][map->width - 1] != '1')
			map->error = 4;
}

void	map_elem_count(t_map *map)
{
	int	i;
	int	j;

	j = 0;
	while (++j < map->heigth - 1 && !map->error)
	{
		i = 0;
		while (++i < map->width - 1 && !map->error)
		{
			if (map->map[j][i] == '0')
				map->empty++;
			else if (map->map[j][i] == '1')
				map->walls++;
			else if (map->map[j][i] == 'C')
				map->colt++;
			else if (map->map[j][i] == 'E')
				is_e_or_ps(j, i, map, 'E');
			else if (map->map[j][i] == 'P')
				is_e_or_ps(j, i, map, 'P');
			else
				map->error = 5;
		}
	}
	if (!map->error && (map->colt == 0 || map->exit != 1 || map->ps != 1))
		map->error = 6;
}

void	is_e_or_ps(int y, int x, t_map *map, int type)
{
	if (type == 'E')
	{
		map->exit++;
		map->exit_cord.y = y;
		map->exit_cord.x = x;
	}
	else
	{
		map->ps++;
		map->ps_cord.y = y;
		map->ps_cord.x = x;
	}
}

int	map_flood_fill(int y, int x, t_map *map)
{
	int	colt;

	// ft_printf("flooding the fill\n");
	if (y < 1 || y >= map->heigth - 1 || x < 1 || x >= map->width - 1
		|| (map->map[y][x] != '0' && map->map[y][x] != 'C'
			&& map->map[y][x] != 'P'))
		return (0);
	colt = 0;
	if (map->map[y][x] == 'C')
	{
		map->map[y][x] = 'c';
		colt++;
	}
	else if (map->map[y][x] == '0')
		map->map[y][x] = 'O';
	colt += map_flood_fill(y + 1, x, map);
	colt += map_flood_fill(y - 1, x, map);
	colt += map_flood_fill(y, x - 1, map);
	colt += map_flood_fill(y, x + 1, map);
	return (colt);
}
