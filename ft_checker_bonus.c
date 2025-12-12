/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmattion <jmattion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 20:57:55 by jules             #+#    #+#             */
/*   Updated: 2025/12/12 16:23:31 by jmattion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	ft_is_sort(t_node *a)
{
	t_node	*current;

	current = a;
	while (current->next)
	{
		if (current->index > current->next->index)
			return (0);
		current = current->next;
	}
	return (1);
}

char	*ft_clean_end(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			str[i] = '\0';
			return (str);
		}
		i++;
	}
	return (str);
}

int	ft_checker(t_stacks *stacks, t_counter *counter)
{
	char	*to_do;

	to_do = get_next_line(0);
	while (to_do)
	{
		to_do = ft_clean_end(to_do);
		if (!ft_is_op(to_do))
		{
			while (to_do)
			{
				free(to_do);
				to_do = get_next_line(0);
			}
			return (0);
		}
		ft_do_op(stacks, counter, to_do);
		free(to_do);
		to_do = get_next_line(0);
	}
	free(to_do);
	return (1);
}

void	ft_print_result(t_stacks *stacks)
{
	if (ft_is_sort(stacks->a) && ft_stack_size(stacks->b) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	t_flag		*flag;
	t_counter	*counter;

	if (ft_check_argc(argc))
		return (1);
	flag = ft_new_flag();
	stacks = ft_setup(argc, argv, flag);
	if (stacks == NULL || stacks->a == NULL)
	{
		ft_clean_stacks(stacks);
		free(flag);
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	counter = ft_new_counter();
	if (!ft_checker(stacks, counter))
		ft_putstr_fd("Error\n", 2);
	else
		ft_print_result(stacks);
	ft_clean_stacks(stacks);
	free(flag);
	free(counter);
	return (0);
}
