/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraft <kkraft@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 11:48:58 by kkraft            #+#    #+#             */
/*   Updated: 2025/11/16 11:48:58 by kkraft           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.h"

void	ft_sort_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
				ft_swap_int(&tab[i], &tab[j]);
			j++;
		}
		i++;
	}
	return ;
}
