/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_sub.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmattion <jmattion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:04:34 by jmattion          #+#    #+#             */
/*   Updated: 2025/12/11 18:29:43 by jmattion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/common.h"

void	ft_do_op(t_stacks *stacks, t_counter *counter, char *op)
{
	if (!ft_strcmp(op, "ra"))
		ft_rotate_a(&stacks->a, 0, 0, counter);
	else if (!ft_strcmp(op, "rb"))
		ft_rotate_b(&stacks->b, 0, 0, counter);
	else if (!ft_strcmp(op, "rr"))
		ft_rotate_r(&stacks->a, &stacks->b, 0, counter);
	else if (!ft_strcmp(op, "rra"))
		ft_reverse_rotate_a(&stacks->a, 0, 0, counter);
	else if (!ft_strcmp(op, "rrb"))
		ft_reverse_rotate_b(&stacks->b, 0, 0, counter);
	else if (!ft_strcmp(op, "rrr"))
		ft_reverse_rotate_r(&stacks->a, &stacks->b, 0, counter);
	else if (!ft_strcmp(op, "sa"))
		ft_swap_a(&stacks->a, 0, 0, counter);
	else if (!ft_strcmp(op, "sb"))
		ft_swap_b(&stacks->b, 0, 0, counter);
	else if (!ft_strcmp(op, "ss"))
		ft_swap_s(&stacks->a, &stacks->b, 0, counter);
	else if (!ft_strcmp(op, "pa"))
		ft_push_a(&stacks->a, &stacks->b, 0, counter);
	else if (!ft_strcmp(op, "pb"))
		ft_push_b(&stacks->b, &stacks->a, 0, counter);
	else
		return ;
}

int	ft_is_op(char *op)
{
	if (!ft_strcmp(op, "ra") || !ft_strcmp(op, "rb")
		|| !ft_strcmp(op, "rr") || !ft_strcmp(op, "rra")
		|| !ft_strcmp(op, "rrb") || !ft_strcmp(op, "rrr"))
		return (1);
	else if (!ft_strcmp(op, "sa") || !ft_strcmp(op, "sb")
		|| !ft_strcmp(op, "ss"))
		return (1);
	else if (!ft_strcmp(op, "pa") || !ft_strcmp(op, "pb"))
		return (1);
	return (0);
}
