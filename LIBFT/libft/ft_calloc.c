/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraft <kkraft@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:22:27 by kkraft            #+#    #+#             */
/*   Updated: 2025/11/18 07:16:39 by kkraft           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*area_memory;
	size_t			total_size;

	if (size && nmemb > (size_t)-1 / size)
		return (NULL);
	total_size = nmemb * size;
	area_memory = malloc(total_size);
	if (area_memory == NULL)
		return (NULL);
	ft_bzero(area_memory, total_size);
	return (area_memory);
}
