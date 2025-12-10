/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraft <kkraft@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:20:58 by kkraft            #+#    #+#             */
/*   Updated: 2025/11/18 07:50:11 by kkraft           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"
#include "../libft.h"

void	ft_putchar_fd_printf(char c, int fd, int *size)
{
	write(fd, &c, 1);
	(*size)++;
	return ;
}

int	ft_is_specifier(char specifier)
{
	if (specifier == 'c' || specifier == 's' || specifier == 'p'
		|| specifier == 'd' || specifier == 'i' || specifier == 'u'
		|| specifier == 'x' || specifier == 'X' || specifier == '%')
		return (1);
	return (0);
}

void	ft_toupper_str(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		s[i] = ft_toupper(s[i]);
		i++;
	}
	return ;
}

int	ft_str_only_zero(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

int	ft_str_is_negative(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '-')
			return (1);
		i++;
	}
	return (0);
}
