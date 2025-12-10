/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraft <kkraft@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 11:10:20 by kkraft            #+#    #+#             */
/*   Updated: 2025/11/16 11:10:20 by kkraft           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/common.h"

char	**ft_clean_split(char **split)
{
	int	i;

	i = 0;
	if (split == NULL)
		return (NULL);
	while (split[i] != NULL)
		free(split[i++]);
	free(split);
	split = NULL;
	return (split);
}
