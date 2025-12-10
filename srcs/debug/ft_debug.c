/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraft <kkraft@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 22:35:14 by kkraft            #+#    #+#             */
/*   Updated: 2025/11/17 22:35:14 by kkraft           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/common.h"

void	ft_print_stack_value(t_node *stack)
{
	t_node	*tmp;

	if (!stack)
		return ;
	tmp = stack;
	while (tmp != NULL)
	{
		ft_printf("[%d]-", tmp->value);
		tmp = tmp->next;
	}
	ft_printf("[null]\n");
	return ;
}

void	ft_print_stacks(t_stacks *stacks, int write_title)
{
	t_node	*tmp;

	if (write_title)
		ft_print_title();
	if (stacks->a != NULL)
	{
		tmp = stacks->a;
		ft_printf("\n|-- STACK A --|\n[value | index]\n");
		while (tmp != NULL)
		{
			ft_printf("[%d | %d]\n", tmp->value, tmp->index);
			tmp = tmp->next;
		}
	}
	if (stacks->b != NULL)
	{
		tmp = stacks->b;
		ft_printf("\n|-- STACK B --|\n[value | index]\n");
		while (tmp != NULL)
		{
			ft_printf("[%d | %d]\n", tmp->value, tmp->index);
			tmp = tmp->next;
		}
	}
	return ;
}

void	ft_print_stack(t_node *stack)
{
	t_node	*tmp;

	if (stack == NULL)
		return ;
	tmp = stack;
	while (tmp != NULL)
	{
		if (tmp->prev == NULL && tmp->next == NULL)
			ft_printf("NULL - %d - NULL\n", tmp->index);
		else if (tmp->next == NULL)
			ft_printf("%d - %d - NULL\n", tmp->prev->index, tmp->index);
		else if (tmp->prev == NULL)
			ft_printf("NULL - %d - %d\n", tmp->index, tmp->next->index);
		else
			ft_printf("%d - %d - %d\n", tmp->prev->index,
				tmp->index, tmp->next->index);
		tmp = tmp->next;
	}
	return ;
}

void	ft_print_flag(t_flag *flag)
{
	if (flag->simple)
		ft_printf("--simple\n");
	else if (flag->medium)
		ft_printf("--medium\n");
	else if (flag->complex)
		ft_printf("--complex\n");
	else
		ft_printf("--adaptive\n");
	if (flag->bench)
		ft_printf("--bench\n");
	return ;
}

void	ft_print_setup(t_stacks *stacks, t_flag *flag)
{
	ft_printf("\n========================================\n");
	ft_printf("            SET UP PUSH-SWAP\n");
	ft_printf("========================================\n\n");
	ft_printf("--------------- STACKS ----------------\n");
	ft_print_stacks(stacks, 0);
	ft_printf("\n");
	ft_printf("--------------- FLAGS -----------------\n");
	ft_print_flag(flag);
	ft_printf("\n========================================\n\n");
	return ;
}
