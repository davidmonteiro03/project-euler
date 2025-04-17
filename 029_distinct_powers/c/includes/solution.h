/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 09:41:55 by dcaetano          #+#    #+#             */
/*   Updated: 2025/03/27 14:23:19 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLUTION_H
# define SOLUTION_H

typedef struct s_solution
{
	int		argc;
	char	**argv;
}			t_solution;

void		solution_init(t_solution *solution, int argc, char **argv);
void		solution_execute(t_solution *solution);

#endif
