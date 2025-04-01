# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/26 11:37:43 by dcaetano          #+#    #+#              #
#    Updated: 2025/03/29 13:45:21 by dcaetano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# === BINARY ================================================================= #

NAME              = solve_py

# === COMMANDS =============================================================== #

FIND              = find
PYINSTALLER       = pyinstaller
RM                = rm

# === EXTENSIONS ============================================================= #

PY_EXT            = .py

# === FILES ================================================================== #

SOLVE_PY          = solve$(PY_EXT)

# === FLAGS ================================================================== #

PYINSTALLER_FLAGS = --onefile --distpath . --name $(NAME)
RM_FLAGS          = -rfv
FIND_FLAGS        = -type f -name "*.spec" -exec $(RM) $(RM_FLAGS) {} \;

# === RULES ================================================================== #

all: $(NAME)

$(NAME):
	@$(PYINSTALLER) $(PYINSTALLER_FLAGS) $(SOLVE_PY) > /dev/null 2>&1

clean:
	@$(RM) $(RM_FLAGS) build
	@$(FIND) * $(FIND_FLAGS) || true

fclean: clean
	@$(RM) $(RM_FLAGS) $(NAME)

re: fclean all

.PHONY: all clean fclean re
