/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 15:04:11 by guifgomes         #+#    #+#             */
/*   Updated: 2022/07/22 17:14:21 by guilhfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	print_type(va_list args, t_info *info)
{
	int		len;
	char	type;

	len = 0;
	type = info->type;
	if (type == 'c' || type == '%')
		len = print_char(va_arg(args, int), info);
	if (type == 'd' || type == 'i' || type == 'u')
		len = print_digits(va_arg(args, int), info);
	if (type == 's')
		len = print_string(va_arg(args, char *));
	if (type == 'x' || type == 'X')
		len = print_hexa(va_arg(args, unsigned int), info);
	if (type == 'p')
		len = print_pointer(va_arg(args, unsigned long int));
	return (len);
}

int	ft_vfprintf(va_list args, const char *format)
{
	int		len;
	int		i;
	t_info	*info;

	i = 0;
	len = 0;
	info = malloc(sizeof(t_info) * 1);
	if (!(info))
		return (-1);
	while (format[i])
	{
		if (format[i] != '%' && format[i])
			len += ft_putchar(format[i++]);
		if (format[i] == '%')
		{
			i++;
			info->type = format[i++];
			len += print_type(args, info);
		}
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	va_start(args, format);
	len = ft_vfprintf(args, format);
	va_end(args);
	return (len);
}