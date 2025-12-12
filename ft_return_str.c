/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraft <kkraft@student42>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 08:02:58 by kkraft            #+#    #+#             */
/*   Updated: 2025/12/12 09:13:57 by kkraft           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.h"

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
