/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunk_sort_cost.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraft <kkraft@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 19:11:15 by kkraft            #+#    #+#             */
/*   Updated: 2025/11/23 19:11:15 by kkraft           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.h"

void	ft_r_cost_sub(t_stacks *stacks, int index, t_op *op_c)
{
	t_node	*node;
	t_node	*node_place;

	if (!stacks)
		return ;
	node = ft_node_by_index(stacks->b, index);
	node_place = ft_node_place_sub(stacks->a, index);
	op_c->rb_count = ft_cost_up(node);
	op_c->ra_count = ft_cost_up(node_place);
	if (op_c->ra_count > op_c->rb_count)
	{
		op_c->rr_count = op_c->rb_count;
		op_c->ra_count -= op_c->rr_count;
		op_c->rb_count = 0;
	}
	else
	{
		op_c->rr_count = op_c->ra_count;
		op_c->rb_count -= op_c->rr_count;
		op_c->ra_count = 0;
	}
	op_c->total_r = op_c->rr_count + op_c->ra_count + op_c->rb_count;
	return ;
}

void	ft_rr_cost_sub(t_stacks *stacks, int index, t_op *op_c)
{
	t_node	*node;
	t_node	*node_place;

	if (!stacks)
		return ;
	node = ft_node_by_index(stacks->b, index);
	node_place = ft_node_place_sub(stacks->a, index);
	op_c->rrb_count = ft_cost_down(node);
	op_c->rra_count = ft_cost_down(node_place);
	if (op_c->rra_count > op_c->rrb_count)
	{
		op_c->rrr_count = op_c->rrb_count;
		op_c->rra_count -= op_c->rrr_count;
		op_c->rrb_count = 0;
	}
	else
	{
		op_c->rrr_count = op_c->rra_count;
		op_c->rrb_count -= op_c->rrr_count;
		op_c->rra_count = 0;
	}
	op_c->total_rr = op_c->rrr_count + op_c->rra_count + op_c->rrb_count;
	return ;
}

void	ft_mix_cost_sub(t_stacks *stacks, int index, t_op *op_c)
{
	t_node	*node;
	t_node	*node_place;
	int		total_1;
	int		total_2;

	node = ft_node_by_index(stacks->b, index);
	node_place = ft_node_place_sub(stacks->a, index);
	total_1 = ft_cost_up(node) + ft_cost_down(node_place);
	total_2 = ft_cost_down(node) + ft_cost_up(node_place);
	if (total_1 < total_2 && total_1 < op_c->total)
	{
		ft_reset_op(op_c);
		op_c->rb_count = ft_cost_up(node);
		op_c->rra_count = ft_cost_down(node_place);
		op_c->total = op_c->rb_count + op_c->rra_count;
	}
	else if (total_2 < op_c->total)
	{
		ft_reset_op(op_c);
		op_c->rrb_count = ft_cost_down(node);
		op_c->ra_count = ft_cost_up(node_place);
		op_c->total = op_c->rrb_count + op_c->ra_count;
	}
	return ;
}

void	ft_put_min_at_top(t_node **stack, t_flag *flag, t_counter *c)
{
	t_node	*min_node;
	int		min_index;
	int		mv_to_make;

	if (!stack || !*stack)
		return ;
	min_index = ft_min_index(*stack);
	min_node = ft_node_by_index(*stack, min_index);
	if (ft_cost_up(min_node) < ft_cost_down(min_node))
	{
		mv_to_make = ft_cost_up(min_node);
		ft_repeat_ra(stack, flag, c, mv_to_make);
	}
	else
	{
		mv_to_make = ft_cost_down(min_node);
		ft_repeat_rra(stack, flag, c, mv_to_make);
	}
	return ;
}
