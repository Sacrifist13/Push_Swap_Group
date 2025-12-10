/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_selection_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraft <kkraft@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:09:20 by kkraft            #+#    #+#             */
/*   Updated: 2025/11/22 19:29:32 by kkraft           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/common.h"

void	ft_simple_sort(t_stacks *stacks, t_flag *flag, t_counter *c)
{
	t_node	*mv_node;
	int		min_index;
	int		cost_up;
	int		cost_down;

	while (stacks->a != NULL)
	{
		min_index = ft_min_index(stacks->a);
		mv_node = ft_node_by_index(stacks->a, min_index);
		if (mv_node)
		{
			cost_up = ft_cost_up(mv_node);
			cost_down = ft_cost_down(mv_node);
			if (cost_down < cost_up)
				ft_repeat_rra(&stacks->a, flag, c, cost_down);
			else
				ft_repeat_ra(&stacks->a, flag, c, cost_up);
			ft_push_b(&stacks->b, &stacks->a, flag->bench, c);
		}
	}
	while (stacks->b != NULL)
		ft_push_a(&stacks->a, &stacks->b, flag->bench, c);
	return ;
}
