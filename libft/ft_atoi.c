/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-p <snunez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:38:11 by snunez-p          #+#    #+#             */
/*   Updated: 2024/10/17 17:38:51 by snunez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*calculate_sign(const char *str, long *sign)
{
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			(*sign) *= -1;
		str++;
	}
	return (str);
}

int	ft_atoi(const char *nptr)
{
	long	result;
	long	sign;

	sign = 1;
	nptr = calculate_sign(nptr, &sign);
	result = 0;
	while (*nptr && (*nptr >= '0') && (*nptr <= '9'))
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	result = sign * result;
	return ((int)result);
}
// int main()
//  {
//      char str[] = "42";
//      int val = ft_atoi(str);
//      printf ("%d ", val);
//      return 0;
//  }