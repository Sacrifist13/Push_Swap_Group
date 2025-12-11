/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform_str_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraft <kkraft@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:50:11 by kkraft            #+#    #+#             */
/*   Updated: 2025/11/18 07:51:12 by kkraft           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

void	ft_handle_str(t_flags *flag, va_list *args, int *size)
{
	if (!flag->width && !flag->dot)
		*size += ft_transform_str(va_arg(*args, char *));
	else if (flag->dot)
		*size += ft_handle_dot_str(flag, va_arg(*args, char *));
	else
		*size += ft_handle_width_str(flag, va_arg(*args, char *));
	return ;
}
