/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform_int_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraft <kkraft@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:50:03 by kkraft            #+#    #+#             */
/*   Updated: 2025/11/18 07:50:39 by kkraft           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"
#include "../libft.h"

void	ft_handle_int(t_flags *flag, va_list *args, int *size)
{
	if (!flag->dot && !flag->width && !flag->plus && !flag->space)
		*size += ft_transform_nb(va_arg(*args, long));
	else if (flag->dot)
		*size += ft_handle_dot_nb(flag, va_arg(*args, long));
	else if (flag->plus || flag->space)
		*size += ft_handle_sign_nb(flag, va_arg(*args, long));
	else
		*size += ft_handle_width_nb(flag, va_arg(*args, long));
	return ;
}
