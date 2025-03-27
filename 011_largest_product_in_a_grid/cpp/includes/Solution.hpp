/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:20:12 by dcaetano          #+#    #+#             */
/*   Updated: 2025/03/27 22:13:54 by dcaetano         ###   ########.fr       */
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

	void fill(void);
	void execute(void) const;

private:
	int __argc;
	char **__argv;
	int __grid[20][20];
	size_t __m, __n;

	void __fillGrid(const std::string &);
	long long int __computeMaxHorizProd(const size_t &) const;
	long long int __computeMaxVertProd(const size_t &) const;
	long long int __computeMaxDiagProd(const size_t &) const;
	long long int __computeMaxRDiagProd(const size_t &) const;
};
