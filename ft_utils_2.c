/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:15:03 by guilhfer          #+#    #+#             */
/*   Updated: 2022/07/25 12:21:23 by guilhfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa(int n)
{
	char	*dest;
	long	nbr;
	size_t	len;

	nbr = n;
	len = n > 0 ? 0 : 1;
	nbr = nbr > 0 ? nbr : -nbr;
	while (n)
	{
		n /= 10;
		len++;
	}
	if (!(dest = (char *)malloc(len + 1)))
		return (0);
	dest[len--] = '\0';
	while (nbr > 0)
	{
		dest[len--] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (len == 0 && dest[1] == '\0')
		dest[0] = '0';
	else if (len == 0 && dest[1] != '\0')
		dest[0] = '-';
	return (dest);
}

char	*ft_ulitoa_base(unsigned long int n, char *base)
{
	char				*dest;
	int					b_len;
	int					len;
	unsigned long int	nbr;

	b_len = ft_strlen(base);
	nbr = n;
	len = 1;
	while (nbr /= b_len)
		len++;
	if (!(dest = (char *)malloc(len + 1)))
		return (NULL);
	dest[len--] = '\0';
	while (n > 0)
	{
		dest[len--] = base[n % b_len];
		n /= b_len;
	}
	if (len == 0 && dest[1] == '\0')
		dest[0] = '0';
	return (dest);
}
