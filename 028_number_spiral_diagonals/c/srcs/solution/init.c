/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 09:50:57 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/17 07:25:08 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solve_c.h"

void	solution_init(t_solution *solution, int argc, char **argv)
{
	if (solution == NULL)
		return ;
	bzero(solution, sizeof(*solution));
	solution->argc = argc;
	solution->argv = argv;
}
