/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:20:12 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/01 17:03:21 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Solution
{
public:
	Solution(int, char **);
	Solution(const Solution &);
	Solution &operator=(const Solution &);
	~Solution();

	void execute(void) const;

private:
	int __argc;
	char **__argv;

	static long long int __sumDivisors(const long long int &);
	static bool __isAbundant(const long long int &);
	static bool __isSumOfAbundants(const long long int &);

	static void __solve(const long long int &);
};
