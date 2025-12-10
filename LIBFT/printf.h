/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraft <kkraft@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 07:04:11 by kkraft            #+#    #+#             */
/*   Updated: 2025/11/18 11:22:17 by kkraft           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_flags
{
	int		width;
	int		dot;
	int		precision;
	int		minus;
	int		plus;
	int		space;
	int		zero;
	int		hash;
	char	type;
}	t_flags;

/* -- MANDATORY PART -- */
/* -- srcs/mandatory/ft_printf.c -- */
int		ft_printf(const char *s, ...);

/* -- ../srcs/mandatory/transform/ft_transform_carac.c -- */
int		ft_transform_char(char c);

/* -- ../srcs/mandatory/transform/ft_transform_else.c -- */
char	*ft_transform_else(char carac);

/* -- ../srcs/mandatory/transform/ft_transform_hex.c -- */
char	*ft_return_unsigned_nb_str(char *unsigned_nb_str);
int		ft_size_hex_str(int nb);
char	*ft_transform_hex_sub(int nb, char *base);
int		ft_transform_hex(char specifier, int nb, char *base);

/* -- ../srcs/mandatory/transform/ft_transform_nb.c -- */
char	*ft_transform_nb_sub(int nb);
int		ft_transform_nb(int nb);

/* -- ../srcs/mandatory/transform/ft_transform_percent.c -- */
int		ft_transform_percent(void);

/* -- ../srcs/mandatory/transform/ft_transform_ptr.c -- */
int		ft_size_word_ptr_nb(long int ptr);
char	*ft_transform_ptr_sub(void *ptr, char *base);
int		ft_transform_ptr(void *ptr, char *base);

/* -- ../srcs/mandatory/transform/ft_transforn_str.c -- */
int		ft_transform_str(char *s);

/* -- ../srcs/mandatory/transform/ft_transform_unsigned.c -- */
int		ft_size_unsigned_str(unsigned int nbr);
char	*ft_transform_uint_sub(int nb);
int		ft_transform_unsigned(int nb);

/* -- ../srcs/mandatory/transform/ft_transform.c -- */
void	ft_transform_specifier(char specifier, va_list *args, int *size);

/* -- ../srcs/mandatory/tools/ft_tools.c -- */
void	ft_putchar_fd_printf(char c, int fd, int *size);
int		ft_is_specifier(char specifier);
void	ft_toupper_str(char *s);
int		ft_str_only_zero(char *s);
int		ft_str_is_negative(char *s);

/* -- BONUS PART -- */
/* -- ../srcs/bonus/ft_printf_bonus.c -- */
int		ft_printf(const char *s, ...);
void	ft_printf_sub(char *s, t_flags *flag, int *size, va_list *args);

/* -- ../srcs/bonus/handle_bonus/ft_handle_char_bonus.c -- */
int		ft_handle_char_width(char c, t_flags *flag);

/* -- ../srcs/bonus/handle_bonus/ft_handle_hex_bonus.c -- */
int		ft_handle_hex_basic(char type, char *s, int basic_size);
int		ft_handle_hex_hash(t_flags *flag, char type, char *s, int basic_size);
char	*ft_handle_hex_hash_width(t_flags *flag, char *s);
int		ft_handle_hex_nohash(t_flags *flag, char type, char *s, int basic_size);

/* -- ../srcs/bonus/handle_bonus/ft_handle_int_bonus.c -- */
int		ft_handle_dot_nb_pos(t_flags *flag, int nb);
int		ft_handle_dot_nb_neg(t_flags *flag, int nb);
int		ft_handle_dot_nb(t_flags *flag, int nb);
int		ft_handle_sign_nb(t_flags *flag, int nb);
int		ft_handle_width_nb(t_flags *flag, int nb);

/* -- ../srcs/bonus/handle_bonus/ft_handle_percent_bonus.c -- */
int		ft_handle_width_percent(t_flags *flag);

/* -- ../srcs/bonus/handle_bonus/ft_handle_ptr_bonus.c -- */
int		ft_handle_width_ptr(t_flags *flag, void *ptr, char *base);

/* -- ../srcs/bonus/handle_bonus/ft_handle_str_bonus.c -- */
char	*ft_transform_str_basic(char *s);
int		ft_handle_dot_str(t_flags *flag, char *s);
int		ft_handle_width_str(t_flags *flag, char *s);

/* -- ../srcs/bonus/handle_bonus/ft_handle_uint_bonus.c -- */
int		ft_handle_dot_uint(t_flags *flag, int nb);
int		ft_handle_width_uint(t_flags *flag, int nb);

/* -- ../srcs/bonus/struct_bonus/ft_clean_struct_bonus.c -- */
void	ft_clean_flags_struct(t_flags *flag);

/* -- ../srcs/bonus/struct_bonus/ft_fill_struct_bonus.c -- */
int		ft_fiil_flags_struct(t_flags *flag, char *flags_str);
void	ft_parse_flags(t_flags *flag, char *flags_str, int *i);
void	ft_parse_width(t_flags *flag, char *flags_str, int *i);
void	ft_parse_precision(t_flags *flag, char *flags_str, int *i);
void	ft_parse_type(t_flags *flag, char *flags_str, int *i);

/* -- ../srcs/bonus/struct_bonus/ft_new_struct_bonus.c -- */
t_flags	*ft_new_flags_struct(void);

/* -- ../srcs/bonus/struct_bonus/ft_reset_struct_bonus.c -- */
void	ft_reset_flags_struct(t_flags *flag);

/* -- ../srcs/bonus/struct_bonus/ft_verif_struct_bonus.c -- */
int		ft_is_verif_flags_struct(t_flags *flag);

/* -- ../srcs/bonus/tools_bonus/ft_tools_bonus.c -- */
char	*ft_fill_before(char *s, int start, int total_len, char c);
char	*ft_fill_after(char *s, int total_len, char c);
char	*ft_add_hash_flag(char *s);
char	*ft_add_sign(t_flags *flag, char *s);

/* -- ../srcs/bonus/transform_bonus/ft_transform_bonus.c -- */
int		ft_conv_flags_struct(t_flags *flag, char *s, va_list *args, int *size);

/* -- ../srcs/bonus/transform_bonus/ft_transform_char_bonus.c -- */
void	ft_handle_char(t_flags *flag, va_list *args, int *size);

/* -- ../srcs/bonus/transform_bonus/ft_transform_hex_bonus.c -- */
void	ft_handle_hex(t_flags *flag, va_list *args, int *size);

/* -- ../srcs/bonus/transform_bonus/ft_transform_int_bonus.c -- */
void	ft_handle_int(t_flags *flag, va_list *args, int *size);

/* -- ../srcs/bonus/transform_bonus/ft_transform_percent_bonus.c -- */
void	ft_handle_percent(t_flags *flag, int *size);

/* -- ../srcs/bonus/transform_bonus/ft_transform_ptr_bonus.c -- */
void	ft_handle_ptr(t_flags *flag, va_list *args, int *size);

/* -- ../srcs/bonus/transform_bonus/ft_transform_str_bonus.c -- */
void	ft_handle_str(t_flags *flag, va_list *args, int *size);

/* -- ../srcs/bonus/transform_bonus/ft_transform_uint_bonus.c -- */
void	ft_handle_uint(t_flags *flag, va_list *args, int *size);

#endif
