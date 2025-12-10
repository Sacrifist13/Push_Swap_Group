/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraft <kkraft@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 19:16:19 by kkraft            #+#    #+#             */
/*   Updated: 2025/11/18 07:16:39 by kkraft           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_is_sep(char sep, char c)
{
	if (c == sep)
		return (1);
	return (0);
}

static int	ft_word_count(char const *s, char sep)
{
	int	i;
	int	word_count;

	i = 0;
	word_count = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (!ft_is_sep(s[i], sep))
		{
			word_count++;
			while (!ft_is_sep(s[i], sep) && s[i] != '\0')
				i++;
		}
		while (ft_is_sep(s[i], sep) && s[i] != '\0')
			i++;
	}
	return (word_count);
}

static int	ft_word_size(char const *s, char sep, int index)
{
	int	word_index;
	int	word_size;
	int	i;

	word_index = 0;
	word_size = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (!ft_is_sep(s[i], sep) && s[i] != '\0')
		{
			i++;
			word_size++;
		}
		if (word_index == index && word_size != 0)
			return (word_size);
		else if (word_index != index && word_size != 0)
		{
			word_index ++;
			word_size = 0;
		}
		while (ft_is_sep(s[i], sep))
			i++;
	}
	return (word_size);
}

static char	*ft_return_word(char const *s, char sep, int size, int *curseur)
{
	char	*word;
	int		i;

	word = malloc(sizeof(char) * (size + 1));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		while (!ft_is_sep(s[*curseur], sep) && s[*curseur] != '\0')
			word[i++] = s[(*curseur)++];
		while (ft_is_sep(s[*curseur], sep) && s[*curseur] != '\0')
			(*curseur)++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**split_str;
	int		nbr_word;
	int		curseur;
	int		i;

	nbr_word = ft_word_count(s, c);
	split_str = malloc(sizeof(char *) * (nbr_word + 1));
	if (split_str == NULL)
		return (NULL);
	i = 0;
	curseur = 0;
	while (i < nbr_word)
	{
		split_str[i] = ft_return_word(s, c, ft_word_size(s, c, i), &curseur);
		if (split_str[i] == NULL)
		{
			while (i >= 0)
				free(split_str[i--]);
			free(split_str);
			return (NULL);
		}
		i++;
	}
	split_str[i] = NULL;
	return (split_str);
}
