/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 15:16:17 by guifgomes         #+#    #+#             */
/*   Updated: 2022/07/25 13:10:31 by guilhfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define DIGITS "0123456789"
# define HEXALOW "0123456789abcdef"
# define HEXAUPP "0123456789ABCDEF"

typedef struct s_into
{
	char	type;
}			t_info;

//|MAIN FUNCTIONS:
//|file: ft_printf.c
int			ft_printf(const char *string, ...);
int			ft_vfprintf(va_list args, const char *format);
int			print_type(va_list args, t_info *info);
//|file: ft_printf_c_str.c
int			print_char(char c);
int			print_string(char *str);
//|file: ft_printf_digits.c
int			print_digits(int d);
int			print_uns_num(unsigned int d);
int			print_hexa(unsigned int d, t_info *info);
int			print_pointer(unsigned long int d);
//|UTILS-FUNCTIONS:
//|file: ft_utils_1.c
void		init_info(t_info *info);
size_t		ft_strlen(const char *str);
int			ft_putchar(int c);
void		ft_putstr_fd(char *s, int fd);
//|file: ft_utils_2.c
int			num_size(int n);
char		*ft_itoa(int n);
int			uns_base_len(unsigned long int n, int base_len);
char		*ft_ulitoa_base(unsigned long int n, char *base);
#endif