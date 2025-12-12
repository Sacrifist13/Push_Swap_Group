/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cost.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraft <kkraft@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 18:34:48 by kkraft            #+#    #+#             */
/*   Updated: 2025/11/23 18:34:48 by kkraft           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.h"

int	ft_cost_down(t_node *node)
{
	t_node	*tmp;
	int		cost_down;

	if (!node || !node->prev)
		return (0);
	tmp = node;
	cost_down = 1;
	while (tmp->next != NULL)
	{
		cost_down++;
		tmp = tmp->next;
	}
	return (cost_down);
}

int	ft_cost_up(t_node *node)
{
	t_node	*tmp;
	int		cost_up;

	if (!node || !node->prev)
		return (0);
	tmp = node;
	cost_up = 0;
	while (tmp->prev != NULL)
	{
		cost_up++;
		tmp = tmp->prev;
	}
	return (cost_up);
}

void	ft_smarter_cost(t_op *op_c)
{
	if (!op_c)
		return ;
	if (op_c->total_r < op_c->total_rr)
	{
		op_c->rra_count = 0;
		op_c->rrb_count = 0;
		op_c->rrr_count = 0;
		op_c->total_rr = 0;
		op_c->total = op_c->total_r;
	}
	else
	{
		op_c->ra_count = 0;
		op_c->rb_count = 0;
		op_c->rr_count = 0;
		op_c->total_r = 0;
		op_c->total = op_c->total_rr;
	}
	return ;
}
