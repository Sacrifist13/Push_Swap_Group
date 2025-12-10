/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraft <kkraft@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:43:00 by kkraft            #+#    #+#             */
/*   Updated: 2025/11/20 15:35:47 by kkraft           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/common.h"

void	ft_print_op(t_op *op_c)
{
	ft_printf("ra_count = %d\n", op_c->ra_count);
	ft_printf("rb_count = %d\n", op_c->rb_count);
	ft_printf("rr_count = %d\n", op_c->rr_count);
	ft_printf("total_r = %d\n", op_c->total_r);
	ft_printf("rra_count = %d\n", op_c->rra_count);
	ft_printf("rrb_count = %d\n", op_c->rrb_count);
	ft_printf("rrr_count = %d\n", op_c->rrr_count);
	ft_printf("total_rr = %d\n", op_c->total_rr);
	ft_printf("total_count = %d\n", op_c->total);
	return ;
}
