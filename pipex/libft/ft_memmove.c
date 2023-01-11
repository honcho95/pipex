/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaskhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:12:13 by tbaskhan          #+#    #+#             */
/*   Updated: 2021/12/17 19:14:06 by tbaskhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*destt;
	unsigned char	*srcc;

	destt = ((unsigned char *)dest);
	srcc = ((unsigned char *)src);
	i = 0;
	if (dest > src)
	{
		while (i < n)
		{
			destt[n - 1 - i] = srcc[n - 1 - i];
			i++;
		}
	}
	else
	{
		while (i < n)
		{
			destt[i] = srcc[i];
			i++;
		}
	}
	return (dest);
}
