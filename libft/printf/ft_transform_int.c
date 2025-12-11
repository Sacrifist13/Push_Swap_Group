/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:07:20 by kkraft            #+#    #+#             */
/*   Updated: 2025/12/11 15:28:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"
#include "../libft.h"

char	*ft_transform_nb_sub(int nb)
{
	char		*nb_str;
	long int	nbr;

	nbr = (long int)nb;
	if (nbr > 2147483647)
		nb_str = ft_itoa(-1);
	else if (nbr < -2147483648)
		nb_str = ft_itoa(0);
	else
		nb_str = ft_itoa(nbr);
	if (nb_str == NULL)
		return (NULL);
	return (nb_str);
}

int	ft_transform_nb(int nb)
{
	char	*nb_str;
	size_t	size;

	nb_str = ft_transform_nb_sub(nb);
	if (nb_str == NULL)
		return (0);
	size = ft_strlen(nb_str);
	ft_putstr_fd(nb_str, 1);
	free(nb_str);
	return ((int)size);
}
