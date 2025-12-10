/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_struct_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraft <kkraft@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:32:38 by kkraft            #+#    #+#             */
/*   Updated: 2025/11/18 07:54:16 by kkraft           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

void	ft_reset_flags_struct(t_flags *flag)
{
	if (flag == NULL)
		return ;
	flag->width = 0;
	flag->dot = 0;
	flag->precision = 0;
	flag->minus = 0;
	flag->plus = 0;
	flag->space = 0;
	flag->zero = 0;
	flag->hash = 0;
	flag->type = '\0';
	return ;
}
