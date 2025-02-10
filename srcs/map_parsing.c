/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:38:04 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/02/10 15:31:51 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	map_parsing(char *map_file, t_map **map)
{
	int	map_fd;

	*map = set_map_struct();
	if (!*map)
		return (error_exit(1, *map), 1);
	map_fd = open(map_file, O_RDONLY);
	if (map_fd < 3 || ft_strncmp(".ber", map_file + ft_strlen(map_file) - 4, 4))
		return (close(map_fd), error_exit(2, *map), 2);
	row_check(map_fd, *map);
	close(map_fd);
	if ((*map)->heigth <= 2 || (*map)->width <= 2 || (*map)->error)
		return (error_exit(3, *map), 3);
	if ((*map)->heigth > 22 || (*map)->width > 38)
		return (error_exit(3, *map), 3);
	map_fd = open(map_file, O_RDONLY);
	if (make_map(map_fd, *map))
		return (close(map_fd), error_exit(1, *map), 1);
	map_full_check(*map);
	if (!close(map_fd) && (*map)->error)
		return (error_exit((*map)->error, *map), 4);
	return (0);
}

void	row_check(int fd, t_map *map)
{
	char	*map_row;

	while (!map->error)
	{
		map_row = get_next_line(fd);
		if (!map_row)
			break ;
		if (map->heigth == 0)
			map->width = row_len(map_row);
		else if (map->width != row_len(map_row))
			map->error = 3;
		map->heigth++;
		free(map_row);
	}
}

int	row_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

void	valid_path_check(int seen_colt, t_map *map)
{
	if (seen_colt != map->colt || (map->map[map->exit_cord.y
				+ 1][map->exit_cord.x] != 'O' && map->map[map->exit_cord.y
			+ 1][map->exit_cord.x] != 'c' && map->map[map->exit_cord.y
			+ 1][map->exit_cord.x] != 'P' && map->map[map->exit_cord.y
			- 1][map->exit_cord.x] != 'O' && map->map[map->exit_cord.y
			- 1][map->exit_cord.x] != 'c' && map->map[map->exit_cord.y
			- 1][map->exit_cord.x] != 'P'
			&& map->map[map->exit_cord.y][map->exit_cord.x + 1] != 'O'
			&& map->map[map->exit_cord.y][map->exit_cord.x + 1] != 'c'
			&& map->map[map->exit_cord.y][map->exit_cord.x + 1] != 'P'
			&& map->map[map->exit_cord.y][map->exit_cord.x - 1] != 'O'
			&& map->map[map->exit_cord.y][map->exit_cord.x - 1] != 'c'
			&& map->map[map->exit_cord.y][map->exit_cord.x - 1] != 'P'))
		map->error = 7;
}

// error meanings ~
// 1: malloc problems
// 2: incorrect file input
// 3: map not rectangle or too short or too big
// 4: no surrounding walls
// 5: invalid characters
// 6: duplicates or no colt
// 7: no path
// 8: missing sprites

void	error_exit(int ret, t_map *map)
{
	ft_printf("Error\n");
	if (ret == 1)
		ft_printf("\nMemory Allocation failed\n");
	else if (ret == 2)
		ft_printf("\nGiven file isn't .ber and or doesn't exists\n");
	else if (map->heigth <= 2)
		ft_printf("\nGiven Map doesn't have enough rows or columns\n");
	else if (map->heigth > 22 || map->width > 38)
		ft_printf("\nGiven Map is too big (limit of 38x22)\n");
	else if (ret == 3)
		ft_printf("\nGiven Map isn't rectangular\n");
	else if (ret == 4)
		ft_printf("\nGiven Map doesn't have surrounding walls\n");
	else if (ret == 5)
		ft_printf("\nGiven Map contains invalid characters\n");
	else if (ret == 6)
		ft_printf("\nGiven Map contains incorrect amount of elements\n");
	else if (ret == 7)
		ft_printf("\nGiven Map has no valid path\n");
	else if (ret == 8)
		ft_printf("\nMissing sprites, can't game :(\n");
	if (map->error || map->heigth <= 2)
		free_map(map, map->heigth);
	exit(ret);
}
