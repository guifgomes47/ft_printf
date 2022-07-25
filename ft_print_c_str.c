/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 16:21:44 by guilhfer          #+#    #+#             */
/*   Updated: 2022/07/25 12:19:37 by guilhfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c, t_info *info)
{
	int	len;

	len = 0;
	if (info->type == '%')
	{
		len += ft_putchar('%');
		return (len);
	}
	len += ft_putchar(c);
	return (len);
}

int	print_string(char *str)
{
	int	len;

	len = 0;
	if (!str)
		str = "(null)";
	while (str[len])
	{
		write(1, &str[len++], 1);
	}
	return (len);
}
