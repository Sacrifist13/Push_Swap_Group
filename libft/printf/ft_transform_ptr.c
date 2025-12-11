/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform_ptr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:07:56 by kkraft            #+#    #+#             */
/*   Updated: 2025/12/11 15:28:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"
#include "../libft.h"

static char	*ft_0_ptr_str(char *ptr_s)
{
	ptr_s[0] = '0';
	ptr_s[1] = 'x';
	ptr_s[2] = '0';
	ptr_s[3] = '\0';
	return (ptr_s);
}

int	ft_size_word_ptr_nb(long int ptr)
{
	unsigned long int	add_nbr;
	int					size;

	add_nbr = (long unsigned int)ptr;
	size = 0;
	if (add_nbr == 0)
		return (3);
	while (add_nbr != 0)
	{
		size++;
		add_nbr = add_nbr / 16;
	}
	size += 2;
	return (size);
}

/* -- base = "0123456789abcdef" -- */

char	*ft_transform_ptr_sub(void *ptr, char *base)
{
	char				*ptr_str;
	unsigned long int	add_nbr;
	int					size;
	int					i;

	if (ptr == NULL)
		return (ft_strdup("(nil)"));
	add_nbr = (unsigned long int)ptr;
	size = ft_size_word_ptr_nb((long int)add_nbr);
	ptr_str = malloc(sizeof(char) * (size + 1));
	if (ptr_str == NULL)
		return (NULL);
	i = 0;
	if (add_nbr == 0)
		return (ft_0_ptr_str(ptr_str));
	while (add_nbr != 0)
	{
		ptr_str[i++] = base[(add_nbr % 16)];
		add_nbr = add_nbr / 16;
	}
	ptr_str[i++] = 'x';
	ptr_str[i++] = '0';
	ptr_str[i] = '\0';
	ptr_str = ft_return_unsigned_nb_str(ptr_str);
	return (ptr_str);
}

int	ft_transform_ptr(void *ptr, char *base)
{
	char	*ptr_str;
	size_t	size;

	ptr_str = ft_transform_ptr_sub(ptr, base);
	if (ptr_str == NULL)
		return (0);
	size = ft_strlen(ptr_str);
	ft_putstr_fd(ptr_str, 1);
	free(ptr_str);
	return ((int)size);
}
