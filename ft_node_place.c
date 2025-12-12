/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_place.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraft <kkraft@student42>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 10:26:09 by kkraft            #+#    #+#             */
/*   Updated: 2025/12/12 09:13:57 by kkraft           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.h"

t_node	*ft_node_place(t_node *stack, int index)
{
	t_node	*node_place;

	if (!stack)
		return (NULL);
	if (index > ft_max_index(stack))
		node_place = ft_node_by_index(stack, ft_max_index(stack));
	else if (index < ft_min_index(stack))
	{
		node_place = ft_node_by_index(stack, ft_min_index(stack));
		if (node_place->next)
			node_place = node_place->next;
		else
			node_place = stack;
	}
	else
		node_place = ft_node_by_index(stack, ft_closer_index(stack, index));
	return (node_place);
}

t_node	*ft_node_place_sub(t_node *stack, int index)
{
	t_node	*node_place;

	if (!stack)
		return (NULL);
	if (index < ft_min_index(stack))
		node_place = ft_node_by_index(stack, ft_min_index(stack));
	else if (index > ft_max_index(stack))
	{
		node_place = ft_node_by_index(stack, ft_max_index(stack));
		if (node_place->next)
			node_place = node_place->next;
		else
			node_place = stack;
	}
	else
		node_place = ft_node_by_index(stack, ft_closer_index_sub(stack, index));
	return (node_place);
}
