/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraft <kkraft@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 18:37:16 by kkraft            #+#    #+#             */
/*   Updated: 2025/11/23 18:37:16 by kkraft           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/common.h"

char	*ft_strcat(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
	{
		s1[i + j] = s2[j];
		j++;
	}
	s1[i + j] = '\0';
	return (s1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

char	*ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	while (s2[i] != '\0')
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

static char	*ft_add_space(char *s)
{
	size_t	size;

	if (s == NULL)
		return (NULL);
	size = ft_strlen(s);
	s[size] = ' ';
	s[size + 1] = '\0';
	return (s);
}

char	*ft_strmerge(char *s1, char *s2)
{
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (str == NULL)
		return (NULL);
	if (!s1)
	{
		str = ft_strcpy(str, s2);
		str = ft_add_space(str);
	}
	else
	{
		str = ft_strcpy(str, s1);
		str = ft_strcat(str, s2);
		str = ft_add_space(str);
	}
	if (s1)
		free(s1);
	return (str);
}
