/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraft <kkraft@student42>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 11:59:45 by kkraft            #+#    #+#             */
/*   Updated: 2025/12/12 09:13:57 by kkraft           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.h"

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
