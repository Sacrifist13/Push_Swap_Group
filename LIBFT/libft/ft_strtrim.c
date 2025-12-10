/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraft <kkraft@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 19:14:51 by kkraft            #+#    #+#             */
/*   Updated: 2025/11/18 07:16:39 by kkraft           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_is_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str_trim;
	int		start;
	int		end;

	start = 0;
	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	while (ft_is_set(s1[start], set) && s1[start] != '\0')
		start++;
	if (s1[start] == '\0')
	{
		str_trim = malloc(sizeof(char));
		if (str_trim == NULL)
			return (NULL);
		str_trim[0] = '\0';
		return (str_trim);
	}
	end = ft_strlen(s1) - 1;
	while (ft_is_set(s1[end], set))
		end--;
	str_trim = ft_substr(s1, start, end - start + 1);
	return (str_trim);
}
