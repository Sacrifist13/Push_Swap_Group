/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_repeat_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmattion <jmattion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:14:48 by kkraft            #+#    #+#             */
/*   Updated: 2025/12/11 18:35:15 by jmattion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/common.h"

void	ft_repeat_ra(t_node **stack, t_flag *flag, t_counter *c, int n)
{
	int	i;

	i = 0;
	if (!stack || !*stack)
		return ;
	while (i < n)
	{
		ft_rotate_a(stack, 1, flag->bench, c);
		i++;
	}
	return ;
}

void	ft_repeat_rb(t_node **stack, t_flag *flag, t_counter *c, int n)
{
	int	i;

	i = 0;
	if (!stack || !*stack)
		return ;
	while (i < n)
	{
		ft_rotate_b(stack, 1, flag->bench, c);
		i++;
	}
	return ;
}

void	ft_repeat_rr(t_stacks *stacks, t_flag *flag, t_counter *c, int n)
{
	int	i;

	i = 0;
	if (!stacks)
		return ;
	while (i < n)
	{
		ft_rotate_r(&stacks->a, &stacks->b, 1, c);
		i++;
	}
	return ;
}
