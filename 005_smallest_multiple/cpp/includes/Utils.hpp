/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:31:48 by dcaetano          #+#    #+#             */
/*   Updated: 2025/03/27 15:32:11 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Utils
{
public:
	static long long int abs(const long long int &);
	static long long int gcd(const long long int &,
							 const long long int &);
	static long long int lcm(const long long int &,
							 const long long int &);

private:
	Utils(void);
	Utils(const Utils &);
	Utils &operator=(const Utils &);
	~Utils();
};
