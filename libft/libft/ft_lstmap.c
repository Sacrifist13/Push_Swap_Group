/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 10:30:52 by kkraft            #+#    #+#             */
/*   Updated: 2025/12/11 15:28:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_map;

	lst_map = NULL;
	if (lst == NULL)
		return (NULL);
	while (lst != NULL)
	{
		ft_lstadd_back(&lst_map, ft_lstnew(f(lst->content)));
		if (lst_map == NULL)
		{
			ft_lstclear(&lst_map, del);
			return (NULL);
		}
		lst = lst->next;
	}
	return (lst_map);
}
