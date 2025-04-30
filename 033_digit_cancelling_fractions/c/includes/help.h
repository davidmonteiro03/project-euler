/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 08:25:32 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/30 09:16:29 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELP_H
# define HELP_H

# include <gmp.h>

typedef struct s_help
{
	long long int	f[2];
	long long int	*ac;
}					t_help;

void				help_compute(mpq_t product, t_help *help_ptr);

#endif
