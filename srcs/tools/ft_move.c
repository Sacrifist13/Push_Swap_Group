/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraft <kkraft@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 18:33:27 by kkraft            #+#    #+#             */
/*   Updated: 2025/11/23 18:33:27 by kkraft           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/common.h"

void	ft_change_smarter_move(t_op *op_c, t_op *lop_c)
{
	if (!op_c || !lop_c)
		return ;
	op_c->rr_count = lop_c->rr_count;
	op_c->ra_count = lop_c->ra_count;
	op_c->rb_count = lop_c->rb_count;
	op_c->rra_count = lop_c->rra_count;
	op_c->rrb_count = lop_c->rrb_count;
	op_c->rrr_count = lop_c->rrr_count;
	op_c->total = lop_c->total;
	return ;
}

void	ft_exec(t_stacks *stacks, t_flag *flag, t_op *op_c, t_counter *c)
{
	if (!stacks || !flag || !op_c || !c)
		return ;
	ft_repeat_rr(stacks, flag, c, op_c->rr_count);
	ft_repeat_ra(&stacks->a, flag, c, op_c->ra_count);
	ft_repeat_rb(&stacks->b, flag, c, op_c->rb_count);
	ft_repeat_rrr(stacks, flag, c, op_c->rrr_count);
	ft_repeat_rra(&stacks->a, flag, c, op_c->rra_count);
	ft_repeat_rrb(&stacks->b, flag, c, op_c->rrb_count);
	ft_push_b(&stacks->b, &stacks->a, flag->bench, c);
	return ;
}

void	ft_exec_s(t_stacks *stacks, t_flag *flag, t_op *op_c, t_counter *c)
{
	if (!stacks || !flag || !op_c || !c)
		return ;
	ft_repeat_rr(stacks, flag, c, op_c->rr_count);
	ft_repeat_ra(&stacks->a, flag, c, op_c->ra_count);
	ft_repeat_rb(&stacks->b, flag, c, op_c->rb_count);
	ft_repeat_rrr(stacks, flag, c, op_c->rrr_count);
	ft_repeat_rra(&stacks->a, flag, c, op_c->rra_count);
	ft_repeat_rrb(&stacks->b, flag, c, op_c->rrb_count);
	ft_push_a(&stacks->a, &stacks->b, flag->bench, c);
}
