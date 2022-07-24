/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 15:16:17 by guifgomes         #+#    #+#             */
/*   Updated: 2022/07/22 23:03:13 by guilhfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define DIGITS "0123456789"
# define HEXALOW "0123456789abcdef"
# define HEXAUPP "0123456789ABCDEF"

typedef struct s_into
{
	char	type;
	int		width;
	int		zero;
}			t_info;

/*
**MAIN FUNCTIONS:
*/
int			ft_printf(const char *string, ...);
int			print_char(char c, t_info *info);
int			print_digits(int d, t_info *info);
int			print_string(char *str);
int			print_hexa(int d, t_info *info);
int			print_pointer(unsigned long int d);
/*
**UTIL-FUNCTIONS:
**file: ft_utils_1.c
*/
void		init_info(t_info *info);
int			ft_putchar(int c);
void		ft_putstr_fd(char *s, int fd);
int			ft_digits(int n, int b_len);
char		*ft_itoa(int n);

/*
**file: ft_utils_2.c
*/
size_t		ft_strlen(const char *str);
void		*ft_calloc(size_t nitems, size_t size);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		ft_bzero(void *str, size_t nbyte);
char		*ft_uitoa_base(unsigned int n, char *base);
char		*ft_ulitoa_base(unsigned long int n, char *base);
#endif