# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkraft <kkraft@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/17 17:54:17 by kkraft            #+#    #+#              #
#    Updated: 2025/11/17 17:54:17 by kkraft           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= 			push_swap
LIBFT=			libft.a
BONUS=			checker
CFLAGS= 		-Iincludes -Ilibft
CC= 			cc
RM= 			rm -rf

SRC_MAIN=		srcs/main.c

SRCS_TOOLS=		srcs/tools/ft_clean_split.c \
				srcs/tools/ft_swap_int.c \
				srcs/tools/ft_sort_tab.c \
				srcs/tools/ft_return_str.c \
				srcs/tools/ft_node_by_index.c \
				srcs/tools/ft_repeat_reverse_rotate.c \
				srcs/tools/ft_repeat_rotate.c \
				srcs/tools/ft_repeat_swap.c \
				srcs/tools/ft_sqrt.c \
				srcs/tools/ft_node_place.c \
				srcs/tools/ft_reset_op.c \
				srcs/tools/ft_put_max_top.c \
				srcs/tools/ft_remaining.c \
				srcs/tools/ft_in_chunk.c \
				srcs/tools/ft_stack.c \
				srcs/tools/ft_index.c \
				srcs/tools/ft_move.c \
				srcs/tools/ft_cost.c \
				srcs/tools/ft_str.c \

SRCS_PARSING=	srcs/parsing/ft_check_inputs.c \
				srcs/parsing/ft_check_utils.c \
				srcs/parsing/ft_parsing_inputs.c \
				srcs/parsing/ft_parsing_utils.c

SRCS_STRUCT=	srcs/struct/ft_struct.c

SRCS_RULES=		srcs/rules/ft_push.c \
				srcs/rules/ft_reverse_rotate.c \
				srcs/rules/ft_rotate.c \
				srcs/rules/ft_swap.c

SRC_SELECTOR=	srcs/selector/ft_selector.c

SRCS_ALGO=		srcs/simple/ft_selection_sort.c \
				srcs/medium/ft_chunk_sort.c \
				srcs/complex/ft_smart_sort.c \
				srcs/complex/ft_pre_sort.c \
				srcs/complex/ft_complex_sub.c \
				srcs/complex/ft_last_sort.c \
				srcs/complex/ft_chunk_sort_cost.c

SRCS_BENCH=		srcs/bench/ft_benchmark.c \
				srcs/bench/ft_benchmark_sub.c

SRCS_DEBUG=		srcs/debug/ft_debug.c \
				srcs/debug/ft_debug_tools.c \
				srcs/debug/ft_print_op.c

SRCS_BONUS=		srcs/bonus/ft_checker_sub.c \
				srcs/bonus/ft_checker.c

OBJS=			$(SRC_MAIN:.c=.o) $(SRCS_TOOLS:.c=.o) $(SRCS_PARSING:.c=.o) $(SRCS_STRUCT:.c=.o) $(SRCS_RULES:.c=.o) $(SRC_SELECTOR:.c=.o) $(SRCS_ALGO:.c=.o)  $(SRCS_BENCH:.c=.o) $(SRCS_DEBUG:.c=.o)

OBJSBONUS=		$(SRCS_BONUS:.c=.o) $(SRCS_TOOLS:.c=.o) $(SRCS_PARSING:.c=.o) $(SRCS_STRUCT:.c=.o) $(SRCS_RULES:.c=.o) $(SRC_SELECTOR:.c=.o) $(SRCS_ALGO:.c=.o)  $(SRCS_BENCH:.c=.o) $(SRCS_DEBUG:.c=.o)

OBJSALL=		$(SRC_MAIN:.c=.o) $(SRCS_BONUS:.c=.o) $(SRCS_TOOLS:.c=.o) $(SRCS_PARSING:.c=.o) $(SRCS_STRUCT:.c=.o) $(SRCS_RULES:.c=.o) $(SRC_SELECTOR:.c=.o) $(SRCS_ALGO:.c=.o)  $(SRCS_BENCH:.c=.o) $(SRCS_DEBUG:.c=.o)

all:			$(LIBFT) $(NAME)

$(LIBFT):
				$(MAKE) -C libft/

$(NAME):		$(OBJS)
				$(CC) $(OBJS) -L./libft -lft -o $(NAME)
%.o:%.c
				$(CC) $(CFLAGS) -c $< -o $@

bonus :			$(LIBFT) $(BONUS)

$(BONUS):		$(OBJSBONUS)
				$(CC) $(OBJSBONUS) -L./libft -lft -o $(BONUS)

clean :
				$(MAKE) clean -C libft/
				$(RM) $(OBJSALL)

fclean : 		clean
				$(MAKE) fclean -C libft/
				$(RM) $(NAME) $(BONUS)

re: 			fclean all

.PHONY: 		all clean fclean re
