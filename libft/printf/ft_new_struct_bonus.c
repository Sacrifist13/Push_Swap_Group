/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_struct_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraft <kkraft@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:31:57 by kkraft            #+#    #+#             */
/*   Updated: 2025/11/18 07:49:38 by kkraft           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

t_flags	*ft_new_flags_struct(void)
{
	t_flags	*element;

	element = malloc(sizeof(t_flags));
	if (element == NULL)
		return (NULL);
	element->width = 0;
	element->dot = 0;
	element->precision = 0;
	element->minus = 0;
	element->plus = 0;
	element->space = 0;
	element->zero = 0;
	element->hash = 0;
	element->type = '\0';
	return (element);
}
