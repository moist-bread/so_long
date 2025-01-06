/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:15:33 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/01/06 16:57:47 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"



int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
		return (1);
	if (map_parsing(argv[1], &map))
		return(1);
	free_map(map, map->heigth);
	return (0);
}

// error meanings ~
// 1: malloc problems
// 2: incorrect file input
// 3: map format

int	map_parsing(char *map_file, t_map **map)
{
	int	map_fd;

	map_fd = open(map_file, O_RDONLY);
	//		checks if file exists and if it's .ber
	if (map_fd < 3 || ft_strncmp(".ber", map_file + ft_strlen(map_file) - 4, 4))
		return (close(map_fd), 2);
	*map = set_map_struct();
	if (!*map)
		return (close(map_fd), 1);
	//		gives map heigth and if theyre all the same len
	row_check(map_fd, *map); // make it return in case of malloc error
	close(map_fd);
	if ((*map)->heigth <= 2 || (*map)->error)
		return (3);
	map_fd = open(map_file, O_RDONLY);
	make_map(map_fd, *map); // make it return in case of malloc error
	map_comp_check(*map);
	if ((*map)->error)
		return (3);
	close(map_fd);
	return (0);
}

void map_comp_check(t_map *map)
{
	int i;

	i = 0;
	map->map[i];
	
}

void	make_map(int fd, t_map *map)
{
	char	*map_row;
	int		i;

	i = -1;
	map->map = malloc((map->heigth + 1) * sizeof(char *));
	if (!map)
		return ;
	while (++i < map->heigth)
	{
		map_row = get_next_line(fd);
		if (!map_row)
			break ;
		map->map[i] = map_row;
	}
	map->map[i] = NULL;
	print_map(map);
}

void	free_map(t_map *map, int max)
{
	int	i;

	i = 0;
	while (i <= max)
		free(map->map[i++]);
	free(map->map);
	free(map);
}

void	print_map(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->heigth)
		ft_printf("map_row %d: %s\n", i, map->map[i]);
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
			map->error++;
		map->heigth++;
		// ft_printf("%d, %d\n", map->width, row_len(map_row));
		// ft_printf("map_row %d: %s", map->heigth, map_row);
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

t_map	*set_map_struct(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->map = NULL;
	map->empty = 0;
	map->wall = 0;
	map->colt = 0;
	map->exit = 0;
	map->ps = 0;
	map->heigth = 0;
	map->width = 0;
	map->error = 0;
	return (map);
}
