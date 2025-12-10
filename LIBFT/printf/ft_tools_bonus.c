/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraft <kkraft@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:59:00 by kkraft            #+#    #+#             */
/*   Updated: 2025/11/21 11:38:41 by kkraft           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"
#include "../libft.h"

char	*ft_fill_before(char *s, int start, int total_len, char c)
{
	char	*str_fill;
	int		i;
	int		len;
	int		j;

	if (s == NULL)
		return (NULL);
	if ((int)ft_strlen(s) >= total_len)
		return (s);
	str_fill = malloc(sizeof(char) * total_len + 1);
	if (str_fill == NULL)
		return (NULL);
	len = (int)ft_strlen(s);
	j = 0;
	i = 0;
	while (i < start)
		str_fill[i++] = s[j++];
	while (i < total_len + start - len)
		str_fill[i++] = c;
	while (s[j] != '\0')
		str_fill[i++] = s[j++];
	str_fill[i] = '\0';
	free(s);
	return (str_fill);
}

char	*ft_fill_after(char *s, int total_len, char c)
{
	char	*str_fill;
	int		i;
	int		j;
	int		len;

	if (s == NULL)
		return (NULL);
	len = (int)ft_strlen(s);
	if (len >= total_len)
		return (s);
	str_fill = malloc(sizeof(char) * total_len + 1);
	if (str_fill == NULL)
		return (NULL);
	j = 0;
	i = 0;
	while (s[j] != '\0')
		str_fill[i++] = s[j++];
	while (i < total_len)
		str_fill[i++] = c;
	str_fill[i] = '\0';
	free(s);
	return (str_fill);
}

char	*ft_add_hash_flag(char *s)
{
	char	*hash_str;
	int		i;

	if (!s)
		return (NULL);
	hash_str = malloc(sizeof(char) * (ft_strlen(s) + 3));
	if (hash_str == NULL)
		return (NULL);
	hash_str[0] = '0';
	hash_str[1] = 'x';
	i = 0;
	while (s[i] != '\0')
	{
		hash_str[i + 2] = s[i];
		i++;
	}
	hash_str[i + 2] = '\0';
	free(s);
	return (hash_str);
}

char	*ft_add_sign(t_flags *flag, char *s)
{
	char	*str_wsign;
	int		i;

	if (s == NULL)
		return (NULL);
	str_wsign = malloc(sizeof(char) * (ft_strlen(s) + 2));
	if (str_wsign == NULL)
		return (NULL);
	if (flag->plus)
		str_wsign[0] = '+';
	else
		str_wsign[0] = ' ';
	i = 0;
	while (s[i] != '\0')
	{
		str_wsign[i + 1] = s[i];
		i++;
	}
	str_wsign[i + 1] = '\0';
	free(s);
	return (str_wsign);
}
