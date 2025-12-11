/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform_ptr_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraft <kkraft@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:50:09 by kkraft            #+#    #+#             */
/*   Updated: 2025/11/18 07:50:59 by kkraft           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

void	ft_handle_ptr(t_flags *flag, va_list *args, int *size)
{
	if (!flag->width)
		*size += ft_transform_ptr(va_arg(*args, void *), "0123456789abcdef");
	else
		*size += ft_handle_width_ptr(flag, va_arg(*args, void *),
				"0123456789abcdef");
	return ;
}
