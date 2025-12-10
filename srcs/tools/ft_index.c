/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraft <kkraft@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 18:31:46 by kkraft            #+#    #+#             */
/*   Updated: 2025/11/23 18:31:46 by kkraft           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/common.h"

int	ft_closer_index(t_node *stack, int index)
{
	t_node	*tmp;
	int		closer_index;
	int		gap;

	if (!stack)
		return (-1);
	gap = INT_MAX_VALUE;
	tmp = stack;
	while (tmp != NULL)
	{
		if (tmp->index < index)
		{
			if (index - tmp->index < gap)
			{
				gap = index - tmp->index;
				closer_index = tmp->index;
			}
		}
		tmp = tmp->next;
	}
	return (closer_index);
}

int	ft_closer_index_sub(t_node *stack, int index)
{
	t_node	*tmp;
	int		closer_index;
	int		gap;

	if (!stack)
		return (-1);
	gap = INT_MAX_VALUE;
	tmp = stack;
	while (tmp != NULL)
	{
		if (tmp->index > index)
		{
			if (tmp->index - index < gap)
			{
				gap = tmp->index - index;
				closer_index = tmp->index;
			}
		}
		tmp = tmp->next;
	}
	return (closer_index);
}

int	ft_max_index(t_node *stack)
{
	t_node	*tmp;
	int		max_index;

	if (!stack)
		return (INT_MIN_VALUE);
	else if (stack->next == NULL)
		return (stack->index);
	tmp = stack;
	max_index = INT_MIN_VALUE;
	while (tmp != NULL)
	{
		if (tmp->index > max_index)
			max_index = tmp->index;
		tmp = tmp->next;
	}
	return (max_index);
}

int	ft_min_index(t_node *stack)
{
	t_node	*tmp;
	int		min_index;

	if (!stack)
		return (INT_MAX_VALUE);
	else if (stack->next == NULL)
		return (stack->index);
	tmp = stack;
	min_index = INT_MAX_VALUE;
	while (tmp != NULL)
	{
		if (tmp->index < min_index)
			min_index = tmp->index;
		tmp = tmp->next;
	}
	return (min_index);
}
