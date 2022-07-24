/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:15:03 by guilhfer          #+#    #+#             */
/*   Updated: 2022/07/22 23:45:03 by guilhfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count])
	{
		count++;
	}
	return (count);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}

char	*ft_uitoa_base(unsigned int n, char *base)
{
	char	*dest;
	int		b_len;
	int		len;
	int		nbr;

	b_len = ft_strlen(base);
	nbr = n;
	len = 1;
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
