/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_benchmark.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraft <kkraft@student42>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:49:46 by kkraft            #+#    #+#             */
/*   Updated: 2025/12/12 09:13:57 by kkraft           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.h"

void	ft_print_benchmark(t_counter *c, t_flag *flag, float disorder)
{
	int	disorder_int;

	disorder_int = (int)(disorder * 100000);
	ft_print_disorder(disorder_int, disorder_int % 10, disorder);
	ft_putstr_fd("\n", 2);
	ft_print_strategy(flag, disorder);
	ft_putstr_fd("\n", 2);
	ft_print_total_ops(c);
	ft_putstr_fd("\n", 2);
	ft_print_ops_1(c);
	ft_putstr_fd("\n", 2);
	ft_print_ops_2(c);
	ft_putstr_fd("\n", 2);
	return ;
}

void	ft_print_disorder(int disorder, int rest, float full_disorder)
{
	ft_putstr_fd("[bench] disorder: ", 2);
	if (!disorder)
	{
		ft_putstr_fd("00.00%", 2);
		return ;
	}
	if (full_disorder == 1)
	{
		ft_putstr_fd("100.00%", 2);
		return ;
	}
	if (rest != 0 && rest > 5)
		disorder = disorder + (10 - rest);
	else if (rest != 0)
		disorder = disorder - rest;
	disorder /= 10;
	ft_print_disorder_sub(disorder);
	return ;
}

void	ft_print_disorder_sub(int disorder)
{
	char	*s_disorder;
	int		i;

	s_disorder = malloc(sizeof(char) * 6);
	if (!s_disorder)
		return ;
	i = 0;
	while (disorder >= 100)
	{
		s_disorder[i++] = (disorder % 10) + '0';
		disorder /= 10;
	}
	s_disorder[i++] = '.';
	while (disorder > 0)
	{
		s_disorder[i++] = disorder % 10 + '0';
		disorder /= 10;
	}
	s_disorder[i] = '\0';
	s_disorder = ft_return_str(s_disorder);
	ft_putstr_fd(s_disorder, 2);
	ft_putstr_fd("%", 2);
	free(s_disorder);
	return ;
}

void	ft_print_strategy(t_flag *flag, float disorder)
{
	ft_putstr_fd("[bench] strategy: ", 2);
	if (!flag)
		return ;
	if (flag->simple)
		ft_putstr_fd("Simple / O(n^2)", 2);
	else if (flag->medium)
		ft_putstr_fd("Medium / O(n√n)", 2);
	else if (flag->complex)
		ft_putstr_fd("Complex / O(nlogn)", 2);
	else
	{
		ft_putstr_fd("Adaptive / ", 2);
		if (disorder < 0.2)
			ft_putstr_fd("O(n^2)", 2);
		else if (disorder < 0.5)
			ft_putstr_fd("O(n√n)", 2);
		else
			ft_putstr_fd("O(nlogn)", 2);
	}
	return ;
}

void	ft_print_total_ops(t_counter *c)
{
	ft_putstr_fd("[bench] total_ops: ", 2);
	if (!c)
		return ;
	c->total = c->pa_count + c->pb_count + c->ra_count
		+ c->rb_count + c->rr_count + c->rra_count
		+ c->rrb_count + c->rrr_count + c->sa_count
		+ c->sb_count + c->ss_count;
	ft_putnbr_fd(c->total, 2);
	return ;
}
