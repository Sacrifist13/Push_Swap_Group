/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraft <kkraft@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 21:49:09 by kkraft            #+#    #+#             */
/*   Updated: 2025/11/17 21:49:09 by kkraft           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/common.h"

void	ft_swap_a(t_node **stack, int w, int bm, t_counter *c)
{
	t_node	*tmp;
	t_node	*tmp_n;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	tmp_n = (*stack)->next;
	tmp->next = tmp_n->next;
	if (tmp_n->next)
		tmp_n->next->prev = tmp;
	tmp_n->prev = NULL;
	tmp_n->next = tmp;
	tmp->prev = tmp_n;
	*stack = tmp_n;
	if (w)
	{
		c->sa_count++;
		ft_printf("sa\n");
	}
	return ;
}

void	ft_swap_b(t_node **stack, int w, int bm, t_counter *c)
{
	t_node	*tmp;
	t_node	*tmp_n;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	tmp_n = (*stack)->next;
	tmp->next = tmp_n->next;
	if (tmp_n->next)
		tmp_n->next->prev = tmp;
	tmp_n->prev = NULL;
	tmp_n->next = tmp;
	tmp->prev = tmp_n;
	*stack = tmp_n;
	if (w)
	{
		c->sb_count++;
		ft_printf("sb\n");
	}
	return ;
}

void	ft_swap_s(t_node **a, t_node **b, int w, t_counter *c)
{
	ft_swap_a(a, 0, 0, c);
	ft_swap_b(b, 0, 0, c);
	ft_printf("ss\n");
	if (w)
		c->ss_count++;
	return ;
}
