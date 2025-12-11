/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraft <kkraft@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 21:49:05 by kkraft            #+#    #+#             */
/*   Updated: 2025/11/17 21:49:05 by kkraft           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/common.h"

void	ft_reverse_rotate_a(t_node **stack, int w, int bm, t_counter *c)
{
	t_node	*tmp;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	last->prev->next = NULL;
	last->next = tmp;
	tmp->prev = last;
	last->prev = NULL;
	*stack = last;
	if (w)
	{
		c->rra_count++;
		ft_printf("rra\n");
	}
	return ;
}

void	ft_reverse_rotate_b(t_node **stack, int w, int bm, t_counter *c)
{
	t_node	*tmp;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	last->prev->next = NULL;
	last->next = tmp;
	tmp->prev = last;
	last->prev = NULL;
	*stack = last;
	if (w)
	{
		c->rrb_count++;
		ft_printf("rrb\n");
	}
	return ;
}

void	ft_reverse_rotate_r(t_node **a, t_node **b, int w, t_counter *c)
{
	ft_reverse_rotate_a(a, 0, 0, c);
	ft_reverse_rotate_b(b, 0, 0, c);
	if (w)
		ft_printf("rrr\n");
	c->rrr_count++;
	return ;
}
