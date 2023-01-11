/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaskhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:16:01 by tbaskhan          #+#    #+#             */
/*   Updated: 2021/12/17 19:20:19 by tbaskhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len(const char *s, unsigned int start, size_t len)
{
	size_t	size;
	size_t	i;

	size = 0;
	i = 0;
	while (s[i])
	{
		if (i >= start && size < len)
			size++;
		i++;
	}
	return (size);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	size;
	size_t	i;
	size_t	j;

	size = ft_len(s, start, len);
	str = (char *)malloc(sizeof(*s) * (size + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}
