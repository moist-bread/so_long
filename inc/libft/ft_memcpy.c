/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:30:38 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/12/27 16:13:39 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
int	main(void)
{
	char	array1[] = "mau dia";
	char	array2[] = "bom dia";

	printf("%s(before)", array1);
	ft_memcpy(array1, array2, 3);
	printf("%s(after)", array1);
}
*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	i = 0;
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	while (i < n && (s || d))
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
