/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_repeat_reverse_rotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraft <kkraft@student42>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:14:45 by kkraft            #+#    #+#             */
/*   Updated: 2025/12/12 09:13:57 by kkraft           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.h"

void	ft_repeat_rra(t_node **stack, t_flag *flag, t_counter *c, int n)
{
	int	i;

	i = 0;
	if (!stack || !*stack)
		return ;
	while (i < n)
	{
		ft_reverse_rotate_a(stack, 1, flag->bench, c);
		i++;
	}
	return ;
}

void	ft_repeat_rrb(t_node **stack, t_flag *flag, t_counter *c, int n)
{
	int	i;

	i = 0;
	if (!stack || !*stack)
		return ;
	while (i < n)
	{
		ft_reverse_rotate_b(stack, 1, flag->bench, c);
		i++;
	}
	return ;
}

void	ft_repeat_rrr(t_stacks *stacks, t_flag *flag, t_counter *c, int n)
{
	int	i;

	i = 0;
	if (!stacks)
		return ;
	while (i < n)
	{
		ft_reverse_rotate_r(&stacks->a, &stacks->b, 1, c);
		i++;
	}
	return ;
}
