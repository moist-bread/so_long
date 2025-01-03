/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:36:35 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/12/27 16:13:23 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
int main (void)
{
	char	*t3;
	char	*t2;
	char	*t1;
	t_list	*last;
	t_list	*secon;
	t_list	*first;
	t_list	**list;
	int		i;

	t3 = "last";
	t2 = "secon";
	t1 = "first";
	last = ft_lstnew((void *)t3);
	secon = ft_lstnew((void *)t2);
	first = ft_lstnew((void *)t1);
	list = &last;
	ft_lstadd_front(list, secon);
	ft_lstadd_front(list, first);
	i = 1;
	while((*list)->next != NULL)
	{
		printf("%s(content %d)\n", (char *)(*list)->content, i);
		i++;
		*list = (*list)->next;
	}
	printf("%s(content %d)\n", (char *)(*list)->content, i);
	printf("%d(list size)\n", ft_lstsize(first));
	return(0);
}
*/

int	ft_lstsize(t_list *lst)
{
	int	size;

	if (lst == NULL)
		return (0);
	size = 0;
	while (lst->next != NULL)
	{
		size++;
		lst = lst->next;
	}
	return (++size);
}
