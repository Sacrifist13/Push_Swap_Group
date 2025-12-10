/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_selector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 10:00:38 by kkraft            #+#    #+#             */
/*   Updated: 2025/12/10 14:26:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/common.h"

void	ft_selector(t_stacks *stacks, t_flag *flag, t_counter *c )
{
	ft_print_setup(stacks, flag);
	if (flag->simple)
		ft_simple_sort(stacks, flag, c);
	else if (flag->medium)
		ft_medium_sort(stacks, flag, c);
	else if (flag->complex)
		ft_complex_sort(stacks, flag, c);
	else
	{
		if (stacks->disorder < 0.2)
			ft_simple_sort(stacks, flag, c);
		else if (stacks->disorder < 0.5)
			ft_medium_sort(stacks, flag, c);
		else
			ft_complex_sort(stacks, flag, c);
	}
	ft_print_stacks(stacks, 1);
	if (flag->bench)
		ft_print_benchmark(c, flag, stacks->disorder);
	free(c);
	free(flag);
	ft_clean_stacks(stacks);
}
