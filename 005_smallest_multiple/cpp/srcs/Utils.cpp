/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 07:43:39 by dcaetano          #+#    #+#             */
/*   Updated: 2025/03/27 07:47:06 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solve_cpp.hpp"

Utils::Utils(void) {}

Utils::Utils(const Utils &) {}

Utils &Utils::operator=(const Utils &) { return *this; }

Utils::~Utils() {}

long long int Utils::abs(const long long int &a) { return a >= 0 ? a : -a; }

long long int Utils::gcd(const long long int &a, const long long int &b)
{
	long long int result = std::min(a, b);
	while (result > 0)
	{
		if (a % result == 0 && b % result == 0)
			break ;
		result--;
	}
	return result;
}

long long int Utils::lcm(const long long int &a, const long long int &b) { return Utils::abs(a * b) / Utils::gcd(a, b); }
