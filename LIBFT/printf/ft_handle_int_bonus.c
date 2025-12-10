/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_int_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraft <kkraft@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:40:45 by kkraft            #+#    #+#             */
/*   Updated: 2025/11/18 07:53:46 by kkraft           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"
#include "../libft.h"

int	ft_handle_dot_nb_pos(t_flags *flag, int nb)
{
	char	*basic_str;
	size_t	size;

	basic_str = ft_transform_nb_sub(nb);
	if (flag->precision > (int)ft_strlen(basic_str))
		basic_str = ft_fill_before(basic_str, 0, flag->precision, '0');
	else if (!flag->precision && ft_str_only_zero(basic_str))
	{
		free(basic_str);
		basic_str = ft_strdup("");
	}
	if (flag->plus || flag->space)
		basic_str = ft_add_sign(flag, basic_str);
	if (flag->width > (int)ft_strlen(basic_str))
	{
		if (flag->minus)
			basic_str = ft_fill_after(basic_str, flag->width, ' ');
		else
			basic_str = ft_fill_before(basic_str, 0, flag->width, ' ');
	}
	size = ft_strlen(basic_str);
	ft_putstr_fd(basic_str, 1);
	free(basic_str);
	return ((int)size);
}

int	ft_handle_dot_nb_neg(t_flags *flag, int nb)
{
	char	*basic_str;
	size_t	size;

	basic_str = ft_transform_nb_sub(nb);
	if (flag->precision > (int)ft_strlen(basic_str) - 1)
		basic_str = ft_fill_before(basic_str, 1, flag->precision + 1, '0');
	if (flag->width > (int)ft_strlen(basic_str))
	{
		if (flag->minus)
			basic_str = ft_fill_after(basic_str, flag->width, ' ');
		else
			basic_str = ft_fill_before(basic_str, 0, flag->width, ' ');
	}
	size = ft_strlen(basic_str);
	ft_putstr_fd(basic_str, 1);
	free(basic_str);
	return ((int)size);
}

int	ft_handle_dot_nb(t_flags *flag, int nb)
{
	if (nb < 0)
		return (ft_handle_dot_nb_neg(flag, nb));
	else
		return (ft_handle_dot_nb_pos(flag, nb));
}

int	ft_handle_sign_nb(t_flags *flag, int nb)
{
	char	*basic_str;
	size_t	size;

	basic_str = ft_transform_nb_sub(nb);
	if ((flag->space || flag->plus) && !ft_str_is_negative(basic_str))
		basic_str = ft_add_sign(flag, basic_str);
	if (flag->width > (int)ft_strlen(basic_str))
	{
		if (flag->minus)
			basic_str = ft_fill_after(basic_str, flag->width, ' ');
		else if (flag->zero)
			basic_str = ft_fill_before(basic_str, 1, flag->width, '0');
		else
			basic_str = ft_fill_before(basic_str, 0, flag->width, ' ');
	}
	size = ft_strlen(basic_str);
	ft_putstr_fd(basic_str, 1);
	free(basic_str);
	return ((int)size);
}

int	ft_handle_width_nb(t_flags *flag, int nb)
{
	char	*basic_str;
	size_t	size;

	basic_str = ft_transform_nb_sub(nb);
	if (flag->width > (int)ft_strlen(basic_str))
	{
		if (flag->minus)
			basic_str = ft_fill_after(basic_str, flag->width, ' ');
		else if (flag->zero && ft_str_is_negative(basic_str))
			basic_str = ft_fill_before(basic_str, 1, flag->width, '0');
		else if (flag->zero)
			basic_str = ft_fill_before(basic_str, 0, flag->width, '0');
		else
			basic_str = ft_fill_before(basic_str, 0, flag->width, ' ');
	}
	size = ft_strlen(basic_str);
	ft_putstr_fd(basic_str, 1);
	free(basic_str);
	return ((int)size);
}
