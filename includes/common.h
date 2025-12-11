/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraft <kkraft@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 17:55:55 by kkraft            #+#    #+#             */
/*   Updated: 2025/11/17 17:55:55 by kkraft           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

/* -- INCLUDES -- */
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

/* -- CONSTANT VALUES -- */
# define NB_CHUNKS 8
# define INT_MAX_VALUE 2147483647
# define INT_MIN_VALUE -2147483648
# define SIMPLE_SELECTOR "--simple"
# define MEDIUM_SELECTOR "--medium"
# define COMPLEX_SELECTOR "--complex"
# define ADAPTIVE_SELECTOR "--adaptive"
# define BENCH_MODE "--bench"

/* -- STRUCT -- */
typedef struct s_node
{
	long int		value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stacks
{
	struct s_node	*a;
	struct s_node	*b;
	float			disorder;
}	t_stacks;

typedef struct s_flag
{
	int	simple;
	int	medium;
	int	complex;
	int	adaptive;
	int	bench;
}	t_flag;

typedef struct s_counter
{
	int	pa_count;
	int	pb_count;
	int	rra_count;
	int	rrb_count;
	int	rrr_count;
	int	ra_count;
	int	rb_count;
	int	rr_count;
	int	sa_count;
	int	sb_count;
	int	ss_count;
	int	total;
}	t_counter;

typedef struct s_op
{
	int	rr_count;
	int	ra_count;
	int	rb_count;
	int	rrr_count;
	int	rra_count;
	int	rrb_count;
	int	total_r;
	int	total_rr;
	int	total;
}	t_op;

/* -- PARSING PART -- */
/* -- CHECK -- */
int			ft_check_order(char **argv_inputs);
int			ft_check_duplicates(char **argv_inputs);
int			ft_check_max_min_value(char **argv_inputs);
int			ft_check_inputs_value(char **argv_inputs);
int			ft_check_inputs(char **argv_inputs);
int			ft_is_nb(char *s);
int			ft_is_flag(char *s);
long int	ft_long_atoi(const char *nptr);
/* -- PARSING -- */
char		**ft_verif_input(int argc, char **argv);
t_stacks	*ft_setup(int argc, char **argv, t_flag *flag);
int			*ft_tab_sort(t_node *stack);
void		ft_fill_stack_value(t_node **stack, char **argv_inputs);
void		ft_fill_stack_index(t_node *stack, int *sort_tab);
void		ft_fill_flag(t_flag *flag, char **argv_inputs);
float		ft_disorder(t_node *stack);
/* ----              ---- */

/* -- STRUCT PARTS -- */
t_stacks	*ft_new_stacks(void);
t_node		*ft_new_node(int value, int index);
t_flag		*ft_new_flag(void);
t_counter	*ft_new_counter(void);
t_op		*ft_new_op(void);
/* ----              ---- */

/* -- RULES PART -- */
void		ft_push_a(t_node **a, t_node **b, int bm, t_counter *c);
void		ft_push_b(t_node **b, t_node **a, int bm, t_counter *c);
void		ft_reverse_rotate_a(t_node **stack, int w, int bm, t_counter *c);
void		ft_reverse_rotate_b(t_node **stack, int w, int bm, t_counter *c);
void		ft_reverse_rotate_r(t_node **a, t_node **b, int bm, t_counter *c);
void		ft_rotate_a(t_node **stack, int w, int bm, t_counter *c);
void		ft_rotate_b(t_node **stack, int w, int bm, t_counter *c);
void		ft_rotate_r(t_node **a, t_node **b, int bm, t_counter *c);
void		ft_swap_a(t_node **stack, int w, int bm, t_counter *c);
void		ft_swap_b(t_node **stack, int w, int bm, t_counter *c);
void		ft_swap_s(t_node **a, t_node **b, int bm, t_counter *c);
/* ----              ---- */

/* -- SELECTOR PART -- */
void		ft_selector(t_stacks *stacks, t_flag *flag, t_counter *c );
/* ----              ---- */

/* -- ALGO PART -- */
/* -- SIMPLE -- */
void		ft_simple_sort(t_stacks *stacks, t_flag *flag, t_counter *c);

/* -- MEDIUM -- */
void		ft_medium_sort(t_stacks *stacks, t_flag *flags, t_counter *counter);

/* -- COMPLEX -- */
void		ft_complex_sort(t_stacks *stacks, t_flag *flag, t_counter *c);
/* -- -- */
/* -- test chunk sort | smart sort -- */
void		ft_complex_sort_2(t_stacks *stacks, t_flag *flag, t_counter *c);
void		ft_pre_sort(t_stacks *stacks, t_flag *flag, t_counter *c, int c_sz);
void		ft_l_sort(t_stacks *stacks, t_flag *flag, t_counter *c, int c_sz);
void		ft_put_min_at_top(t_node **stack, t_flag *flag, t_counter *c);
int			ft_remaining_sub(t_node *stack, int start, int end, int size);
int			ft_index_in_higher_c(int index, int start, int end, int size);
void		ft_r_cost_sub(t_stacks *stacks, int index, t_op *op_c);
void		ft_rr_cost_sub(t_stacks *stacks, int index, t_op *op_c);
void		ft_mix_cost_sub(t_stacks *stacks, int index, t_op *op_c);
/* ----              ---- */

/* -- BENCHMARK MODE PART -- */
void		ft_print_benchmark(t_counter *c, t_flag *flag, float disorder);
void		ft_print_disorder(int disorder, int rest);
void		ft_print_disorder_sub(int disorder);
void		ft_print_strategy(t_flag *flag, float disorder);
void		ft_print_total_ops(t_counter *c);
void		ft_print_ops_1(t_counter *c);
void		ft_print_ops_2(t_counter *c);
/* ----              ---- */

/* -- TOOLS FUNCTIONS PART -- */
char		*ft_strcat(char *s1, char *s2);
char		*ft_strmerge(char *s1, char *s2);
char		**ft_clean_split(char **split);
void		ft_sort_tab(int *tab, int size);
void		ft_swap_int(int *a, int *b);
int			ft_stack_size(t_node *a);
char		*ft_strcat(char *s1, char *s2);
int			ft_strcmp(char *s1, char *s2);
char		*ft_strcpy(char *s1, char *s2);
char		*ft_return_str(char *nb_str);
int			ft_cost_down(t_node *node);
int			ft_cost_up(t_node *node);
int			ft_min_index(t_node *stack);
int			ft_max_index(t_node *stack);
int			ft_closer_index(t_node *stack, int index);
int			ft_closer_index_sub(t_node *stack, int index);
int			ft_sqrt(int nb);
int			ft_remaining(int min, int max, t_node *stack);
int			ft_in_chunk(int min, int max, int index);
void		ft_stack_add_back(t_node **stack, t_node *node);
t_stacks	*ft_clean_stacks(t_stacks *stack);
t_node		*ft_node_by_index(t_node *stack, int index);
t_node		*ft_node_place(t_node *stack, int index);
t_node		*ft_node_place_sub(t_node *stack, int index);
void		ft_reset_op(t_op *op_c);
void		ft_smarter_cost(t_op *op_c);
void		ft_change_smarter_move(t_op *op_c, t_op *lop_c);
void		ft_put_max_top(t_node **stack, t_flag *flag, t_counter *c);
void		ft_exec(t_stacks *stacks, t_flag *flag, t_op *op_c, t_counter *c);
void		ft_exec_s(t_stacks *stacks, t_flag *flag, t_op *op_c, t_counter *c);
void		ft_repeat_rra(t_node **stack, t_flag *flag, t_counter *c, int n);
void		ft_repeat_rrb(t_node **stack, t_flag *flag, t_counter *c, int n);
void		ft_repeat_rrr(t_stacks *stacks, t_flag *flag, t_counter *c, int n);
void		ft_repeat_ra(t_node **stack, t_flag *flag, t_counter *c, int n);
void		ft_repeat_rb(t_node **stack, t_flag *flag, t_counter *c, int n);
void		ft_repeat_rr(t_stacks *stacks, t_flag *flag, t_counter *c, int n);
void		ft_repeat_sa(t_node **stack, t_flag *flag, t_counter *c, int n);
void		ft_repeat_sb(t_node **stack, t_flag *flag, t_counter *c, int n);
void		ft_repeat_ss(t_stacks *stacks, t_flag *flag, t_counter *c, int n);
/* ----              ---- */

/* -- DEBUG PART -- */
void		ft_print_stack_value(t_node *stack);
void		ft_print_stacks(t_stacks *stacks, int write_title);
void		ft_print_stack(t_node *stack);
void		ft_print_flag(t_flag *flag);
void		ft_print_setup(t_stacks *stacks, t_flag *flag);
void		ft_print_title(void);
void		ft_print_op(t_op *op_c);
/* ----              ---- */
#endif
