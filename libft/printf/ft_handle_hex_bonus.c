/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hex_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:40:41 by kkraft            #+#    #+#             */
/*   Updated: 2025/12/11 15:28:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"
#include "../libft.h"

int	ft_handle_hex_basic(char type, char *s, int basic_size)
{
	if (!s)
		return (0);
	if (type == 'X')
		ft_toupper_str(s);
	ft_putstr_fd(s, 1);
	free(s);
	return (basic_size);
}

int	ft_handle_hex_hash(t_flags *flag, char type, char *s, int basic_size)
{
	if (!s)
		return (0);
	if (flag->precision > basic_size && flag->dot)
		s = ft_fill_before(s, 0, flag->precision, '0');
	else if (flag->dot && !flag->precision && ft_str_only_zero(s))
	{
		free(s);
		s = ft_strdup("");
	}
	if (flag->width - 2 > (int)ft_strlen(s))
		s = ft_handle_hex_hash_width(flag, s);
	else if (!ft_str_only_zero(s))
		s = ft_add_hash_flag(s);
	if (type == 'X')
		ft_toupper_str(s);
	basic_size = (int)ft_strlen(s);
	ft_putstr_fd(s, 1);
	free(s);
	return (basic_size);
}

char	*ft_handle_hex_hash_width(t_flags *flag, char *s)
{
	if (flag->minus)
	{
		if (*s)
			s = ft_add_hash_flag(s);
		s = ft_fill_after(s, flag->width, ' ');
	}
	else if (flag->zero && !flag->dot && !flag->minus)
	{
		s = ft_fill_before(s, 0, flag->width - 2, '0');
		if (!ft_str_only_zero(s))
			s = ft_add_hash_flag(s);
	}
	else
	{
		if (*s)
			s = ft_add_hash_flag(s);
		s = ft_fill_before(s, 0, flag->width, ' ');
	}
	return (s);
}

int	ft_handle_hex_nohash(t_flags *flag, char type, char *s, int basic_size)
{
	if (!s)
		return (0);
	if (flag->precision > basic_size && flag->dot)
		s = ft_fill_before(s, 0, flag->precision, '0');
	else if (flag->dot && !flag->precision && ft_str_only_zero(s))
	{
		free(s);
		s = ft_strdup("");
	}
	if (flag->minus)
		s = ft_fill_after(s, flag->width, ' ');
	else if (flag->zero && !flag->dot && !flag->minus)
		s = ft_fill_before(s, 0, flag->width, '0');
	else
		s = ft_fill_before(s, 0, flag->width, ' ');
	if (type == 'X')
		ft_toupper_str(s);
	basic_size = (int)ft_strlen(s);
	ft_putstr_fd(s, 1);
	free(s);
	return (basic_size);
}
