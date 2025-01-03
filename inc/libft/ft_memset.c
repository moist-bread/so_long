/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:30:44 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/12/27 16:13:48 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
int	main(void)
{
	void	*string[21];
	char	*result;

	result = (char	*)ft_memset(string, 'A', 5);
	printf("return: %s \n", result);
	result = (char	*)ft_memset(string, 'B', 10);
	printf("return: %s \n", result);
	result = (char	*)ft_memset(string, 'C', 15);
	printf("return: %s \n", result);
	result = (char	*)ft_memset(string, 'D', 20);
	printf("return: %s \n", result);
	return (0);
}
*/

void	*ft_memset(void *dest, int filler, size_t n)
{
	size_t			i;
	unsigned char	*d;

	i = 0;
	d = (unsigned char *)dest;
	while (i < n)
		d[i++] = filler;
	return (dest);
}
