/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 18:50:22 by guilhfer          #+#    #+#             */
/*   Updated: 2022/07/22 23:59:13 by guilhfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_digits(int d, t_info *info)
{
	int	i;

	if (info->type == 'd' || info->type == 'i')
		ft_putstr_fd(ft_itoa(d), 1);
	if (info->type == 'u')
		ft_putstr_fd(ft_uitoa_base(d, DIGITS), 1);
	i = 0;
	while (d)
	{
		d /= 10;
		i++;
	}
	return (i + 1);
}

int	print_hexa(int d, t_info *info)
{
	int	i;

	if (info->type == 'x')
		ft_putstr_fd(ft_uitoa_base(d, HEXALOW), 1);
	if (info->type == 'X')
		ft_putstr_fd(ft_uitoa_base(d, HEXAUPP), 1);
	i = 0;
	while (d)
	{
		d /= 16;
		i++;
	}
	return (i);
}

int	print_pointer(unsigned long int d)
{
	int		i;
	char	*pointer;

	pointer = ft_ulitoa_base(d, HEXALOW);
	i = 0;
	i += write(1, "0x", 2);
	i += ft_strlen(pointer);
	ft_putstr_fd(pointer, 1);
	return (i);
}

char	*ft_ulitoa_base(unsigned long int n, char *base)
{
	char				*dest;
	int					b_len;
	int					len;
	unsigned long int	nbr;

	b_len = ft_strlen(base);
	nbr = n;
	len = 0;
	while (nbr /= b_len)
		len++;
	dest = (char *)malloc(len + 1);
	if (!dest)
		return (NULL);
	while (--len >= 0)
	{
		dest[len] = base[n % b_len];
		n /= b_len;
	}
	return (dest);
}
