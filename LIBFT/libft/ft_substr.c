/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraft <kkraft@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:44:58 by kkraft            #+#    #+#             */
/*   Updated: 2025/11/18 07:16:39 by kkraft           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	size;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		size = 0;
	else if (ft_strlen(s + start) < len)
		size = ft_strlen(s + start);
	else
		size = len;
	sub_str = malloc(sizeof(char) * (size + 1));
	if (sub_str == NULL)
		return (NULL);
	i = 0;
	while (i < size && s[start + i] != '\0')
	{
		sub_str[i] = s[start + i];
		i++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}
