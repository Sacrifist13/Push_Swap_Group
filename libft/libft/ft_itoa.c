/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 08:34:14 by kkraft            #+#    #+#             */
/*   Updated: 2025/12/11 15:28:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*ft_return_nb_str(char *nb_str)
{
	char	tmp;
	int		i;
	int		len;
	int		negative;

	i = 0;
	len = ft_strlen(nb_str);
	negative = 1;
	if (nb_str[0] == '-')
	{
		negative = 0;
		i++;
	}
	while (i <= (len / 2) - negative)
	{
		tmp = nb_str[i];
		nb_str[i] = nb_str[len - i - negative];
		nb_str[len - i - negative] = tmp;
		i++;
	}
	return (nb_str);
}

static int	ft_nbr_word_size(int n)
{
	int			nbr_word_size;
	long int	nbr;

	nbr_word_size = 0;
	nbr = (long int)n;
	if (nbr < 0)
	{
		nbr_word_size++;
		nbr = -nbr;
	}
	while (nbr >= 0)
	{
		nbr_word_size++;
		nbr = nbr / 10;
		if (nbr == 0)
			break ;
	}
	return (nbr_word_size);
}

char	*ft_itoa(int n)
{
	char		*nb_str;
	long int	nbr;
	int			i;

	nb_str = malloc(sizeof(char) * (ft_nbr_word_size(n) + 1));
	if (nb_str == NULL)
		return (NULL);
	nbr = (long int)n;
	i = 0;
	if (nbr < 0)
	{
		nb_str[i++] = '-';
		nbr = -nbr;
	}
	while (nbr >= 0)
	{
		nb_str[i++] = ((nbr % 10) + '0');
		nbr = nbr / 10;
		if (nbr == 0)
			break ;
	}
	nb_str[i] = '\0';
	nb_str = ft_return_nb_str(nb_str);
	return (nb_str);
}
