/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraft <kkraft@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 18:22:05 by kkraft            #+#    #+#             */
/*   Updated: 2025/11/17 18:22:05 by kkraft           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.h"

int	ft_is_nb(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (ft_isdigit(s[i]))
		i++;
	if (s[i] != '\0')
		return (0);
	return (1);
}

int	ft_is_flag(char *s)
{
	if (!ft_strcmp(s, SIMPLE_SELECTOR))
		return (1);
	else if (!ft_strcmp(s, MEDIUM_SELECTOR))
		return (2);
	else if (!ft_strcmp(s, COMPLEX_SELECTOR))
		return (3);
	else if (!ft_strcmp(s, ADAPTIVE_SELECTOR))
		return (4);
	else if (!ft_strcmp(s, BENCH_MODE))
		return (5);
	return (0);
}

long int	ft_long_atoi(const char *nptr)
{
	long int	result;
	int			sign;
	int			i;

	result = 0;
	i = 0;
	sign = 1;
	if (!nptr)
		return (0);
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
		if (result > INT_MAX_VALUE)
			break ;
	}
	return (result * sign);
}
