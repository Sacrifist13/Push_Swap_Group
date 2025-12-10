/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraft <kkraft@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:49:54 by kkraft            #+#    #+#             */
/*   Updated: 2025/11/18 11:22:25 by kkraft           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

int	ft_conv_flags_struct(t_flags *flag, char *s, va_list *args, int *size)
{
	int		offset;

	offset = ft_fiil_flags_struct(flag, s);
	if (!ft_is_verif_flags_struct(flag))
		return (offset);
	if (flag->type == 'd' || flag->type == 'i')
		ft_handle_int(flag, args, size);
	else if (flag->type == 'u')
		ft_handle_uint(flag, args, size);
	else if (flag->type == 'x' || flag->type == 'X')
		ft_handle_hex(flag, args, size);
	else if (flag->type == 'c')
		ft_handle_char(flag, args, size);
	else if (flag->type == 's')
		ft_handle_str(flag, args, size);
	else if (flag->type == 'p')
		ft_handle_ptr(flag, args, size);
	else
		ft_handle_percent(flag, size);
	return (offset);
}
