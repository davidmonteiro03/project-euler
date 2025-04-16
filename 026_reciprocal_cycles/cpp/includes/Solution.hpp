/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:20:12 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/16 11:23:35 by dcaetano         ###   ########.fr       */
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

	static std::string __decimalPeriod(const long long int &,
									   const long long int &);
	static std::size_t __reciprocalCycle(const long long int &,
										 const long long int &);

	static void __solve(const long long int &);
};
