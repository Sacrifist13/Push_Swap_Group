/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform_uint_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraft <kkraft@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:50:15 by kkraft            #+#    #+#             */
/*   Updated: 2025/11/18 11:23:11 by kkraft           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

void	ft_handle_uint(t_flags *flag, va_list *args, int *size)
{
	if (!flag->dot && !flag->width)
		*size += ft_transform_unsigned(va_arg(*args, int));
	else if (flag->dot)
		*size += ft_handle_dot_uint(flag, va_arg(*args, int));
	else
		*size += ft_handle_width_uint(flag, va_arg(*args, int));
	return ;
}
