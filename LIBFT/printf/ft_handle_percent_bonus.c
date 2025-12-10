/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_percent_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraft <kkraft@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:40:49 by kkraft            #+#    #+#             */
/*   Updated: 2025/11/18 07:17:46 by kkraft           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"
#include "../libft.h"

int	ft_handle_width_percent(t_flags *flag)
{
	char	*basic_str;
	size_t	size;

	basic_str = malloc(sizeof(char) * 2);
	if (basic_str == NULL)
		return (0);
	basic_str[0] = '%';
	basic_str[1] = '\0';
	if (flag->minus)
		basic_str = ft_fill_after(basic_str, flag->width, ' ');
	else
		basic_str = ft_fill_before(basic_str, 0, flag->width, ' ');
	size = ft_strlen(basic_str);
	ft_putstr_fd(basic_str, 1);
	free(basic_str);
	return ((int)size);
}
