/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_in_chunk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraft <kkraft@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 00:48:15 by kkraft            #+#    #+#             */
/*   Updated: 2025/11/23 00:48:15 by kkraft           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/common.h"

int	ft_in_chunk(int min, int max, int index)
{
	if (index >= min && index <= max)
		return (1);
	return (0);
}
