/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunk_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmattion <jmattion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 11:12:05 by jmattion          #+#    #+#             */
/*   Updated: 2025/12/11 18:39:05 by jmattion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/common.h"

int	is_up(t_node *node, int max_index)
{
	t_node	*tmp;
	int		i;
	int		size;

	size = ft_stack_size(node);
	tmp = node;
	i = 0;
	while (tmp)
	{
		if (tmp->index == max_index)
			break ;
		tmp = tmp->next;
		i++;
	}
	if (i <= size / 2)
		return (1);
	return (0);
}

int	ft_chunk_size(int chunk_count, int size)
{
	if (chunk_count == 0 || chunk_count == 1)
		return (size);
	return (size / chunk_count);
}

void	ft_medium_sub(t_stacks *stacks, t_flag *flag, t_counter *c, int size)
{
	int	max_index;

	while (stacks->b)
	{
		max_index = ft_max_index(stacks->b);
		if (stacks->b->index == max_index)
		{
			ft_push_a(&stacks->a, &stacks->b, 1, c);
			if (stacks->a && stacks->a->next
				&& stacks->a->index > stacks->a->next->index)
				ft_swap_a(&stacks->a, 1, flag->bench, c);
		}
		else if (stacks->b->index == max_index - 1 && max_index != size - 1)
			ft_push_a(&stacks->a, &stacks->b, 1, c);
		else
		{
			if (is_up(stacks->b, max_index))
				ft_rotate_b(&stacks->b, 1, flag->bench, c);
			else
				ft_reverse_rotate_b(&stacks->b, 1, flag->bench, c);
		}
	}
}

void	ft_chunk_loop(t_stacks *stacks, t_flag *flags, t_counter *c, int r)
{
	int	c_size;

	c_size = ft_chunk_size(ft_sqrt(ft_stack_size(stacks->a)),
			ft_stack_size(stacks->a));
	while (stacks->a)
	{
		while (ft_stack_size(stacks->b) < r && stacks->a)
		{
			if (stacks->a->index < r)
			{
				ft_push_b(&stacks->b, &stacks->a, 1, c);
				if (stacks->b->index < r - (c_size / 2))
					ft_rotate_b(&stacks->b, 1, flags->bench, c);
			}
			else if (stacks->a->index < r + c_size)
			{
				ft_push_b(&stacks->b, &stacks->a, 1, c);
				ft_rotate_b(&stacks->b, 1, flags->bench, c);
			}
			else
				ft_rotate_a(&stacks->a, 1, flags->bench, c);
		}
		r += c_size;
	}
}

void	ft_medium_sort(t_stacks *stacks, t_flag *flags, t_counter *count)
{
	int	size;
	int	range_max;

	size = ft_stack_size(stacks->a);
	range_max = ft_chunk_size(ft_sqrt(size), size);
	ft_chunk_loop(stacks, flags, count, range_max);
	ft_medium_sub(stacks, flags, count, size);
}
