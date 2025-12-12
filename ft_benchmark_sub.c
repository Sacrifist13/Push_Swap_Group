/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_benchmark_sub.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraft <kkraft@student42>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 08:52:55 by kkraft            #+#    #+#             */
/*   Updated: 2025/12/12 09:13:57 by kkraft           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.h"

void	ft_print_ops_1(t_counter *c)
{
	ft_putstr_fd("[bench] sa: ", 2);
	if (!c)
		return ;
	ft_putnbr_fd(c->sa_count, 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(c->sb_count, 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(c->ss_count, 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(c->pa_count, 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(c->pb_count, 2);
	return ;
}

void	ft_print_ops_2(t_counter *c)
{
	ft_putstr_fd("[bench] ra: ", 2);
	if (!c)
		return ;
	ft_putnbr_fd(c->ra_count, 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(c->rb_count, 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(c->rr_count, 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(c->rra_count, 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(c->rrb_count, 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(c->rrr_count, 2);
	return ;
}
