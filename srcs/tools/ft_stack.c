/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraft <kkraft@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 18:29:35 by kkraft            #+#    #+#             */
/*   Updated: 2025/11/23 18:29:35 by kkraft           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/common.h"

int	ft_stack_size(t_node *a)
{
	t_node	*tmp;
	int		size;

	size = 0;
	if (!a)
		return (0);
	tmp = a;
	while (tmp != NULL)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

void	ft_stack_add_back(t_node **stack, t_node *node)
{
	t_node	*tmp;

	if (!node)
		return ;
	if (!stack || !*stack)
	{
		*stack = node;
		return ;
	}
	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = node;
	node->prev = tmp;
	return ;
}

t_stacks	*ft_clean_stacks(t_stacks *stack)
{
	t_node	*tmp;

	if (!stack)
		return (NULL);
	while (stack->a != NULL)
	{
		tmp = stack->a;
		stack->a = stack->a->next;
		free(tmp);
	}
	while (stack->b != NULL)
	{
		tmp = stack->b;
		stack->b = stack->b->next;
		free(tmp);
	}
	free(stack);
	stack = NULL;
	return (stack);
}
