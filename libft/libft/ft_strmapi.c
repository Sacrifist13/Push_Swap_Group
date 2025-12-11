/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 09:27:56 by kkraft            #+#    #+#             */
/*   Updated: 2025/12/11 15:28:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str_mapi;
	int		i;

	if (s == NULL || f == NULL)
		return (NULL);
	str_mapi = ft_strdup(s);
	if (str_mapi == NULL)
		return (NULL);
	i = 0;
	while (str_mapi[i] != '\0')
	{
		str_mapi[i] = f(i, str_mapi[i]);
		i++;
	}
	str_mapi[i] = '\0';
	return (str_mapi);
}
