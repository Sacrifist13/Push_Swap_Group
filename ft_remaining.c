/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remaining.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraft <kkraft@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 23:39:49 by kkraft            #+#    #+#             */
/*   Updated: 2025/11/22 23:39:49 by kkraft           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.h"

int	ft_remaining(int min, int max, t_node *stack)
{
	t_node	*tmp;

	tmp = stack;
	while (tmp != NULL)
	{
		if (tmp->index >= min && tmp->index <= max)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
