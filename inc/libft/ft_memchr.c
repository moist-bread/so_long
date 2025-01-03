/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:30:54 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/12/27 16:13:30 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
int	main(void)
{
	char	s[] = {0, 1, 2 ,3 ,4 ,5};
	int		character;

	//char	*string;
	//string = "tripouille";
	character = 'a';
	//printf("original: %s\npin: %c\nsearch result: %s\n", string, 't' + 256,
	//	(char *)ft_memchr((const void *)string, 't' + 256, 3));
	printf("original: %s\npin: %i\nsearch result: %s\n", s, 0,
		(char *)ft_memchr((const void *)s, 0, 0));
	return (0);
}
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((void *)&str[i]);
		i++;
	}
	return (0);
}
