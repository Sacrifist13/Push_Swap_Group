/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraft <kkraft@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 21:49:06 by kkraft            #+#    #+#             */
/*   Updated: 2025/11/17 21:49:06 by kkraft           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/common.h"

void	ft_rotate_a(t_node **stack, int w, int bm, t_counter *c)
{
	t_node	*tmp;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	*stack = (*stack)->next;
	tmp->next->prev = NULL;
	last->next = tmp;
	tmp->prev = last;
	tmp->next = NULL;
	if (w)
	{
		c->ra_count++;
		ft_printf("ra\n");
	}
	return ;
}

void	ft_rotate_b(t_node **stack, int w, int bm, t_counter *c)
{
	t_node	*tmp;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	*stack = (*stack)->next;
	tmp->next->prev = NULL;
	last->next = tmp;
	tmp->prev = last;
	tmp->next = NULL;
	if (w)
	{
		c->rb_count++;
		ft_printf("rb\n");
	}
	return ;
}

void	ft_rotate_r(t_node **a, t_node **b, int w, t_counter *c)
{
	ft_rotate_a(a, 0, 0, c);
	ft_rotate_b(b, 0, 0, c);
	if (w)
		ft_printf("rr\n");
	c->rr_count++;
	return ;
}
