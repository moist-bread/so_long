/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:30:41 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/12/27 16:13:43 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
int	main(void)
{
	char	array1[] = "mau dia";
	char	*array2;

	array2 = "bom dia";
	printf("%s(before)", array1);
	ft_memmove((void *)&array1[4], (const void *)array1, 3);
	printf("%s(after)", array1);
}
*/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int				i;
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (d < s && (s || d))
	{
		i = 0;
		while (i < (int)n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else if (s || d)
	{
		i = (int)n - 1;
		while (i >= 0)
		{
			d[i] = s[i];
			i--;
		}
	}
	return (dest);
}
