/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-p <snunez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:40:33 by snunez-p          #+#    #+#             */
/*   Updated: 2024/10/17 17:40:36 by snunez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}
/*#include <stdio.h>

int	main(void)
{
	char c1 = '5';
	if (ft_isdigit(c1))
		printf("El carácter '%c' es un dígito.\n", c1);
	else
		printf("El carácter '%c' NO es un dígito.\n", c1);

	char c2 = 'A';
	if (ft_isdigit(c2))
		printf("El carácter '%c' es un dígito.\n", c2);
	else
		printf("El carácter '%c' NO es un dígito.\n", c2);

	char c3 = '#';
	if (ft_isdigit(c3))
		printf("El carácter '%c' es un dígito.\n", c3);
	else
		printf("El carácter '%c' NO es un dígito.\n", c3);

	return (0);
}*/