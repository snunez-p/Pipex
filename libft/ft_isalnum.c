/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-p <snunez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:39:43 by snunez-p          #+#    #+#             */
/*   Updated: 2024/10/17 17:41:10 by snunez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int	ft_isalnum(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

/*#include <stdio.h>   // Para printf

int	main(void)
{
	// Prueba con un dígito
	char c1 = '5';
	if (ft_isalnum(c1))
		printf("El carácter '%c' es alfanumérico.\n", c1);
	else
		printf("El carácter '%c' NO es alfanumérico.\n", c1);
}*/