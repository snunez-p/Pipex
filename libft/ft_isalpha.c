/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-p <snunez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:39:56 by snunez-p          #+#    #+#             */
/*   Updated: 2024/10/17 17:52:31 by snunez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
	{
		return (1);
	}
	return (0);
}
//#include <stdio.h>

/*int main(void)
{
	char c1 = 'A';
	if (ft_isalpha(c1))
		printf("El carácter '%c' es una letra.\n", c1);
	else
		printf("El carácter '%c' NO es una letra.\n", c1);
}*/