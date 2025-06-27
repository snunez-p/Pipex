/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaltea <amaltea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:46:55 by snunez-p          #+#    #+#             */
/*   Updated: 2025/05/24 17:39:29 by amaltea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d;
	size_t	s;
	size_t	destl;
	size_t	strl;

	d = 0;
	s = 0;
	while (dst[d] != '\0' && d < size)
	{
		d++;
	}
	destl = d;
	strl = ft_strlen(src);
	if (size <= destl)
	{
		return (size + strl);
	}
	s = 0;
	while (src[s] != '\0' && (destl + s) < (size - 1))
	{
		dst[destl + s] = src[s];
		s++;
	}
	dst[destl + s] = '\0';
	return (destl + strl);
}
