/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:31:49 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/01/03 13:00:29 by rduro-pe         ###   ########.fr       */
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
typedef struct s_stacks
{
	int		*a;
	int		atop_id;
	int		*b;
	int		btop_id;
}			t_stacks;

// TBD


#endif