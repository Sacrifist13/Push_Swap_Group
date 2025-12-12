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
CFLAGS= 		-Ilibft
CC= 			cc
RM= 			rm -rf

SRC_MAIN=		main.c

SRCS_TOOLS=		ft_clean_split.c \
				ft_swap_int.c \
				ft_sort_tab.c \
				ft_return_str.c \
				ft_node_by_index.c \
				ft_repeat_reverse_rotate.c \
				ft_repeat_rotate.c \
				ft_repeat_swap.c \
				ft_sqrt.c \
				ft_node_place.c \
				ft_reset_op.c \
				ft_put_max_top.c \
				ft_remaining.c \
				ft_in_chunk.c \
				ft_stack.c \
				ft_index.c \
				ft_move.c \
				ft_cost.c \
				ft_str.c \

SRCS_PARSING=	ft_check_inputs.c \
				ft_check_utils.c \
				ft_parsing_inputs.c \
				ft_parsing_utils.c

SRCS_STRUCT=	ft_struct.c

SRCS_RULES=		ft_push.c \
				ft_reverse_rotate.c \
				ft_rotate.c \
				ft_swap.c

SRC_SELECTOR=	ft_selector.c

SRCS_ALGO=		ft_selection_sort.c \
				ft_chunk_sort.c \
				ft_smart_sort.c \
				ft_pre_sort.c \
				ft_complex_sub.c \
				ft_last_sort.c \
				ft_chunk_sort_cost.c

SRCS_BENCH=		ft_benchmark.c \
				ft_benchmark_sub.c

SRCS_BONUS=		ft_checker_sub_bonus.c \
				ft_checker_bonus.c

OBJS=			$(SRC_MAIN:.c=.o) $(SRCS_TOOLS:.c=.o) $(SRCS_PARSING:.c=.o) $(SRCS_STRUCT:.c=.o) $(SRCS_RULES:.c=.o) $(SRC_SELECTOR:.c=.o) $(SRCS_ALGO:.c=.o)  $(SRCS_BENCH:.c=.o)

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
