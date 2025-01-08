/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:05:32 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/01/08 13:05:45 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_map	*set_map_struct(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->map = NULL;
	map->empty = 0;
	map->walls = 0;
	map->colt = 0;
	map->exit = 0;
	map->exit_cord.y = 0;
	map->exit_cord.x = 0;
	map->ps = 0;
	map->ps_cord.y = 0;
	map->ps_cord.x = 0;
	map->heigth = 0;
	map->width = 0;
	map->error = 0;
	return (map);
}

int	make_map(int fd, t_map *map)
{
	char	*map_row;
	int		i;

	i = -1;
	map->map = malloc((map->heigth + 1) * sizeof(char *));
	if (!map)
		return (1);
	while (++i < map->heigth)
	{
		map_row = get_next_line(fd);
		if (!map_row)
			break ;
		map->map[i] = map_row;
	}
	map->map[i] = NULL;
	print_map(map);
	return (0);
}

void	free_map(t_map *map, int max)
{
	int	i;

	i = 0;
	if (map->error != 1 && map->heigth > 2)
	{
		while (i <= max)
			free(map->map[i++]);
		free(map->map);
	}
	free(map);
}

void	print_map(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->heigth)
		ft_printf("map_row %d: %s", i, map->map[i]);
	ft_printf("\n\n");
}

void	print_map_elems(t_map *map)
{
	ft_printf("map->empty: %d\n", map->empty);
	ft_printf("map->walls: %d\n", map->walls);
	ft_printf("map->colt: %d\n", map->colt);
	ft_printf("map->exit: %d\n", map->exit);
	ft_printf("map->exit_cord.y: %d\n", map->exit_cord.y);
	ft_printf("map->exit_cord.x: %d\n", map->exit_cord.x);
	ft_printf("map->ps: %d\n", map->ps);
	ft_printf("map->ps_cord.y: %d\n", map->ps_cord.y);
	ft_printf("map->ps_cord.x: %d\n", map->ps_cord.x);
	ft_printf("map->heigth: %d\n", map->heigth);
	ft_printf("map->width: %d\n", map->width);
	ft_printf("map->error: %d\n\n", map->error);
}
