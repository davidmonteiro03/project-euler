/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:20:12 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/01 14:54:11 by dcaetano         ###   ########.fr       */
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
	std::vector<std::string> __names;

	void __fillNames(const std::string &);
	static long long int __getLetterCode(const char &);
	static long long int __getNameScore(const std::string &,
										const long long int &);

	static void __solve(const std::vector<std::string> &,
						const std::string &);
};
