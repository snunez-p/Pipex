/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-p <snunez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:42:35 by snunez-p          #+#    #+#             */
/*   Updated: 2024/10/22 20:10:37 by snunez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*src_c;
	unsigned char		*dest_c;
	size_t				i;

	dest_c = (unsigned char *)dest;
	src_c = (const unsigned char *)src;
	if (dest_c < src_c)
	{
		i = -1;
		while (++i < n)
			dest_c[i] = src_c[i];
	}
	if (dest_c > src_c)
	{
		i = n;
		while (i-- > 0)
		{
			dest_c[i] = src_c[i];
		}
	}
	return (dest);
}
