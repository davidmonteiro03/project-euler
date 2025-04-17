/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:20:12 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/17 08:59:09 by dcaetano         ###   ########.fr       */
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
	std::vector<std::vector<long long int>> __spiral;
	std::size_t __m;
	std::size_t __n;

	void __fillSpiral(void);

	static void __solve(const std::vector<std::vector<long long int>> &,
						const std::size_t &,
						const std::size_t &);
};
