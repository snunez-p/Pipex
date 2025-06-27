/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-p <snunez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:50:18 by snunez-p          #+#    #+#             */
/*   Updated: 2024/10/22 20:12:24 by snunez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!(*little))
		return ((char *)big);
	j = 0;
	while ((big[j]) && (j < len))
	{
		i = 0;
		while (little[i] && big[i + j] && (big[i + j] == little[i]) \
				&& (i + j < len))
		{
			i++;
		}
		if (!little[i])
			return ((char *)(&big[j]));
		j++;
	}
	return ((void *)0);
}
