# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkraft <kkraft@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/03 09:39:25 by kkraft            #+#    #+#              #
#    Updated: 2025/11/21 11:43:17 by kkraft           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
INCDIR = include
LINK= ar rc
RM= rm -rf
SRCS =	libft/ft_isalpha.c \
		libft/ft_isdigit.c \
		libft/ft_isalnum.c \
		libft/ft_isascii.c \
		libft/ft_isprint.c \
		libft/ft_strlen.c \
		libft/ft_memset.c \
		libft/ft_bzero.c \
		libft/ft_memcpy.c \
		libft/ft_memmove.c \
		libft/ft_strlcpy.c \
		libft/ft_strlcat.c \
		libft/ft_toupper.c \
		libft/ft_tolower.c \
		libft/ft_strchr.c \
		libft/ft_strrchr.c \
		libft/ft_strncmp.c \
		libft/ft_memchr.c \
		libft/ft_memcmp.c \
		libft/ft_strnstr.c \
		libft/ft_atoi.c \
		libft/ft_calloc.c \
		libft/ft_strdup.c \
		libft/ft_substr.c \
		libft/ft_strjoin.c \
		libft/ft_split.c \
		libft/ft_strtrim.c \
		libft/ft_itoa.c \
		libft/ft_strmapi.c \
		libft/ft_striteri.c \
		libft/ft_putchar_fd.c \
		libft/ft_putstr_fd.c \
		libft/ft_putendl_fd.c \
		libft/ft_putnbr_fd.c \
		libft/ft_lstnew.c \
		libft/ft_lstadd_front.c \
		libft/ft_lstsize.c \
		libft/ft_lstlast.c \
		libft/ft_lstadd_back.c \
		libft/ft_lstdelone.c \
		libft/ft_lstclear.c \
		libft/ft_lstiter.c \
		libft/ft_lstmap.c \
		printf/ft_printf_bonus.c \
		printf/ft_tools.c \
		printf/ft_transform_char.c \
		printf/ft_transform_hex.c \
		printf/ft_transform_int.c \
		printf/ft_transform_percent.c \
		printf/ft_transform_ptr.c \
		printf/ft_transform_str.c \
		printf/ft_transform_unsigned.c \
		printf/ft_transform.c \
		printf/ft_handle_char_bonus.c \
		printf/ft_handle_hex_bonus.c \
		printf/ft_handle_int_bonus.c \
		printf/ft_handle_percent_bonus.c \
		printf/ft_handle_ptr_bonus.c \
		printf/ft_handle_str_bonus.c \
		printf/ft_handle_uint_bonus.c \
		printf/ft_clean_struct_bonus.c \
		printf/ft_fill_struct_bonus.c \
		printf/ft_new_struct_bonus.c \
		printf/ft_reset_struct_bonus.c \
		printf/ft_verif_struct_bonus.c \
		printf/ft_transform_bonus.c \
		printf/ft_transform_char_bonus.c \
		printf/ft_transform_hex_bonus.c \
		printf/ft_transform_int_bonus.c \
		printf/ft_transform_percent_bonus.c \
		printf/ft_transform_ptr_bonus.c \
		printf/ft_transform_str_bonus.c \
		printf/ft_transform_uint_bonus.c \
		printf/ft_tools_bonus.c

OBJS= $(SRCS:.c=.o)

all: $(NAME)

$(NAME):	$(OBJS)
			$(LINK) -o $(NAME) $(OBJS)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
