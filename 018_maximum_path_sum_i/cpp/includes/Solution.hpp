/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:20:12 by dcaetano          #+#    #+#             */
/*   Updated: 2025/03/31 12:06:02 by dcaetano         ###   ########.fr       */
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
	std::size_t __nLines;
	std::vector<std::vector<long long int>> __triangle;

	void __triangleAlloc(void);
	void __triangleFill(const std::string &);
	long long int __solveRecursive(const std::size_t &,
								   const std::size_t &,
								   const std::size_t &,
								   const std::size_t &) const;
};
