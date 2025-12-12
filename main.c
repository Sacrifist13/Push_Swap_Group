/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmattion <jmattion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 08:24:35 by kkraft            #+#    #+#             */
/*   Updated: 2025/12/12 16:23:43 by jmattion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	t_flag		*flag;
	t_counter	*counter;

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
	ft_selector(stacks, flag, counter);
	return (0);
}
