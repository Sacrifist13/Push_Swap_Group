/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_struct_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:31:32 by kkraft            #+#    #+#             */
/*   Updated: 2025/12/11 15:28:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"
#include "../libft.h"

int	ft_fiil_flags_struct(t_flags *flag, char *flags_str)
{
	int	i;

	if (flags_str == NULL || flag == NULL)
		return (0);
	i = 1;
	ft_parse_flags(flag, flags_str, &i);
	ft_parse_width(flag, flags_str, &i);
	ft_parse_precision(flag, flags_str, &i);
	ft_parse_type(flag, flags_str, &i);
	return (i);
}

void	ft_parse_flags(t_flags *flag, char *flags_str, int *i)
{
	while ((flags_str[*i] == '#' || flags_str[*i] == '0'
			|| flags_str[*i] == ' ' || flags_str[*i] == '+'
			|| flags_str[*i] == '-')
		&& flags_str[*i] != '\0')
	{
		if (flags_str[*i] == '#')
			(flag->hash) = 1;
		else if (flags_str[*i] == '0')
			(flag->zero) = 1;
		else if (flags_str[*i] == ' ')
			(flag->space) = 1;
		else if (flags_str[*i] == '+')
			(flag->plus) = 1;
		else
			(flag->minus)++;
		(*i)++;
	}
	return ;
}

void	ft_parse_width(t_flags *flag, char *flags_str, int *i)
{
	int	width;

	width = ft_atoi(flags_str + *i);
	while (flags_str[*i] >= '0' && flags_str[*i] <= '9'
		&& flags_str[*i] != '\0')
		(*i)++;
	flag->width = width;
	return ;
}

void	ft_parse_precision(t_flags *flag, char *flags_str, int *i)
{
	int	precision;

	while (flags_str[*i] == '.' && flags_str[*i] != '\0')
	{
		(flag->dot)++;
		(*i)++;
	}
	precision = ft_atoi(flags_str + *i);
	while (flags_str[*i] >= '0' && flags_str[*i] <= '9'
		&& flags_str[*i] != '\0')
		(*i)++;
	flag->precision = precision;
	return ;
}

void	ft_parse_type(t_flags *flag, char *flags_str, int *i)
{
	if (flags_str[*i])
		flag->type = flags_str[*i];
	(*i)++;
	return ;
}
