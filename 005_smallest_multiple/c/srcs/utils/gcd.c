/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gcd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:29:53 by dcaetano          #+#    #+#             */
/*   Updated: 2025/03/27 15:29:56 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solve_c.h"

long long int	utils_gcd(long long int a, long long int b)
{
	long long int	result;

	if (a < b)
		result = a;
	else
		result = b;
	while (result > 0)
	{
		if (a % result == 0 && b % result == 0)
			break ;
		result--;
	}
	return (result);
}
