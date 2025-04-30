/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_cpp.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:23:06 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/30 12:57:14 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <sstream>
#include <boost/multiprecision/cpp_int.hpp>

extern "C"
{
#include <sysexits.h>
}

class Solution;

#include "Solution.hpp"

extern int gExitStatus;
