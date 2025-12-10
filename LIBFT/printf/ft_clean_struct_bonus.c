/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_struct_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraft <kkraft@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:29:35 by kkraft            #+#    #+#             */
/*   Updated: 2025/11/18 07:47:51 by kkraft           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

void	ft_clean_flags_struct(t_flags *flag)
{
	if (flag == NULL)
		return ;
	free(flag);
	flag = NULL;
	return ;
}
