/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_uint_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:40:58 by kkraft            #+#    #+#             */
/*   Updated: 2025/12/11 15:28:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"
#include "../libft.h"

int	ft_handle_dot_uint(t_flags *flag, int nb)
{
	char	*uint_str;
	size_t	size;

	uint_str = ft_transform_uint_sub(nb);
	if (flag->precision > (int)ft_strlen(uint_str))
		uint_str = ft_fill_before(uint_str, 0, flag->precision, '0');
	else if (!flag->precision && ft_str_only_zero(uint_str))
	{
		free(uint_str);
		uint_str = ft_strdup("");
	}
	if (flag->width > (int)ft_strlen(uint_str))
	{
		if (flag->minus)
			uint_str = ft_fill_after(uint_str, flag->width, ' ');
		else
			uint_str = ft_fill_before(uint_str, 0, flag->width, ' ');
	}
	ft_putstr_fd(uint_str, 1);
	size = ft_strlen(uint_str);
	free(uint_str);
	return ((int)size);
}

int	ft_handle_width_uint(t_flags *flag, int nb)
{
	char	*uint_str;
	size_t	size;

	uint_str = ft_transform_uint_sub(nb);
	if (flag->width > (int)ft_strlen(uint_str))
	{
		if (flag->minus)
			uint_str = ft_fill_after(uint_str, flag->width, ' ');
		else if (flag->zero)
			uint_str = ft_fill_before(uint_str, 0, flag->width, '0');
		else
			uint_str = ft_fill_before(uint_str, 0, flag->width, ' ');
	}
	ft_putstr_fd(uint_str, 1);
	size = ft_strlen(uint_str);
	free(uint_str);
	return ((int)size);
}
