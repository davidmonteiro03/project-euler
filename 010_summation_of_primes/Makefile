# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/26 10:39:56 by dcaetano          #+#    #+#              #
#    Updated: 2025/03/26 11:57:57 by dcaetano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CDIR    = c
CNAME   = $(CDIR)/solve_$(CDIR)

CPPDIR  = cpp
CPPNAME = $(CPPDIR)/solve_$(CPPDIR)

PYDIR   = py
PYNAME = $(PYDIR)/solve_$(PYDIR)

all: $(CNAME) $(CPPNAME) $(PYNAME)

$(CNAME):
	@$(MAKE) -sC $(CDIR) > /dev/null 2>&1

$(CPPNAME):
	@$(MAKE) -sC $(CPPDIR) > /dev/null 2>&1

$(PYNAME):
	@$(MAKE) -sC $(PYDIR) > /dev/null 2>&1

clean:
	@$(MAKE) -sC $(CDIR) clean
	@$(MAKE) -sC $(CPPDIR) clean
	@$(MAKE) -sC $(PYDIR) clean

fclean: clean
	@$(MAKE) -sC $(CDIR) fclean
	@$(MAKE) -sC $(CPPDIR) fclean
	@$(MAKE) -sC $(PYDIR) fclean

re: fclean all

.PHONY: all clean fclean re
