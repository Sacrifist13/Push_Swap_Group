/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pre_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmattion <jmattion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 17:17:47 by kkraft            #+#    #+#             */
/*   Updated: 2025/12/11 18:37:59 by jmattion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/common.h"

static void	ft_init_values(int i, int size, int *start, int *end)
{
	*start = i * size;
	*end = (i + 1) * size - 1;
	return ;
}

static int	ft_node_in_chunk(t_node *stack, int start, int end, int size)
{
	if (stack && (ft_in_chunk(start, end, stack->index)
			|| ft_in_chunk(start + size, end + size, stack->index)))
		return (1);
	return (0);
}

static void	ft_sort_init(t_stacks *stacks, t_flag *flag, t_counter *c, int size)
{
	int	i;
	int	start;
	int	end;

	i = 0;
	while (i < NB_CHUNKS - 2)
	{
		ft_init_values(i, size, &start, &end);
		while (ft_remaining_sub(stacks->a, start, end, size))
		{
			if (ft_in_chunk(start, end, stacks->a->index))
			{
				ft_push_b(&stacks->b, &stacks->a, 1, c);
				if (ft_node_in_chunk(stacks->a, start, end, size))
					ft_rotate_b(&stacks->b, 1, flag->bench, c);
				else if (stacks->a)
					ft_rotate_r(&stacks->a, &stacks->b, 1, c);
			}
			else if (ft_index_in_higher_c(stacks->a->index, start, end, size))
				ft_push_b(&stacks->b, &stacks->a, 1, c);
			else
				ft_rotate_a(&stacks->a, 1, flag->bench, c);
		}
		i += 2;
	}
}

static void	ft_sort_term(t_stacks *stacks, t_flag *flag, t_counter *c, int size)
{
	int	start;
	int	end;
	int	last_index;

	start = (NB_CHUNKS - 2) * size;
	end = (NB_CHUNKS - 1) * size - 1;
	last_index = ft_max_index(stacks->a);
	while ((ft_remaining(start, end, stacks->a)
			|| ft_remaining(start + size, last_index, stacks->a)))
	{
		if (ft_in_chunk(start, end, stacks->a->index))
		{
			ft_push_b(&stacks->b, &stacks->a, 1, c);
			if (stacks->a && (ft_in_chunk(start, end, stacks->a->index)
					|| ft_in_chunk(start + size, last_index, stacks->a->index)))
				ft_rotate_b(&stacks->b, 1, flag->bench, c);
			else if (stacks->a)
				ft_rotate_r(&stacks->a, &stacks->b, 1, c);
		}
		else if (stacks->a->index >= start + size
			&& stacks->a->index <= last_index)
			ft_push_b(&stacks->b, &stacks->a, 1, c);
		else
			ft_rotate_a(&stacks->a, 1, flag->bench, c);
	}
}

void	ft_pre_sort(t_stacks *stacks, t_flag *flag, t_counter *c, int c_sz)
{
	ft_sort_init(stacks, flag, c, c_sz);
	ft_sort_term(stacks, flag, c, c_sz);
	return ;
}
