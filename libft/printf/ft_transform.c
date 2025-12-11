/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraft <kkraft@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:12:51 by kkraft            #+#    #+#             */
/*   Updated: 2025/11/18 07:15:33 by kkraft           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

void	ft_transform_specifier(char specifier, va_list *args, int *size)
{
	if (!ft_is_specifier(specifier))
		return ;
	if (specifier == 'd' || specifier == 'i')
		*size += ft_transform_nb(va_arg(*args, int));
	else if (specifier == 'c')
		*size += ft_transform_char(va_arg(*args, int));
	else if (specifier == 'x' || specifier == 'X')
		*size += ft_transform_hex(specifier, va_arg(*args, int),
				"0123456789abcdef");
	else if (specifier == 'p')
		*size += ft_transform_ptr(va_arg(*args, void *), "0123456789abcdef");
	else if (specifier == 'u')
		*size += ft_transform_unsigned(va_arg(*args, int));
	else if (specifier == 's')
		*size += ft_transform_str(va_arg(*args, char *));
	else
		*size += ft_transform_percent();
	return ;
}
