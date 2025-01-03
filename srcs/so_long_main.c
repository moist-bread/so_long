/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:15:33 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/01/03 17:29:59 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int map_parsing(char *map_file, t_map **map);
void row_check(int fd, t_map *map);
t_map *set_map_struct(void);

int main (int argc, char **argv)
{
	t_map *map;
	
	if (argc != 2)
		return(1);
	map_parsing(argv[1], &map);
	return(0);
}

int map_parsing(char *map_file, t_map **map)
{
	int map_fd;

	*map = set_map_struct();
	if (!*map)
		return(0);
	map_fd = open(map_file, O_RDONLY);
	row_check(map_fd, *map);
	close(map_fd);
	if((*map)->heigth <= 2 || (*map)->error)
		return(0);
	map_fd = open(map_file, O_RDONLY);

	close(map_fd);
	return(1);
}

void row_check(int fd, t_map *map)
{
	char *map_row;
	int end_flag;

	end_flag = 0;
	while(!map->error)
	{
		map_row = get_next_line(fd);
		if (!map_row)
			break;
		if(map->heigth == 0)
			map->width = ft_strlen(map_row);
		else if (map->width != ft_strlen(map_row))
			map->error++;
		map->heigth++;
		ft_printf("map_row %d: %s", map->heigth, map_row);
		free(map_row);
	}
}

t_map *set_map_struct(void)
{
	t_map *map;

	map = malloc(sizeof(t_map));
	if (!map)
		return(NULL);
	map->map = NULL;
	map->empty = 0;
	map->wall = 0;
	map->colt = 0;
	map->exit = 0;
	map->ps = 0;
	map->heigth = 0;
	map->width = 0;
	map->error = 0;
	return(map);
}
