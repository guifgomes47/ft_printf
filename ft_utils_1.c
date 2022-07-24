/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 18:03:48 by guilhfer          #+#    #+#             */
/*   Updated: 2022/07/22 23:45:20 by guilhfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_info(t_info *info)
{
	info->type = 0;
	info->width = 0;
	info->zero = 0;
}

int	ft_putchar(int c)
{
	int	len;

	len = 0;
	len += write(1, &c, 1);
	return (len);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s || !fd)
		return ;
	write(fd, s, ft_strlen(s));
}

int	ft_digits(int n, int b_len)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	if (n < 0)
		i++;
	while (n)
	{
		n /= b_len;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*dest;
	int		sign;
	int		len;

	len = ft_digits(n, 10);
	dest = (char *)malloc(len + 1);

	if (!dest)
		return (NULL);
	if (n == -2147483648)
		return (ft_memcpy(dest, "-2147483648", 11));
	sign = 1;
	if (n < 0)
		sign = -1;
	n *= sign;
	while (--len >= 0)
	{
		dest[len] = n % 10 + '0';
		n /= 10;
	}
	if (sign == -1)
		dest[0] = '-';
	return (dest);
}
