/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_char_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:40:38 by kkraft            #+#    #+#             */
/*   Updated: 2025/12/11 15:28:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"
#include "../libft.h"

int	ft_handle_char_width(char c, t_flags *flag)
{
	int	i;

	if (flag->minus)
	{
		i = 1;
		ft_putchar_fd(c, 1);
		while (i < flag->width)
		{
			ft_putchar_fd(' ', 1);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < flag->width - 1)
		{
			ft_putchar_fd(' ', 1);
			i++;
		}
		ft_putchar_fd(c, 1);
		i++;
	}
	return (i);
}
