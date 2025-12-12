/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraft <kkraft@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 18:23:43 by kkraft            #+#    #+#             */
/*   Updated: 2025/11/17 18:23:43 by kkraft           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.h"

int	*ft_tab_sort(t_node *stack)
{
	t_node	*tmp;
	int		*sort_tab;
	int		size;
	int		i;

	if (!stack)
		return (NULL);
	size = ft_stack_size(stack);
	sort_tab = malloc(sizeof(int) * size);
	if (sort_tab == NULL)
		return (NULL);
	tmp = stack;
	i = 0;
	while (tmp != NULL)
	{
		sort_tab[i++] = tmp->value;
		tmp = tmp->next;
	}
	ft_sort_tab(sort_tab, size);
	return (sort_tab);
}

void	ft_fill_stack_value(t_node **stack, char **argv_inputs)
{
	int	i;

	i = 0;
	while (argv_inputs[i] != NULL)
	{
		if (ft_is_nb(argv_inputs[i]))
			ft_stack_add_back(stack, ft_new_node(ft_atoi(argv_inputs[i]), 0));
		i++;
	}
}

void	ft_fill_stack_index(t_node *stack, int *sort_tab)
{
	t_node	*tmp;
	int		size;
	int		i;

	i = 0;
	size = ft_stack_size(stack);
	while (i < size)
	{
		tmp = stack;
		while (tmp != NULL)
		{
			if (tmp->value == sort_tab[i])
			{
				tmp->index = i;
				break ;
			}
			tmp = tmp->next;
		}
		i++;
	}
	return ;
}

void	ft_fill_flag(t_flag *flag, char **argv_inputs)
{
	int	i;
	int	flag_nb;

	i = 0;
	while (argv_inputs[i] != NULL)
	{
		flag_nb = ft_is_flag(argv_inputs[i]);
		if (flag_nb == 1)
			flag->simple = 1;
		else if (flag_nb == 2)
			flag->medium = 1;
		else if (flag_nb == 3)
			flag->complex = 1;
		else if (flag_nb == 5)
			flag->bench = 1;
		i++;
	}
	return ;
}

float	ft_disorder(t_node *stack)
{
	t_node	*tmp;
	float	total_pairs;
	float	mistakes;

	if (!stack || ft_stack_size(stack) == 1)
		return (0);
	tmp = stack;
	mistakes = 0;
	total_pairs = 0;
	while (stack)
	{
		tmp = stack->next;
		while (tmp)
		{
			total_pairs++;
			if (stack->index > tmp->index)
				mistakes++;
			tmp = tmp->next;
		}
		stack = stack->next;
	}
	return (mistakes / total_pairs);
}
