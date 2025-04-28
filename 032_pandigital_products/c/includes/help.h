/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 09:41:55 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/28 12:21:26 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELP_H
# define HELP_H

# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>

typedef struct s_help
{
	char			*ds;
	long long int	l;
	char			r[BUFSIZ];
	bool			*u;
}					t_help;

#endif
