/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_inputs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraft <kkraft@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 18:00:08 by kkraft            #+#    #+#             */
/*   Updated: 2025/11/17 18:00:08 by kkraft           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.h"

int	ft_check_order(char **argv_inputs)
{
	int	i;

	if (!argv_inputs || !*argv_inputs)
		return (0);
	i = 0;
	while (ft_is_flag(argv_inputs[i]))
		i++;
	while (ft_is_nb(argv_inputs[i]) && argv_inputs[i] != NULL)
		i++;
	while (ft_is_flag(argv_inputs[i]))
		i++;
	if (argv_inputs[i] != NULL)
		return (0);
	return (1);
}

int	ft_check_duplicates(char **argv_inputs)
{
	int	i;
	int	j;

	if (!argv_inputs || !*argv_inputs)
		return (0);
	i = 0;
	while (argv_inputs[i] != NULL)
	{
		j = i + 1;
		while (argv_inputs[j] != NULL)
		{
			if (!ft_strcmp(argv_inputs[i], argv_inputs[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_max_min_value(char **argv_inputs)
{
	long int	nb;
	int			i;

	if (!argv_inputs || !*argv_inputs)
		return (0);
	i = 0;
	while (argv_inputs[i] != NULL)
	{
		if (ft_is_nb(argv_inputs[i]))
		{
			nb = ft_long_atoi(argv_inputs[i]);
			if (nb > INT_MAX_VALUE || nb < INT_MIN_VALUE)
				return (0);
		}
		i++;
	}
	return (1);
}

int	ft_check_inputs_value(char **argv_inputs)
{
	int	i;

	if (!argv_inputs || !*argv_inputs)
		return (0);
	i = 0;
	while (argv_inputs[i] != NULL)
	{
		if (!ft_is_nb(argv_inputs[i]) && !ft_is_flag(argv_inputs[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_inputs(char **argv_inputs)
{
	if (!argv_inputs || !*argv_inputs)
		return (0);
	if (ft_check_order(argv_inputs) && ft_check_duplicates(argv_inputs)
		&& ft_check_max_min_value(argv_inputs)
		&& ft_check_inputs_value(argv_inputs))
		return (1);
	ft_clean_split(argv_inputs);
	return (0);
}
