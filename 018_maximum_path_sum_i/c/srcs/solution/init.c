/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 09:50:57 by dcaetano          #+#    #+#             */
/*   Updated: 2025/03/31 10:45:39 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solve_c.h"

void	solution_init(t_solution *solution, int argc, char **argv)
{
	if (solution == NULL)
		return ;
	solution->argc = argc;
	solution->argv = argv;
	solution->triangle = NULL;
}
