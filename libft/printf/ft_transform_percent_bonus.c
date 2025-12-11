/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform_percent_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraft <kkraft@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:50:06 by kkraft            #+#    #+#             */
/*   Updated: 2025/11/18 07:50:51 by kkraft           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

void	ft_handle_percent(t_flags *flag, int *size)
{
	if (flag->width <= 1)
		*size += ft_transform_percent();
	else
		*size += ft_handle_width_percent(flag);
	return ;
}
