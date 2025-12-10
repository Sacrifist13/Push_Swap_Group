/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform_unsigned.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraft <kkraft@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:08:16 by kkraft            #+#    #+#             */
/*   Updated: 2025/11/21 11:35:07 by kkraft           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"
#include "../libft.h"

static char	*ft_0_uint_str(char *uint_str)
{
	uint_str[0] = '0';
	uint_str[1] = '\0';
	return (uint_str);
}

int	ft_size_unsigned_str(unsigned int nbr)
{
	int	size;

	size = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		size++;
		nbr = nbr / 10;
	}
	return (size);
}

char	*ft_transform_uint_sub(int nb)
{
	char			*uint_str;
	unsigned int	nbr;
	size_t			i;

	uint_str = malloc(sizeof(char) * (ft_size_unsigned_str(nb) + 1));
	if (uint_str == NULL)
		return (0);
	nbr = (unsigned int)nb;
	i = 0;
	if (nb == 0)
		return (ft_0_uint_str(uint_str));
	while (nbr != 0)
	{
		uint_str[i++] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	uint_str[i] = '\0';
	uint_str = ft_return_unsigned_nb_str(uint_str);
	return (uint_str);
}

int	ft_transform_unsigned(int nb)
{
	char	*uint_str;
	size_t	size;

	uint_str = ft_transform_uint_sub(nb);
	ft_putstr_fd(uint_str, 1);
	size = ft_strlen(uint_str);
	free(uint_str);
	return ((int)size);
}
