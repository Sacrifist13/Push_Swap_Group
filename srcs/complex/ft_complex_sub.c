/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex_sub.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraft <kkraft@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 10:05:37 by kkraft            #+#    #+#             */
/*   Updated: 2025/11/23 10:05:37 by kkraft           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/common.h"

int	ft_remaining_sub(t_node *stack, int start, int end, int size)
{
	if (stack && (ft_remaining(start, end, stack)
			|| ft_remaining(start + size, end + size, stack)))
		return (1);
	return (0);
}

int	ft_index_in_higher_c(int index, int start, int end, int size)
{
	if (index >= start + size && index <= end + size)
		return (1);
	return (0);
}

void	ft_complex_sort_2(t_stacks *stacks, t_flag *flag, t_counter *c)
{
	int	chunk_size;

	chunk_size = ft_stack_size(stacks->a) / NB_CHUNKS;
	ft_pre_sort(stacks, flag, c, chunk_size);
	ft_l_sort(stacks, flag, c, chunk_size);
	return ;
}
