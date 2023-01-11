/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaskhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 10:34:21 by tbaskhan          #+#    #+#             */
/*   Updated: 2021/12/17 19:11:33 by tbaskhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*ss;

	i = 0;
	j = 0;
	ss = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ss)
		return (NULL);
	while (s1[i])
	{
		ss[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		ss[i] = s2[j];
		i++;
		j++;
	}
	ss[i] = '\0';
	return (ss);
}
