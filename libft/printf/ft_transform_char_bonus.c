/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform_char_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraft <kkraft@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:49:57 by kkraft            #+#    #+#             */
/*   Updated: 2025/11/18 11:22:48 by kkraft           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

void	ft_handle_char(t_flags *flag, va_list *args, int *size)
{
	if (!flag->width)
		*size += ft_transform_char(va_arg(*args, int));
	else
		*size += ft_handle_char_width(va_arg(*args, int), flag);
	return ;
}
