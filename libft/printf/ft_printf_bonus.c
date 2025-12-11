/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:01:24 by kkraft            #+#    #+#             */
/*   Updated: 2025/12/11 15:28:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"
#include "../libft.h"

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		size;
	t_flags	*flag;

	if (s == NULL)
		return (0);
	size = 0;
	va_start(args, s);
	flag = ft_new_flags_struct();
	ft_printf_sub((char *)s, flag, &size, &args);
	va_end(args);
	ft_clean_flags_struct(flag);
	return (size);
}

void	ft_printf_sub(char *s, t_flags *flag, int *size, va_list *args)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '%' && s[i] != '\0')
			ft_putchar_fd_printf(s[i++], 1, size);
		if (s[i] == '%' && s[i + 1])
		{
			i += ft_conv_flags_struct(flag, s + i, args, size);
			ft_reset_flags_struct(flag);
		}
		else if (s[i] == '%' && !s[i + 1])
			i++;
	}
	return ;
}
