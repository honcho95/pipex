/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaskhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 22:51:07 by tbaskhan          #+#    #+#             */
/*   Updated: 2021/12/17 16:16:27 by tbaskhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (little[i])
		i++;
	if (i == 0)
		return ((char *)big);
	i = 0;
	while (big[i])
	{
		if (big[i] == little[0])
		{
			j = 0;
			while (little[j] && little[j] == big[i + j] && i + j < len)
				j++;
			if (little[j] == 0)
				return ((char *)big + i);
		}
		if (++i == len)
			return (0);
	}	
	return (0);
}
