/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraft <kkraft@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:07:05 by kkraft            #+#    #+#             */
/*   Updated: 2025/11/21 11:36:33 by kkraft           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"
#include "../libft.h"

static char	*ft_0_str(char *hex_str)
{
	hex_str[0] = '0';
	hex_str[1] = '\0';
	return (hex_str);
}

char	*ft_return_unsigned_nb_str(char *unsigned_nb_str)
{
	char	tmp;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(unsigned_nb_str);
	while (i <= (len / 2) - 1)
	{
		tmp = unsigned_nb_str[i];
		unsigned_nb_str[i] = unsigned_nb_str[len - i - 1];
		unsigned_nb_str[len - i - 1] = tmp;
		i++;
	}
	return (unsigned_nb_str);
}

int	ft_size_hex_str(int nb)
{
	int				size;
	unsigned int	nbr;

	size = 0;
	nbr = (unsigned int)nb;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		size++;
		nbr = nbr / 16;
	}
	return (size);
}

/* -- lower case base = "0123456789abcdef" -- */
/* -- upper case base = "0123456789ABCDEF" -- */

char	*ft_transform_hex_sub(int nb, char *base)
{
	char			*hex_str;
	unsigned int	nbr;
	size_t			i;

	if (base == NULL)
		return (0);
	hex_str = malloc(sizeof(char) * (ft_size_hex_str(nb) + 1));
	if (hex_str == NULL)
		return (0);
	nbr = (unsigned int)nb;
	if (nbr == 0)
		return (ft_0_str(hex_str));
	i = 0;
	while (nbr != 0)
	{
		hex_str[i++] = base[(nbr % 16)];
		nbr = nbr / 16;
	}
	hex_str[i] = '\0';
	hex_str = ft_return_unsigned_nb_str(hex_str);
	return (hex_str);
}

int	ft_transform_hex(char specifier, int nb, char *base)
{
	char	*hex_str;
	size_t	size;

	hex_str = ft_transform_hex_sub(nb, base);
	if (hex_str == NULL)
		return (0);
	if (specifier == 'X')
		ft_toupper_str(hex_str);
	size = ft_strlen(hex_str);
	ft_putstr_fd(hex_str, 1);
	free(hex_str);
	return ((int)size);
}
