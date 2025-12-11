/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smart_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 11:42:31 by kkraft            #+#    #+#             */
/*   Updated: 2025/12/11 15:37:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/common.h"

static void	ft_r_cost(t_stacks *stacks, int index, t_op *op_c)
{
	t_node	*node;
	t_node	*node_place;

	if (!stacks)
		return ;
	node = ft_node_by_index(stacks->a, index);
	node_place = ft_node_place(stacks->b, index);
	op_c->ra_count = ft_cost_up(node);
	op_c->rb_count = ft_cost_up(node_place);
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

static void	ft_rr_cost(t_stacks *stacks, int index, t_op *op_c)
{
	t_node	*node;
	t_node	*node_place;

	if (!stacks)
		return ;
	node = ft_node_by_index(stacks->a, index);
	node_place = ft_node_place(stacks->b, index);
	op_c->rra_count = ft_cost_down(node);
	op_c->rrb_count = ft_cost_down(node_place);
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

static void	ft_mix_cost(t_stacks *stacks, int index, t_op *op_c)
{
	t_node	*node;
	t_node	*node_place;
	int		total_1;
	int		total_2;

	node = ft_node_by_index(stacks->a, index);
	node_place = ft_node_place(stacks->b, index);
	total_1 = ft_cost_up(node) + ft_cost_down(node_place);
	total_2 = ft_cost_down(node) + ft_cost_up(node_place);
	if (total_1 < total_2 && total_1 < op_c->total)
	{
		ft_reset_op(op_c);
		op_c->ra_count = ft_cost_up(node);
		op_c->rrb_count = ft_cost_down(node_place);
		op_c->total = op_c->ra_count + op_c->rrb_count;
	}
	else if (total_2 < op_c->total)
	{
		ft_reset_op(op_c);
		op_c->rra_count = ft_cost_down(node);
		op_c->rb_count = ft_cost_up(node_place);
		op_c->total = op_c->rra_count + op_c->rb_count;
	}
	return ;
}

static void	ft_complex_sort_sub(t_stacks *stacks, t_flag *flag, t_counter *c)
{
	t_node	*tmp;
	t_op	*op_count;
	t_op	*lop_count;

	op_count = ft_new_op();
	lop_count = ft_new_op();
	while (stacks->a != NULL)
	{
		tmp = stacks->a;
		while (tmp != NULL)
		{
			ft_r_cost(stacks, tmp->index, lop_count);
			ft_rr_cost(stacks, tmp->index, lop_count);
			ft_smarter_cost(lop_count);
			ft_mix_cost(stacks, tmp->index, lop_count);
			if (lop_count->total < op_count->total)
				ft_change_smarter_move(op_count, lop_count);
			ft_reset_op(lop_count);
			tmp = tmp->next;
		}
		ft_exec(stacks, flag, op_count, c);
		op_count->total = INT_MAX_VALUE;
	}
	free(op_count);
	free(lop_count);
}

void	ft_complex_sort(t_stacks *stacks, t_flag *flag, t_counter *c)
{
	if (ft_stack_size(stacks->a) > 200)
		ft_complex_sort_2(stacks, flag, c);
	else
	{
		ft_complex_sort_sub(stacks, flag, c);
		ft_put_max_top(&stacks->b, flag, c);
		while (stacks->b != NULL)
			ft_push_a(&stacks->a, &stacks->b, flag->bench, c);
	}
	return ;
}
