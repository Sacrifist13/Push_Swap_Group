/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_repeat_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraft <kkraft@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:14:51 by kkraft            #+#    #+#             */
/*   Updated: 2025/11/21 11:03:57 by kkraft           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/common.h"

void	ft_repeat_sa(t_node **stack, t_flag *flag, t_counter *c, int n)
{
	int	i;

	i = 0;
	if (!stack || !*stack)
		return ;
	while (i < n)
	{
		ft_swap_a(stack, 1, flag->bench, c);
		i++;
	}
	return ;
}

void	ft_repeat_sb(t_node **stack, t_flag *flag, t_counter *c, int n)
{
	int	i;

	i = 0;
	if (!stack || !*stack)
		return ;
	while (i < n)
	{
		ft_swap_b(stack, 1, flag->bench, c);
		i++;
	}
	return ;
}

void	ft_repeat_ss(t_stacks *stacks, t_flag *flag, t_counter *c, int n)
{
	int	i;

	i = 0;
	if (!stacks)
		return ;
	while (i < n)
	{
		ft_swap_s(&stacks->a, &stacks->b, flag->bench, c);
		i++;
	}
	return ;
}
