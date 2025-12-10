/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_struct_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraft <kkraft@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:33:00 by kkraft            #+#    #+#             */
/*   Updated: 2025/11/18 11:22:28 by kkraft           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

int	ft_is_verif_flags_struct(t_flags *flag)
{
	if (flag->dot > 1 || !ft_is_specifier(flag->type))
		return (0);
	if ((flag->type == 'd' || flag->type == 'i') && flag->hash)
		return (0);
	else if (flag->type == 'u' && (flag->plus || flag->space
			|| flag->hash))
		return (0);
	else if ((flag->type == 'x' || flag->type == 'X')
		&& (flag->plus || flag->space))
		return (0);
	else if (flag->type == 'c' && (flag->hash || flag->plus
			|| flag->space || flag->dot))
		return (0);
	else if (flag->type == 's' && (flag->hash || flag->zero
			|| flag->plus))
		return (0);
	else if (flag->type == 'p' && (flag->hash
			|| flag->plus || flag->space || flag->dot))
		return (0);
	else if (flag->type == '%' && (flag->hash || flag->plus
			|| flag->space || flag->dot))
		return (0);
	return (1);
}
