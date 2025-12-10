/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_ptr_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraft <kkraft@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:40:52 by kkraft            #+#    #+#             */
/*   Updated: 2025/11/18 07:17:49 by kkraft           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"
#include "../libft.h"

int	ft_handle_width_ptr(t_flags *flag, void *ptr, char *base)
{
	char	*ptr_str;
	size_t	size;

	ptr_str = ft_transform_ptr_sub(ptr, base);
	if (ptr_str == NULL)
		return (0);
	if (flag->width > (int)ft_strlen(ptr_str))
	{
		if (flag->minus)
			ptr_str = ft_fill_after(ptr_str, flag->width, ' ');
		else if (!flag->minus && flag->zero)
			ptr_str = ft_fill_before(ptr_str, 2, flag->width, '0');
		else
			ptr_str = ft_fill_before(ptr_str, 0, flag->width, ' ');
	}
	size = ft_strlen(ptr_str);
	ft_putstr_fd(ptr_str, 1);
	free(ptr_str);
	return ((int)size);
}
