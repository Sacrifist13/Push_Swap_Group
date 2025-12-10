/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraft <kkraft@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:08:08 by kkraft            #+#    #+#             */
/*   Updated: 2025/11/18 07:51:16 by kkraft           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"
#include "../libft.h"

int	ft_transform_str(char *s)
{
	size_t	size;

	if (s == NULL)
		return (ft_transform_str("(null)"));
	size = ft_strlen(s);
	ft_putstr_fd(s, 1);
	return ((int)size);
}
