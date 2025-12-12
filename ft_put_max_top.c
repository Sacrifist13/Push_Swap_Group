/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_max_top.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraft <kkraft@student42>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:38:55 by kkraft            #+#    #+#             */
/*   Updated: 2025/12/12 09:13:57 by kkraft           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.h"

void	ft_put_max_top(t_node **stack, t_flag *flag, t_counter *c)
{
	t_node	*max_node;
	int		max_index;
	int		mv_to_make;

	if (!stack || !*stack)
		return ;
	max_index = ft_max_index(*stack);
	max_node = ft_node_by_index(*stack, max_index);
	if (ft_cost_up(max_node) < ft_cost_down(max_node))
	{
		mv_to_make = ft_cost_up(max_node);
		ft_repeat_rb(stack, flag, c, mv_to_make);
	}
	else
	{
		mv_to_make = ft_cost_down(max_node);
		ft_repeat_rrb(stack, flag, c, mv_to_make);
	}
	return ;
}
