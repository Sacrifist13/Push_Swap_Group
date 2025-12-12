/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraft <kkraft@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 10:12:27 by kkraft            #+#    #+#             */
/*   Updated: 2025/11/23 10:12:27 by kkraft           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.h"

static void	ft_calcul_mv(t_op *lop_c, t_stacks *stacks, int index)
{
	if (!lop_c || !stacks)
		return ;
	ft_r_cost_sub(stacks, index, lop_c);
	ft_rr_cost_sub(stacks, index, lop_c);
	ft_smarter_cost(lop_c);
	ft_mix_cost_sub(stacks, index, lop_c);
	return ;
}

static t_op	*ft_find_best_mv(int start, int end, t_stacks *stacks)
{
	t_node	*tmp;
	t_op	*op_c;
	t_op	*lop_c;

	if (!stacks || !stacks->b)
		return (NULL);
	op_c = ft_new_op();
	lop_c = ft_new_op();
	op_c->total = INT_MAX_VALUE;
	tmp = stacks->b;
	while (tmp != NULL)
	{
		if (ft_in_chunk(start, end, tmp->index))
		{
			ft_calcul_mv(lop_c, stacks, tmp->index);
			if (lop_c->total < op_c->total)
				ft_change_smarter_move(op_c, lop_c);
			ft_reset_op(lop_c);
		}
		tmp = tmp->next;
	}
	free(lop_c);
	return (op_c);
}

static void	ft_srt_lst(t_stacks *stacks, t_flag *flag, t_counter *c, int c_sz)
{
	t_op	*op_c;
	int		end;
	int		start;

	start = (NB_CHUNKS - 1) * c_sz;
	end = ft_max_index(stacks->b);
	while (ft_remaining(start, end, stacks->b))
	{
		op_c = ft_find_best_mv(start, end, stacks);
		ft_exec_s(stacks, flag, op_c, c);
		free(op_c);
	}
	return ;
}

static void	ft_sort_c(t_stacks *stacks, t_flag *flag, t_counter *c, int c_sz)
{
	t_op	*op_c;
	int		end;
	int		start;
	int		i;

	i = NB_CHUNKS - 2;
	while (i >= 0)
	{
		start = i * c_sz;
		end = (i + 1) * c_sz - 1;
		while (ft_remaining(start, end, stacks->b))
		{
			op_c = ft_find_best_mv(start, end, stacks);
			ft_exec_s(stacks, flag, op_c, c);
			free(op_c);
		}
		i--;
	}
	return ;
}

void	ft_l_sort(t_stacks *stacks, t_flag *flag, t_counter *c, int c_sz)
{
	ft_srt_lst(stacks, flag, c, c_sz);
	ft_sort_c(stacks, flag, c, c_sz);
	ft_put_min_at_top(&stacks->a, flag, c);
	if (stacks->b != NULL)
		ft_printf("Erreur dans les calculs.\n");
	return ;
}
