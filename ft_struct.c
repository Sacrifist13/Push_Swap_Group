/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraft <kkraft@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 21:00:14 by kkraft            #+#    #+#             */
/*   Updated: 2025/11/17 21:00:14 by kkraft           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.h"

t_stacks	*ft_new_stacks(void)
{
	t_stacks	*new_element;

	new_element = malloc(sizeof(t_stacks));
	if (new_element == NULL)
		return (NULL);
	new_element->a = NULL;
	new_element->b = NULL;
	new_element->disorder = 0;
	return (new_element);
}

t_node	*ft_new_node(int value, int index)
{
	t_node	*new_element;

	new_element = malloc(sizeof(t_node));
	if (new_element == NULL)
		return (NULL);
	new_element->value = value;
	new_element->index = index;
	new_element->next = NULL;
	new_element->prev = NULL;
	return (new_element);
}

t_flag	*ft_new_flag(void)
{
	t_flag	*new_element;

	new_element = malloc(sizeof(t_flag));
	if (new_element == NULL)
		return (NULL);
	new_element->simple = 0;
	new_element->medium = 0;
	new_element->complex = 0;
	new_element->adaptive = 1;
	new_element->bench = 0;
	return (new_element);
}

t_counter	*ft_new_counter(void)
{
	t_counter	*new_element;

	new_element = malloc(sizeof(t_counter));
	if (new_element == NULL)
		return (NULL);
	new_element->pa_count = 0;
	new_element->pb_count = 0;
	new_element->rra_count = 0;
	new_element->rrb_count = 0;
	new_element->rrr_count = 0;
	new_element->ra_count = 0;
	new_element->rb_count = 0;
	new_element->rr_count = 0;
	new_element->sa_count = 0;
	new_element->sb_count = 0;
	new_element->ss_count = 0;
	new_element->total = 0;
	return (new_element);
}

t_op	*ft_new_op(void)
{
	t_op	*new_element;

	new_element = malloc(sizeof(t_op));
	if (new_element == NULL)
		return (NULL);
	new_element->rr_count = 0;
	new_element->ra_count = 0;
	new_element->rb_count = 0;
	new_element->rra_count = 0;
	new_element->rrb_count = 0;
	new_element->rrr_count = 0;
	new_element->total_r = 0;
	new_element->total_rr = 0;
	new_element->total = INT_MAX_VALUE;
	return (new_element);
}
