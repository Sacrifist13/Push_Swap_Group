/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraft <kkraft@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 08:02:58 by kkraft            #+#    #+#             */
/*   Updated: 2025/11/19 09:35:33 by kkraft           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/common.h"

char	*ft_return_str(char *nb_str)
{
	char	tmp;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(nb_str);
	while (i <= (len / 2) - 1)
	{
		tmp = nb_str[i];
		nb_str[i] = nb_str[len - i - 1];
		nb_str[len - i -1] = tmp;
		i++;
	}
	return (nb_str);
}
