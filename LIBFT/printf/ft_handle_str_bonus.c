/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_str_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraft <kkraft@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:40:55 by kkraft            #+#    #+#             */
/*   Updated: 2025/11/18 07:17:53 by kkraft           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"
#include "../libft.h"

char	*ft_transform_str_basic(char *s)
{
	char	*str;

	if (s == NULL)
		return (ft_strdup("(null)"));
	str = ft_strdup(s);
	return (str);
}

int	ft_handle_dot_str(t_flags *flag, char *s)
{
	char	*str;
	size_t	size;

	if (!s && flag->precision >= 6)
		str = ft_transform_str_basic(s);
	else
		str = ft_substr(s, 0, flag->precision);
	if (str == NULL)
		return (0);
	if (flag->width > (int)ft_strlen(str))
	{
		if (flag->minus)
			str = ft_fill_after(str, flag->width, ' ');
		else
			str = ft_fill_before(str, 0, flag->width, ' ');
	}
	size = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return ((int)size);
}

int	ft_handle_width_str(t_flags *flag, char *s)
{
	char	*basic_str;
	size_t	size;

	basic_str = ft_transform_str_basic(s);
	if (basic_str == NULL)
		return (0);
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
