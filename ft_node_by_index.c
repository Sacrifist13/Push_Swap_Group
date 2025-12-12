/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_by_index.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraft <kkraft@student42>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:01:06 by kkraft            #+#    #+#             */
/*   Updated: 2025/12/12 09:13:57 by kkraft           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.h"

t_node	*ft_node_by_index(t_node *stack, int index)
{
	t_node	*tmp;

	if (!stack)
		return (NULL);
	tmp = stack;
	while (tmp != NULL)
	{
		if (tmp->index == index)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
