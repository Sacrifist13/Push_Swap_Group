/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraft <kkraft@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 11:59:45 by kkraft            #+#    #+#             */
/*   Updated: 2025/11/22 19:30:18 by kkraft           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/common.h"

void	ft_reset_op(t_op *op_c)
{
	if (!op_c)
		return ;
	op_c->rr_count = 0;
	op_c->ra_count = 0;
	op_c->rb_count = 0;
	op_c->rra_count = 0;
	op_c->rrb_count = 0;
	op_c->rrr_count = 0;
	op_c->total_r = 0;
	op_c->total_rr = 0;
	op_c->total = 0;
	return ;
}
