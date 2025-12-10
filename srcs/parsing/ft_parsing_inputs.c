/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_inputs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraft <kkraft@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 18:23:33 by kkraft            #+#    #+#             */
/*   Updated: 2025/11/17 18:23:33 by kkraft           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/common.h"

char	**ft_verif_input(int argc, char **argv)
{
	char	**argv_inputs;
	char	*argv_str;
	int		i;

	if (argc < 2)
		return (NULL);
	i = 1;
	argv_str = NULL;
	while (i < argc)
		argv_str = ft_strmerge(argv_str, argv[i++]);
	argv_inputs = ft_split(argv_str, ' ');
	free(argv_str);
	if (!ft_check_inputs(argv_inputs))
		return (NULL);
	return (argv_inputs);
}

t_stacks	*ft_setup(int argc, char **argv, t_flag *flag)
{
	t_stacks	*stacks;
	char		**argv_inputs;
	int			*sort_tab;

	argv_inputs = ft_verif_input(argc, argv);
	if (argv_inputs == NULL)
		return (NULL);
	stacks = ft_new_stacks();
	ft_fill_stack_value(&stacks->a, argv_inputs);
	sort_tab = ft_tab_sort(stacks->a);
	ft_fill_stack_index(stacks->a, sort_tab);
	ft_fill_flag(flag, argv_inputs);
	free(sort_tab);
	ft_clean_split(argv_inputs);
	stacks->disorder = ft_disorder(stacks->a);
	return (stacks);
}
