/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform_hex_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraft <kkraft@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:50:00 by kkraft            #+#    #+#             */
/*   Updated: 2025/11/18 07:50:27 by kkraft           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"
#include "../libft.h"

void	ft_handle_hex(t_flags *flag, va_list *args, int *size)
{
	char	*s_basic;
	int		basic_size;

	s_basic = ft_transform_hex_sub(va_arg(*args, int), "0123456789abcdef");
	if (s_basic == NULL)
		return ;
	basic_size = (int)ft_strlen(s_basic);
	if (!flag->hash && flag->width <= basic_size && !flag->dot)
		*size += ft_handle_hex_basic(flag->type, s_basic, basic_size);
	else if (flag->hash)
		*size += ft_handle_hex_hash(flag, flag->type, s_basic, basic_size);
	else if (!flag->hash)
		*size += ft_handle_hex_nohash(flag, flag->type, s_basic, basic_size);
	else
		free(s_basic);
	return ;
}
